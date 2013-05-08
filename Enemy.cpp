//Enemy.cpp
#include <Enemy.h>
#include <sstream>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Enemy::Enemy(Ogre::SceneManager* sceneMgr, Ogre::String name, int x, int z,int ind){
	mSceneMgr = sceneMgr;
    mHasBall = false;
    ball = NULL;
    mPower = 1;
    mThrowing = false;
    spawnPoint=Ogre::Vector3(x,-100,z);
    entEnemy = mSceneMgr->createEntity("ent" + name, "ninja.mesh");
    nodeEnemy = mSceneMgr->getRootSceneNode()->createChildSceneNode("node" + name, spawnPoint);
    camEnemy = mSceneMgr->createCamera(name + "Cam");
    nodeEnemy->attachObject(camEnemy);
    nodeEnemy->yaw(Ogre::Degree(180));

    entEnemy->setCastShadows(true);
    camEnemy->setPosition(0, nodeEnemy->getPosition().y + 180, nodeEnemy->getPosition().x -10);
    camEnemy->setNearClipDistance(5);
    nodeEnemy->attachObject(entEnemy);
    nodeEnemy->scale(.50,.50,.50);
    inPlay=true;

	body = Simulator::Simulation.addCylinder(20,100,x,-50,z,0, false,ind);
}

Ogre::Vector3 Enemy::getPosition(){
    return nodeEnemy->getPosition();
}

bool Enemy::hasBall(){
    return mHasBall;
}

void Enemy::pickupBall(Ball* baller){
    Ogre::Vector3 diff = Ogre::Vector3(nodeEnemy->getPosition().x - baller->getPosition().x ,0,nodeEnemy->getPosition().z - baller->getPosition().z);
    //if( (baller->getPosition().x-10 <= max.x  && baller->getPosition().x+10 >= min.x) && (baller->getPosition().z <= max.z  && baller->getPosition().z >= min.z) &&  baller->getPosition().y < 0){
    if(diff.length() < 15.0f &&  baller->getPosition().y < 0){
        ball = baller;
        ball->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y + 75, nodeEnemy->getPosition().z);
		ball->removeFromBullet();
        mHasBall = true;
    }
}

void Enemy::pickupBallPhysics(Ball* baller){
        ball = baller;
        ball->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y + 75, nodeEnemy->getPosition().z);
		ball->removeFromBullet();
        mHasBall = true;
}

void Enemy::beginThrow(){
    mThrowing = true;	
}

void Enemy::chargeThrow(){
    mPower+=0.02;
    if(mPower > 4)
        mPower = 4;
}

void Enemy::endThrow(Ogre::Vector3 playerloc){
    mHasBall = false;
    camEnemy->lookAt(playerloc.x, -20, playerloc.z);
    Ogre::Vector3 muldir=Ogre::Vector3(camEnemy->getDerivedDirection().x,0,camEnemy->getDerivedDirection().z);
    float mult = 20.0f/muldir.length();
    ball->setPosition(nodeEnemy->getPosition().x+(camEnemy->getDerivedDirection().x*mult), nodeEnemy->getPosition().y + 75, nodeEnemy->getPosition().z+(camEnemy->getDerivedDirection().z*mult));
    btVector3 dir=btVector3(camEnemy->getDerivedDirection().x,camEnemy->getDerivedDirection().y,camEnemy->getDerivedDirection().z);
    ball->addToBullet(dir, 3);
    ball->thrownBy(true);
    ball = NULL;
    mPower = 1;
    mThrowing = false;
}

void Enemy::extThrow(btVector3 dir, Ogre::Real pow){
    mHasBall = false;
    Ogre::Vector3 muldir=Ogre::Vector3(camEnemy->getDerivedDirection().x,0,camEnemy->getDerivedDirection().z);
    float mult = 20.0f/muldir.length();
    ball->setPosition(nodeEnemy->getPosition().x+(camEnemy->getDerivedDirection().x*mult), nodeEnemy->getPosition().y + 75, nodeEnemy->getPosition().z+(camEnemy->getDerivedDirection().z*mult));
    ball->addToBullet(dir, pow);
    ball->thrownBy(true); 
    ball = NULL;
    mPower = 1;
    mThrowing = false;
}

bool Enemy::isThrowing(){
    return mThrowing;
}

void Enemy::getNearBall(Ball* ball, const Ogre::FrameEvent& evt){
    if (ball->getPosition().z < -10){
	    Ogre::Vector3 relPos = ball->getPosition() - nodeEnemy->getPosition();
        relPos=Ogre::Vector3(relPos.x,0,relPos.z);
	    btVector3 speed=ball->getBody()->getLinearVelocity();
	    Ogre::Vector3 vel=Ogre::Vector3(speed.x(),0,speed.z());
	    relPos.normalise();
	    vel.normalise();
	    relPos+=vel;
	    relPos.normalise();
	    nodeEnemy->translate(relPos.x ,0,relPos.z, Ogre::Node::TS_WORLD);
    }

    if(nodeEnemy->getPosition().z > 0)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, 0);
    if(nodeEnemy->getPosition().z < -280)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, -280);
    if(nodeEnemy->getPosition().x < -80)
        nodeEnemy->setPosition(-80, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);
    if(nodeEnemy->getPosition().x > 80)
        nodeEnemy->setPosition(80, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);


	Simulator::Simulation.getWorld()->removeRigidBody(body);
	btTransform t;
	body->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeEnemy->getPosition().x,-50,nodeEnemy->getPosition().z);
	t.setOrigin(pos);
	body->proceedToTransform(t);
	Simulator::Simulation.getWorld()->addRigidBody(body);
}

void Enemy::getAwayBall(Ball* ball, const Ogre::FrameEvent& evt){
//    std::cout<<"\nOHSHIT OHSHIT OHSHIT\n";
//    std::cout<<ball->isDangerous();
//    std::cout<<" <- danger\n";
    if (ball->getPosition().z < -10){
	    btVector3 ballvel=ball->getBody()->getLinearVelocity();
	    ballvel/=60;
	    ballvel.setY(0);
	    btVector3 newdir = ballvel.cross(btVector3(0,1,0));
	    newdir.normalize();
	    nodeEnemy->translate(newdir.x()*10,0,newdir.z()*10, Ogre::Node::TS_WORLD);
    }
    if(nodeEnemy->getPosition().z > 0)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, 0);
    if(nodeEnemy->getPosition().z < -280)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, -280);
    if(nodeEnemy->getPosition().x < -80)
        nodeEnemy->setPosition(-80, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);
    if(nodeEnemy->getPosition().x > 80)
        nodeEnemy->setPosition(80, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);

	Simulator::Simulation.getWorld()->removeRigidBody(body);
	btTransform t;
	body->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeEnemy->getPosition().x,-50,nodeEnemy->getPosition().z);
	t.setOrigin(pos);
	body->proceedToTransform(t);
	Simulator::Simulation.getWorld()->addRigidBody(body);
}

btVector3 Enemy::throwDir(){
	return btVector3(camEnemy->getDerivedDirection().x,camEnemy->getDerivedDirection().y,camEnemy->getDerivedDirection().z);
}

Ogre::Real Enemy::throwPower(){
	return mPower;
}

void Enemy::setRelease(bool b){
	mRelease=b;
}

bool Enemy::isReleasing(){
	return mRelease;
}

bool Enemy::isInPlay()
{
	return inPlay;
}

void Enemy::setInPlay(bool b)
{
	if(inPlay&&!b)
	{
		nodeEnemy->setVisible(false);
		Simulator::Simulation.getWorld()->removeRigidBody(body);
	}
	inPlay=b;
}

void Enemy::respawn()
{
	if(inPlay)
	{
		Simulator::Simulation.getWorld()->removeRigidBody(body);
	}
	nodeEnemy->setPosition(spawnPoint);
	nodeEnemy->setVisible(true);
	btTransform t;
	body->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeEnemy->getPosition().x,-50,nodeEnemy->getPosition().z);
	t.setOrigin(pos);
	body->proceedToTransform(t);
	Simulator::Simulation.getWorld()->addRigidBody(body);
}

/*  std::stringstream ss (std::stringstream::in | std::stringstream::out);
    ss << camEnemy->getDerivedDirection().x;
        std::cout<<"throw dir: x="+ss.str();
        ss.str(std::string());
        ss << camEnemy->getDerivedDirection().y;
        std::cout<<" y="+ss.str();
        ss.str(std::string());
        ss << camEnemy->getDerivedDirection().z;
        std::cout<<" z="+ss.str()+"\n";*/
