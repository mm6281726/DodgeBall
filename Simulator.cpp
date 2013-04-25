#include "Simulator.h"


Simulator::Simulator()
{
	//paddleLocation = btVector3(0.f,0.f,0.f);
	//world = NULL;
}
//-------------------------------------------------------------------------------------
Simulator::~Simulator(void)
{
}

btRigidBody* Simulator::addPlane(float x,float y,float z,btVector3 normal)
{
	//similar to createSphere
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(x,y,z));
	btStaticPlaneShape* plane= new btStaticPlaneShape(normal,0);
	btMotionState* motion= new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo info(0.0,motion,plane);
	btRigidBody* body=new btRigidBody(info);
    	body->setRestitution(1.0);
	world->addRigidBody(body);
	bodies.push_back(body);
	return body;
}

btRigidBody* Simulator::addSphere(float rad,float x,float y,float z,float mass)
{
	btTransform t;	//position and rotation
	t.setIdentity();
	t.setOrigin(btVector3(x,y,z));	//put it to x,y,z coordinates
	btSphereShape* sphere=new btSphereShape(rad);	//it's a sphere, so use sphereshape
	btVector3 inertia(0,0,0);	//inertia is 0,0,0 for static object, else
	if(mass!=0.0)
		sphere->calculateLocalInertia(mass,inertia);	//it can be determined by this function (for all kind of shapes)
	
	btMotionState* motion=new btDefaultMotionState(t);	//set the position (and motion)
	btRigidBody::btRigidBodyConstructionInfo info(mass,motion,sphere,inertia);	//create the constructioninfo, you can create multiple bodies with the same info
	btRigidBody* body=new btRigidBody(info);	//let's create the body itself
  body->setRestitution(1);
	body->setLinearVelocity(btVector3(0,0,0));
	world->addRigidBody(body);	//and let the world know about it
	bodies.push_back(body);	//to be easier to clean, I store them a vector
	return body;
}

btDiscreteDynamicsWorld* Simulator::setupSimulator(void)
{
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new	btCollisionDispatcher(collisionConfiguration);
	btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
	world = new btDiscreteDynamicsWorld(dispatcher,overlappingPairCache,solver,collisionConfiguration);
	world->setGravity(btVector3(0,-25,0));

	addPlane(-100,0,0,btVector3(1,0,0));
	addPlane(100,0,0,btVector3(-1,0,0));
  addPlane(0,-100,0,btVector3(0,1,0));
	addPlane(0,100,0,btVector3(0,-1,0));
	addPlane(0,0,-300,btVector3(0,0,1));
	addPlane(0,0,300,btVector3(0,0,-1));
	
	std::cout << "****************************************************************************************setup complete";

	return world;
}

void Simulator::handleCollisions(void)
{
	std::cout << "~~~------~~~~~~~-------~~~------~~~~~~~-------got to handle collisions";
	//for(int c=0;c<1000 && simulate;c++)
	while(simulate)
	{
	//	paddleBody->getMotionState()->getWorldTransform()->setOrigin(paddleLocation);
		world->stepSimulation(1.f/60.f,10);
		//check for collisions (Somehow)			---	-		--		--		This may not work... I had trouble running Bullet at home, so this is the extent of my ability. 
		int numManifolds = world->getDispatcher()->getNumManifolds();		//	Try using world->ContactResultCallback().
		for (int i=0;i<numManifolds;i++)
		{
			btPersistentManifold* contactManifold =  world->getDispatcher()->getManifoldByIndexInternal(i);
			btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0());
			btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1());
			btRigidBody* first = btRigidBody::upcast(obA);
			btRigidBody* second = btRigidBody::upcast(obB);
			if((first && first == ballBody) || (second && second == ballBody))			//may need two if statements to determine which is the ball (and maybe to tell which wall it is?)
			{
				std::cout << "~~~------~~~~~~~-------ball collision------~~~~~~~-------~~~";	//could also use collision points to determine the side of the ball that hit. (use contactManifold)
				//bounce ball - applycentralforce = -2 x force in wall direction
				//check other body to determine bounce direction 
				//ball sfx
			}
			if(first == paddleBody || second == paddleBody)
			{
				std::cout << "~~~------~~~~~~~-------paddle collision------~~~~~~~-------~~~";
				//paddle sfx
			}
		}
	}
}

bool Simulator::updatePaddle(Ogre::Vector3 location)
{
	paddleLocation = btVector3(location.x,location.y,location.z);
	return true;
}
	

void Simulator::runSimulator(bool sim)
{
	simulate = sim;
}

btVector3 Simulator::getBallLocation(void)			///Discover why this segfaults
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~getting ball location";
	btTransform* ballt;
	ballBody->getMotionState()->getWorldTransform(*ballt);
	std::cout << "got ball transform";
	btVector3 temp =ballt->getOrigin();
	return temp;
	//return Ogre::Vector3(temp.x(),temp.y(),temp.z());
}

void Simulator::deletePhysics(void)
{
	// free all resources
}
btDiscreteDynamicsWorld* Simulator::getWorld(void)
{
	return world;
}
