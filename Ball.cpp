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
 
    nodeBall = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeBall", Ogre::Vector3(0,-95,0));
    nodeBall->attachObject(entBall);
    nodeBall->scale(.05,.05,.05);
}

Ogre::Vector3 Ball::getPosition(){
    return nodeBall->getPosition();
}

void Ball::setPosition(int x, int y, int z){
    nodeBall->setPosition(x,y,z);
}

void Ball::translate(const Ogre::Vector3 & d, Ogre::Node::TransformSpace relativeTo){
    nodeBall->translate(d, relativeTo);
}