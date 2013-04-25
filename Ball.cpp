//Ball.cpp
#include <Ball.h>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;

Ball::Ball(Ogre::SceneManager* sceneMgr, Simulator* s){
	mSceneMgr = sceneMgr;

  entBall = mSceneMgr->createEntity("entBall", "sphere.mesh");
  entBall->setMaterialName("Examples/SphereMappedRustySteel");
  entBall->setCastShadows(true);
 
    nodeBall = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeBall", Ogre::Vector3(0,-95,0));
    nodeBall->attachObject(entBall);
    nodeBall->scale(.05,.05,.05);


	simulator = s;
	physicsBall = simulator->addSphere(5,0,0,0,5);
}

void Ball::setPosition(int x, int y, int z){
    nodeBall->setPosition(x,y,z);
}

void Ball::setPosition(const Ogre::Vector3 &  pos){
    nodeBall->setPosition(pos);
}

Ogre::Vector3 Ball::getPosition(){
    return nodeBall->getPosition();
}

void Ball::translate(const Ogre::Vector3 & d, Ogre::Node::TransformSpace relativeTo){
    nodeBall->translate(d, relativeTo);
}

void Ball::yaw(Ogre::Degree d){
    nodeBall->yaw(d);
}
btRigidBody* Ball::getBody()
{
	return physicsBall;
}

void Ball::addToBullet(btVector3 dir)
{
	btTransform t;
	physicsBall->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeBall->getPosition().x,nodeBall->getPosition().y,nodeBall->getPosition().z);
	t.setOrigin(pos);
	physicsBall->proceedToTransform(t);
	physicsBall->setLinearVelocity(dir*200);
	simulator->getWorld()->addRigidBody(physicsBall);
}

void Ball::removeFromBullet(void)
{
	simulator->getWorld()->removeRigidBody(physicsBall);
}
