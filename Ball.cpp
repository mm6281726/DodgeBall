//Ball.cpp
#include <Ball.h>

static Ogre::Real mMove = 150;      // The movement constant
static Ogre::Real mRotate = 0.13;
static Ogre::Vector3 transVector = Ogre::Vector3::ZERO;
bool velInfo[3];
int mBounce;

Ball::Ball(Ogre::SceneManager* sceneMgr, Simulator* s, Ogre::String name, int x,int ind){
	mSceneMgr = sceneMgr;
	mThrownByEnemy = false;
	mIsPickedUp = false;

    entBall = mSceneMgr->createEntity("ent" + name, "sphere.mesh");
    entBall->setMaterialName("Examples/SphereMappedRustySteel");
    entBall->setCastShadows(true);
    spawnPoint=Ogre::Vector3(x,-95,0);
    nodeBall = mSceneMgr->getRootSceneNode()->createChildSceneNode("node" + name, spawnPoint);
    nodeBall->attachObject(entBall);
    nodeBall->scale(.05,.05,.05);


	simulator = s;
	physicsBall = simulator->addSphere(5,0,0,0,5,ind);
	dangerous=0;
}

void Ball::gotPickedUp(){
	mIsPickedUp = true;
}

void Ball::gotThrown(){
	mIsPickedUp = false;
}

bool Ball::isPickedUp(){
	return mIsPickedUp;
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

void Ball::addToBullet(btVector3 dir, Ogre::Real power)
{
	btTransform t;
	physicsBall->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeBall->getPosition().x,nodeBall->getPosition().y,nodeBall->getPosition().z);
	t.setOrigin(pos);
	physicsBall->proceedToTransform(t);
	physicsBall->setLinearVelocity(dir * 200 * power);
	simulator->getWorld()->addRigidBody(physicsBall);
	velInfo[0]=(dir.getX()>=0);
	velInfo[1]=(dir.getY()>=0);
	velInfo[2]=(dir.getZ()>=0);
	mBounce=0;
	//dangerous=-1;
}

void Ball::removeFromBullet(void)
{
	physicsBall->setLinearVelocity(btVector3(0,0,0));
	simulator->getWorld()->removeRigidBody(physicsBall);
	velInfo[0]=true;
	velInfo[1]=true;
	velInfo[2]=true;
	mBounce=0;
	dangerous=0;
}

int Ball::numBounces(void)
{
	return mBounce;
}

bool Ball::bounceCheck(void)
{
	bool bounced=false;
	btVector3 vel = physicsBall->getLinearVelocity();
	if(dangerous == -1 && ((vel.getX()>=0) != velInfo[0]) || ((vel.getZ()>=0) != velInfo[2]))
	{
		velInfo[0]=(vel.getX()>=0);
		velInfo[2]=(vel.getZ()>=0);
		bounced= true;
	}
	if(((vel.getY()>=0) && !velInfo[1]) || ((vel.getY()<-10) && velInfo[1]))
	{
		velInfo[1]=(vel.getY()>=0);
		bounced= true;
	}
	else if(vel.getY()<0 && velInfo[1])
	{
		velInfo[1]=(vel.getY()>=0);
	}
	if(bounced)
		mBounce++;
	return bounced;
}

void Ball::setDanger(int dan)
{
	dangerous=dan;
	if(dangerous < 0)
		entBall->setMaterialName("Examples/Fish");
	else
		entBall->setMaterialName("Examples/SphereMappedRustySteel");
}

int Ball::isDangerous(void)
{
	return dangerous;
}

bool Ball::towardsPos(Ogre::Vector3 pos)
{
	Ogre::Vector3 vel=Ogre::Vector3(physicsBall->getLinearVelocity().x(),0,physicsBall->getLinearVelocity().z());
	vel/=60;
	vel.normalise();
	Ogre::Vector3 relPos = pos - nodeBall->getPosition();
	relPos.normalise();
	return relPos.directionEquals(vel,Ogre::Radian(.5));
	//Ogre::Vector3 nextPos=nodeBall->getPosition()+vel;
	
}

void Ball::respawn()
{
	nodeBall->setPosition(spawnPoint);
	if(!mIsPickedUp)
		removeFromBullet();
	btTransform t;
	physicsBall->getMotionState()->getWorldTransform(t);
	btVector3 pos = btVector3(nodeBall->getPosition().x,nodeBall->getPosition().y,nodeBall->getPosition().z);
	t.setOrigin(pos);
	physicsBall->proceedToTransform(t);
	physicsBall->setLinearVelocity(btVector3(0,0,0));
	simulator->getWorld()->addRigidBody(physicsBall);
	setDanger(0);
}
void Ball::thrownBy(bool thrownByEnemy){
	mThrownByEnemy = thrownByEnemy;
}

bool Ball::thrownBy(){
	return mThrownByEnemy;
}
