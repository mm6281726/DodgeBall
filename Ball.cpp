//Ball.cpp
#include <Ball.h>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Ball::Ball(Ogre::SceneManager* sceneMgr){
	mSceneMgr = sceneMgr;

    entBall = mSceneMgr->createEntity("entBall", "sphere.mesh");
    entBall->setMaterialName("Examples/SphereMappedRustySteel");
    entBall->setCastShadows(true);
 
    nodeBall = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeBall", Ogre::Vector3(0,-90,0));
    nodeBall->attachObject(entBall);
    nodeBall->scale(.1,.1,.1);
}

Ogre::Vector3 Ball::getPosition(){
    return nodeBall->getPosition();
}

Ogre::SceneNode* Ball::getSceneNode(){
    return nodeBall;
}