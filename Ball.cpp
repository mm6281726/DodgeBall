//Ball.cpp
#include <Ball.h>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Ball::Ball(Ogre::SceneManager* sceneMgr){
	mSceneMgr = sceneMgr;

    entBall = mSceneMgr->createEntity("entBall", "sphere.mesh");
 
    nodeBall = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeBall", Ogre::Vector3(0,-100,0));
    nodeBall->attachObject(entBall);
    nodeBall->scale(.50,.50,.50);
}

void Ball::move(const Ogre::FrameEvent& evt){
    nodeBall->translate(transVector * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
    if(nodeBall->getPosition().y < -80)
        nodeBall->setPosition(nodeBall->getPosition().x, -80, nodeBall->getPosition().z);
    if(nodeBall->getPosition().y > 180)
        nodeBall->setPosition(nodeBall->getPosition().x, 180, nodeBall->getPosition().z;
    if(nodeBall->getPosition().x < -80)
        nodeBall->setPosition(-80, nodeBall->getPosition().y, nodeBall->getPosition().z);
    if(nodeBall->getPosition().x > 80)
        nodeBall->setPosition(80, nodeBall->getPosition().y, nodeBall->getPosition().z);
}