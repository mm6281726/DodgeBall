//Enemy.cpp
#include <Enemy.h>
#include <sstream>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Enemy::Enemy(Ogre::SceneManager* sceneMgr, int x, int z){
	mSceneMgr = sceneMgr;
    mHasBall = false;
    ball = NULL;
    mPower = 1;
    mThrowing = false;
    entEnemy = mSceneMgr->createEntity("entEnemy", "ninja.mesh");
    nodeEnemy = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeEnemy", Ogre::Vector3(x,-100,z));
    camEnemy = mSceneMgr->createCamera("EnemyCam");
    nodeEnemy->attachObject(camEnemy);
    nodeEnemy->yaw(Ogre::Degree(180));

    entEnemy->setCastShadows(true);
    camEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y + 180, nodeEnemy->getPosition().x -10);
    camEnemy->setNearClipDistance(5);
    nodeEnemy->attachObject(entEnemy);
    nodeEnemy->scale(.50,.50,.50);
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

void Enemy::beginThrow(){
    GUIManager::GUIControl.createPowerBar();
    GUIManager::GUIControl.setPowerBarProgress(0);
    mThrowing = true;	
}

void Enemy::chargeThrow(){
    mPower+=0.02;
    if(mPower > 4)
        mPower = 4;
    GUIManager::GUIControl.setPowerBarProgress(mPower/4);
}

void Enemy::endThrow(Ogre::Vector3 playerloc){
    mHasBall = false;
    camEnemy->lookAt(playerloc.x, -20, playerloc.z);
    Ogre::Vector3 muldir=Ogre::Vector3(camEnemy->getDerivedDirection().x,0,camEnemy->getDerivedDirection().z);
    float mult = 20.0f/muldir.length();
    ball->setPosition(nodeEnemy->getPosition().x+(camEnemy->getDerivedDirection().x*mult), nodeEnemy->getPosition().y + 75, nodeEnemy->getPosition().z+(camEnemy->getDerivedDirection().z*mult));
    btVector3 dir=btVector3(camEnemy->getDerivedDirection().x,camEnemy->getDerivedDirection().y,camEnemy->getDerivedDirection().z);
    //btVector3 dir=btVector3(playerloc.x - nodeEnemy->getPosition().x, playerloc.y - nodeEnemy->getPosition().y, playerloc.z - nodeEnemy->getPosition().z);
    ball->addToBullet(dir, 3);
    ball = NULL;
    mPower = 1;
    mThrowing = false;

    GUIManager::GUIControl.destroyPowerBar();
    GUIManager::GUIControl.threwBall();
}

void Enemy::extThrow(btVector3 dir, Ogre::Real pow){
    mHasBall = false;
    Ogre::Vector3 muldir=Ogre::Vector3(camEnemy->getDerivedDirection().x,0,camEnemy->getDerivedDirection().z);
    float mult = 20.0f/muldir.length();
    ball->setPosition(nodeEnemy->getPosition().x+(camEnemy->getDerivedDirection().x*mult), nodeEnemy->getPosition().y + 75, nodeEnemy->getPosition().z+(camEnemy->getDerivedDirection().z*mult));
    ball->addToBullet(dir, pow); 
    ball = NULL;
    mPower = 1;
    mThrowing = false;

    GUIManager::GUIControl.destroyPowerBar();
    GUIManager::GUIControl.threwBall();
}

bool Enemy::isThrowing(){
    return mThrowing;
}

void Enemy::getNearBall(Ball* ball, const Ogre::FrameEvent& evt){
    if (ball->getPosition().z < -10)
        nodeEnemy->translate((ball->getPosition().x - nodeEnemy->getPosition().x) * evt.timeSinceLastFrame,0,(ball->getPosition().z - nodeEnemy->getPosition().z) * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

    if(nodeEnemy->getPosition().z > 0)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, 0);
    if(nodeEnemy->getPosition().z < -280)
        nodeEnemy->setPosition(nodeEnemy->getPosition().x, nodeEnemy->getPosition().y, -280);
    if(nodeEnemy->getPosition().x < -80)
        nodeEnemy->setPosition(-80, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);
    if(nodeEnemy->getPosition().x > 80)
        nodeEnemy->setPosition(80, nodeEnemy->getPosition().y, nodeEnemy->getPosition().z);
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

/*  std::stringstream ss (std::stringstream::in | std::stringstream::out);
    ss << camEnemy->getDerivedDirection().x;
        std::cout<<"throw dir: x="+ss.str();
        ss.str(std::string());
        ss << camEnemy->getDerivedDirection().y;
        std::cout<<" y="+ss.str();
        ss.str(std::string());
        ss << camEnemy->getDerivedDirection().z;
        std::cout<<" z="+ss.str()+"\n";*/