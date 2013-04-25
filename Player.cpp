//Player.cpp
#include <Player.h>
#include <sstream>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Player::Player(Ogre::SceneManager* sceneMgr){
	mSceneMgr = sceneMgr;
    mHasBall = false;
    ball = NULL;

	camPlayer = mSceneMgr->createCamera("Player1Cam");
    camPlayer->setNearClipDistance(5);

    entPlayer = mSceneMgr->createEntity("entPlayer", "ninja.mesh");
    entPlayer->setCastShadows(true);
 
    nodePlayer = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodePlayer", Ogre::Vector3(0,-100,200));
    nodePlayer->attachObject(entPlayer);
    nodePlayer->attachObject(camPlayer);
    nodePlayer->scale(.50,.50,.50);

    camPlayer->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y + 180, nodePlayer->getPosition().x -10);
}

void Player::move(const Ogre::FrameEvent& evt){
    nodePlayer->translate(transVector * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
    if(mHasBall)
		{
        ball->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z);

		}

    if(nodePlayer->getPosition().z < 0)
        nodePlayer->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y, 0);
    if(nodePlayer->getPosition().z > 280)
        nodePlayer->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y, 280);
    if(nodePlayer->getPosition().x < -80)
        nodePlayer->setPosition(-80, nodePlayer->getPosition().y, nodePlayer->getPosition().z);
    if(nodePlayer->getPosition().x > 80)
        nodePlayer->setPosition(80, nodePlayer->getPosition().y, nodePlayer->getPosition().z);
}

void Player::startMove(Ogre::String key){
    if(key.compare("w") == 0)
        transVector.z = -mMove;
    if(key.compare("a") == 0)
        transVector.x = -mMove;
    if(key.compare("s") == 0)
        transVector.z = mMove;
    if(key.compare("d") == 0)
        transVector.x = mMove;
}

void Player::stopMove(Ogre::String key){
    if(key.compare("w") == 0)
        transVector.z = 0;
    if(key.compare("a") == 0)
        transVector.x = 0;
    if(key.compare("s") == 0)
        transVector.z = 0;
    if(key.compare("d") == 0)
        transVector.x = 0;
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
    if(std::abs(nodePlayer->getPosition().x - baller->getPosition().x) < 5 && std::abs(nodePlayer->getPosition().z - baller->getPosition().z) < 5){
        ball = baller;
        ball->setPosition(nodePlayer->getPosition().x, nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z);
				ball->removeFromBullet();
        mHasBall = true;
    }
}

void Player::throwBall(){
    mHasBall = false;
		Ogre::Vector3 muldir=Ogre::Vector3(camPlayer->getDerivedDirection().x,0,camPlayer->getDerivedDirection().z);
		float mult = 6.0f/muldir.length();
    ball->setPosition(nodePlayer->getPosition().x+(camPlayer->getDerivedDirection().x*mult), nodePlayer->getPosition().y + 75, nodePlayer->getPosition().z+(camPlayer->getDerivedDirection().z*mult));
	/*	std::stringstream ss (std::stringstream::in | std::stringstream::out);
  	ss << camPlayer->getDerivedDirection().x;
		std::cout<<"throw dir: x="+ss.str();
		ss.str(std::string());
		ss << camPlayer->getDerivedDirection().y;
		std::cout<<" y="+ss.str();
		ss.str(std::string());
		ss << camPlayer->getDerivedDirection().z;
		std::cout<<" z="+ss.str()+"\n";*/
		btVector3 dir=btVector3(camPlayer->getDerivedDirection().x,camPlayer->getDerivedDirection().y,camPlayer->getDerivedDirection().z);
		ball->addToBullet(dir);	
    ball = NULL;
}
