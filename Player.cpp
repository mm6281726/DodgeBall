//Player.cpp
#include <Player.h>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Player::Player(Ogre::SceneManager* sceneMgr){
	mSceneMgr = sceneMgr;
    hasBall = false;

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

void Player::pickupBall(Ball* ball){
    if(hasBall == false && (std::abs(nodePlayer->getPosition().x - ball->getPosition().x) < 5 && std::abs(nodePlayer->getPosition().z - ball->getPosition().z) < 5 )){
        nodePlayer->addChild(ball->getSceneNode());
        hasBall == true;
    }
}