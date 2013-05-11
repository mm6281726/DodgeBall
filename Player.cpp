//Player.cpp
#include <Player.h>
#include <sstream>

static Ogre::Real mMove = 250;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Player::Player(Ogre::SceneManager* sceneMgr, Ogre::String name, int x, int z,int ind){
	mSceneMgr = sceneMgr;
    mHasBall = false;
    ball = NULL;
    mPower = 1;
    mThrowing = false;
    //mRayScnQuery = mSceneMgr->createRayQuery(Ogre::Ray());

    entPlayer = mSceneMgr->createEntity("ent" + name, "ninja.mesh");
    spawnPoint=Ogre::Vector3(x,-100,z);
    nodePlayer = mSceneMgr->getRootSceneNode()->createChildSceneNode("node" + name, spawnPoint);
    camPlayer = mSceneMgr->createCamera(name + "Cam");
    nodePlayer->attachObject(camPlayer);

    entPlayer->setCastShadows(true);
    camPlayer->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y + 180, nodePlayer->getPosition().x -10);
    camPlayer->setNearClipDistance(5);
    nodePlayer->attachObject(entPlayer);
    nodePlayer->scale(.50,.50,.50);
    nodePlayer->yaw(Ogre::Degree(100));
    camPlayer->lookAt(0, 0, -250);
    inPlay=true;

    body = Simulator::Simulation.addCylinder(20,100,x,-50,z,0, true,ind);
	wKey=false;
	aKey=false;
	sKey=false;
	dKey=false;
}

Ogre::Vector3 Player::getPosition(){
    return nodePlayer->getPosition();
}

void Player::move(const Ogre::FrameEvent& evt){
    nodePlayer->translate(transVector * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
    if(mHasBall)
        ball->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z);

    if(nodePlayer->getPosition().z < 0)
        nodePlayer->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y, 0);
    if(nodePlayer->getPosition().z > 280)
        nodePlayer->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y, 280);
    if(nodePlayer->getPosition().x < -280)
        nodePlayer->setPosition(-280, nodePlayer->getPosition().y, nodePlayer->getPosition().z);
    if(nodePlayer->getPosition().x > 280)
        nodePlayer->setPosition(280, nodePlayer->getPosition().y, nodePlayer->getPosition().z);
	
	Simulator::Simulation.getWorld()->removeRigidBody(body);
	btTransform t;
	body->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodePlayer->getPosition().x,-50,nodePlayer->getPosition().z);
	t.setOrigin(pos);
	body->proceedToTransform(t);
	Simulator::Simulation.getWorld()->addRigidBody(body);
}

void Player::startMove(Ogre::String key){
    if(key.compare("w") == 0)
	{
		wKey=true;
        transVector.z = -mMove;
	}	
	if(key.compare("s") == 0)
	{
		sKey=true;
        transVector.z = mMove;
	}    
	if(key.compare("a") == 0)
    {
		aKey=true;
	    transVector.x = -mMove;
	}
    if(key.compare("d") == 0)
	{
		dKey=true;
        transVector.x = mMove;
	}
}

void Player::stopMove(Ogre::String key){
    if(key.compare("w") == 0)
	{
		wKey=false;
        transVector.z = sKey?mMove:0;
	}    
	if(key.compare("a") == 0)
	{
		aKey=false;
        transVector.x = dKey?mMove:0;
	}
    if(key.compare("s") == 0)
	{
		sKey=false;
        transVector.z = wKey?-mMove:0;
	}
    if(key.compare("d") == 0)
	{
		dKey=false;
        transVector.x = aKey?-mMove:0;
	}
}

void Player::lookAround(const OIS::MouseEvent &arg){
    camPlayer->pitch(Ogre::Degree(-(arg.state.Y.rel) * mRotate));
    nodePlayer->yaw(Ogre::Degree(-(arg.state.X.rel) * mRotate));
    //if(mHasBall)
    //    ball->setPosition(camPlayer->getDerivedPosition());

    // Angle of rotation around the X-axis.
    Ogre::Real pitchAngle = (2 * Ogre::Degree(Ogre::Math::ACos(camPlayer->getOrientation().w)).valueDegrees());
 
    // Just to determine the sign of the angle we pick up above, the
    // value itself does not interest us.
    Ogre::Real pitchAngleSign = camPlayer->getOrientation().x;
 
    // Limit the pitch between -90 degress and +90 degrees, Quake3-style.
    if (pitchAngle > 90.0f)
    {
        if (pitchAngleSign > 0)
            // Set orientation to 90 degrees on X-axis.
            camPlayer->setOrientation(Ogre::Quaternion(Ogre::Math::Sqrt(0.5f),
                                                                Ogre::Math::Sqrt(0.5f), 0, 0));
        else if (pitchAngleSign < 0)
            // Sets orientation to -90 degrees on X-axis.
            camPlayer->setOrientation(Ogre::Quaternion(Ogre::Math::Sqrt(0.5f),
                                                                -Ogre::Math::Sqrt(0.5f), 0, 0));
    }
}

bool Player::hasBall(){
    return mHasBall;
}

void Player::pickupBall(Ball* baller){
    Ogre::Vector3 diff = Ogre::Vector3(nodePlayer->getPosition().x - baller->getPosition().x ,0,nodePlayer->getPosition().z - baller->getPosition().z);
    //if( (baller->getPosition().x-10 <= max.x  && baller->getPosition().x+10 >= min.x) && (baller->getPosition().z <= max.z  && baller->getPosition().z >= min.z) &&  baller->getPosition().y < 0){
    if(diff.length() < 15.0f &&  baller->getPosition().y < 0){
        ball = baller;
        ball->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z);
		ball->removeFromBullet();
        mHasBall = true;
        ball->gotPickedUp();
    }
}

void Player::pickupBallPhysics(Ball* baller){
        ball = baller;
        mHasBall = true;
        ball->gotPickedUp();
		ball->removeFromBullet();
        ball->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z);
}

void Player::beginThrow(){
    GUIManager::GUIControl.createPowerBar();
    GUIManager::GUIControl.setPowerBarProgress(0);
    mThrowing = true;	
}

void Player::chargeThrow(){
    mPower+=0.04;
    if(mPower > 4)
        mPower = 4;
    GUIManager::GUIControl.setPowerBarProgress(mPower/4);
}

void Player::endThrow(){
    mHasBall = false;
    Ogre::Vector3 muldir=Ogre::Vector3(camPlayer->getDerivedDirection().x,0,camPlayer->getDerivedDirection().z);
    float mult = 20.0f/muldir.length();
    ball->setPosition(nodePlayer->getPosition().x+(camPlayer->getDerivedDirection().x*mult), nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z+(camPlayer->getDerivedDirection().z*mult));
    btVector3 dir=btVector3(camPlayer->getDerivedDirection().x,camPlayer->getDerivedDirection().y,camPlayer->getDerivedDirection().z);
    ball->addToBullet(dir, mPower);
    ball->thrownBy(false); 
    ball->gotThrown();
    ball->setDanger(1);
    ball = NULL;
    mPower = 1;
    mThrowing = false;

    GUIManager::GUIControl.destroyPowerBar();
    GUIManager::GUIControl.threwBall();
}

void Player::extThrow(btVector3 dir, Ogre::Real pow){
    mHasBall = false;
    Ogre::Vector3 muldir=Ogre::Vector3(camPlayer->getDerivedDirection().x,0,camPlayer->getDerivedDirection().z);
    float mult = 20.0f/muldir.length();
    ball->setPosition(nodePlayer->getPosition().x+(camPlayer->getDerivedDirection().x*mult), nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z+(camPlayer->getDerivedDirection().z*mult));
    ball->addToBullet(dir, pow);
    ball->thrownBy(false); 
    ball->gotThrown();
    ball->setDanger(1);
    ball = NULL;
    mPower = 1;
    mThrowing = false;

    GUIManager::GUIControl.destroyPowerBar();
    GUIManager::GUIControl.threwBall();
}

bool Player::isThrowing(){
    return mThrowing;
}

btVector3 Player::throwDir(){
	return btVector3(camPlayer->getDerivedDirection().x,camPlayer->getDerivedDirection().y,camPlayer->getDerivedDirection().z);
}

Ogre::Real Player::throwPower(){
	return mPower;
}

void Player::setRelease(bool b){
	mRelease=b;
}

bool Player::isReleasing(){
	return mRelease;
}

bool Player::isInPlay()
{
	return inPlay;
}

void Player::setInPlay(bool b)
{
	if(inPlay&&!b)
	{
		nodePlayer->setVisible(false);
		Simulator::Simulation.getWorld()->removeRigidBody(body);
	}
	inPlay=b;
}

void Player::respawn()
{
	if(inPlay)
	{
		Simulator::Simulation.getWorld()->removeRigidBody(body);
	}
	nodePlayer->setPosition(spawnPoint);
	nodePlayer->setVisible(true);
	btTransform t;
	body->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodePlayer->getPosition().x,-50,nodePlayer->getPosition().z);
	t.setOrigin(pos);
	body->proceedToTransform(t);
	Simulator::Simulation.getWorld()->addRigidBody(body);
}

/*  std::stringstream ss (std::stringstream::in | std::stringstream::out);
    ss << camPlayer->getDerivedDirection().x;
        std::cout<<"throw dir: x="+ss.str();
        ss.str(std::string());
        ss << camPlayer->getDerivedDirection().y;
        std::cout<<" y="+ss.str();
        ss.str(std::string());
        ss << camPlayer->getDerivedDirection().z;
        std::cout<<" z="+ss.str()+"\n";*/
