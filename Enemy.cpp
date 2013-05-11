//Enemy.cpp
#include <Enemy.h>
#include <sstream>

#include <PlayerManager.h>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;


Enemy::Enemy(Ogre::SceneManager* sceneMgr,int i, int x, int z,int ind){
	mSceneMgr = sceneMgr;
    mHasBall = false;
    ball = NULL;
    mPower = 1;
    mThrowing = false;
    spawnPoint=Ogre::Vector3(x,-100,z);
    entEnemy = mSceneMgr->createEntity("entEnemy" + Ogre::StringConverter::toString(i), "ninja.mesh");
    nodeEnemy = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeEnemy" + Ogre::StringConverter::toString(i), spawnPoint);
    camEnemy = mSceneMgr->createCamera("camEnemy" + Ogre::StringConverter::toString(i));
    nodeEnemy->attachObject(camEnemy);
    nodeEnemy->yaw(Ogre::Degree(180));

    entEnemy->setCastShadows(true);
    camEnemy->setPosition(0, nodeEnemy->getPosition().y + 180, nodeEnemy->getPosition().x -10);
    camEnemy->setNearClipDistance(5);
    nodeEnemy->attachObject(entEnemy);
    nodeEnemy->scale(.50,.50,.50);
    inPlay=true;

	body = Simulator::Simulation.addCylinder(20,100,x,-50,z,0, false,ind);
	enemyX=0;
	enemyZ=0;
	randCounterX=0;
	randCounterZ=0;
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
        ball->gotPickedUp();
        mHasBall = true;
    }
}

void Enemy::pickupBallPhysics(Ball* baller){
        ball = baller;
        ball->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y + 75, nodeEnemy->getPosition().z);
		ball->removeFromBullet();
        ball->gotPickedUp();
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
    ball->gotThrown();
    ball->setDanger(-1);
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
    ball->gotThrown();
    ball->setDanger(-1);
    ball = NULL;
    mPower = 1;
    mThrowing = false;
}

bool Enemy::isThrowing(){
    return mThrowing;
}

bool Enemy::getNearBall(Ball* ball, const Ogre::FrameEvent& evt){
	Ogre::Vector3 originalPos=nodeEnemy->getPosition();
    if (ball->getPosition().z < -1){
	    Ogre::Vector3 relPos = ball->getPosition() - nodeEnemy->getPosition();
        relPos=Ogre::Vector3(relPos.x,0,relPos.z);
	    btVector3 speed=ball->getBody()->getLinearVelocity();
	    Ogre::Vector3 vel=Ogre::Vector3(speed.x(),0,speed.z());
	    relPos.normalise();
	    vel.normalise();
	    relPos+=vel;
	    relPos.normalise();
	    nodeEnemy->translate(relPos.x*2 ,0,relPos.z*2, Ogre::Node::TS_WORLD);
    }

    if(nodeEnemy->getPosition().z > 0)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, 0);
    if(nodeEnemy->getPosition().z < -280)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, -280);
    if(nodeEnemy->getPosition().x < -280)
        nodeEnemy->setPosition(-280, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);
    if(nodeEnemy->getPosition().x > 280)
        nodeEnemy->setPosition(280, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);

	if(originalPos.positionEquals(nodeEnemy->getPosition(),0))
	{
		return false;
	}
	Simulator::Simulation.getWorld()->removeRigidBody(body);
	btTransform t;
	body->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeEnemy->getPosition().x,-50,nodeEnemy->getPosition().z);
	t.setOrigin(pos);
	body->proceedToTransform(t);
	Simulator::Simulation.getWorld()->addRigidBody(body);
	return true;
}

void Enemy::getAwayBall(Ball* ball, const Ogre::FrameEvent& evt){

    if (ball->getPosition().z < -10){
	    btVector3 ballvel=ball->getBody()->getLinearVelocity();
	    ballvel.setY(0);
	    btVector3 newdir = ballvel.cross(btVector3(0,1,0));
	    newdir.normalize();
		newdir *= Ogre::Math::RangeRandom(1,2)==1?1:-1;
		enemyX=newdir.x();
		enemyZ=newdir.z();
	    nodeEnemy->translate(newdir.x()*10,0,newdir.z()*10, Ogre::Node::TS_WORLD);
    }
    if(nodeEnemy->getPosition().z > 0)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, 0);
    if(nodeEnemy->getPosition().z < -280)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, -280);
    if(nodeEnemy->getPosition().x < -280)
        nodeEnemy->setPosition(-280, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);
    if(nodeEnemy->getPosition().x > 280)
        nodeEnemy->setPosition(280, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);

	Simulator::Simulation.getWorld()->removeRigidBody(body);
	btTransform t;
	body->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeEnemy->getPosition().x,-50,nodeEnemy->getPosition().z);
	t.setOrigin(pos);
	body->proceedToTransform(t);
	Simulator::Simulation.getWorld()->addRigidBody(body);
}

void Enemy::randomMove(){
	//
	Ogre::Vector3 originalPos=nodeEnemy->getPosition();
	int rand=Ogre::Math::RangeRandom(1,3);
	randCounterX+=rand;
	rand=Ogre::Math::RangeRandom(1,3);
	randCounterZ+=rand;
	int xDir=Ogre::Math::Abs(enemyX)/enemyX;
	int zDir=Ogre::Math::Abs(enemyZ)/enemyZ;
	enemyX=xDir*(Ogre::Math::RangeRandom(1,3));
	enemyZ=zDir*(Ogre::Math::RangeRandom(1,3));
	if(randCounterX>70)
	{
		enemyX=-enemyX;
		randCounterX=0;
	}
	if(randCounterZ>80)
	{
		enemyZ=-enemyZ;
		randCounterZ=0;
	}
	//enemyX=rand<10?enemyX:-enemyX;
	//enemyZ=rand<5?enemyZ:-enemyZ;
	
/*	std::cout<<"\nenemy x: ";	
	std::cout<<enemyX;
	std::cout<<" and z: ";
	std::cout<<enemyZ;
	std::cout<<"\n";*/
	Ogre::Vector3 newdir = Ogre::Vector3(enemyX,0,enemyZ);
	newdir.normalise();
	nodeEnemy->translate(newdir.x*2,0,newdir.z*2, Ogre::Node::TS_WORLD);

/*	if(nodeEnemy->getPosition().positionEquals(PlayerManager::PlayerControl.closestEnemyToEnemy(this,nodeEnemy->getPosition())->getPosition(),20))
	{
		nodeEnemy->setPosition(originalPos);
		return;
	}*/
	if(nodeEnemy->getPosition().z > -10)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, 0);
    if(nodeEnemy->getPosition().z < -280)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, -280);
    if(nodeEnemy->getPosition().x < -280)
        nodeEnemy->setPosition(-280, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);
    if(nodeEnemy->getPosition().x > 280)
        nodeEnemy->setPosition(280, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);

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
