#include "Simulator.h"
#include <Player.h>
#include <Enemy.h>
#include <PlayerManager.h>
#include <Ball.h>
#include <BallManager.h>

Simulator Simulator::Simulation;
Simulator::Simulator()
{
	//paddleLocation = btVector3(0.f,0.f,0.f);
	//world = NULL;
}
//-------------------------------------------------------------------------------------
Simulator::~Simulator(void)
{
}

bool callbackFunc(btManifoldPoint& cp, const btCollisionObject* obj1, int id1, int index1, const btCollisionObject* obj2, int id2, int index2)
{
	bulletObject* a = (bulletObject*)obj1->getUserPointer();
	bulletObject* b = (bulletObject*)obj2->getUserPointer();
/*	std::cout << "\n-------------------------~~~~~~~~~~~~~~~~~~~~~~~~~************************\n";
	std::cout << "Object a type: ";
	std::cout << a->type;
	std::cout << "\nObject b type: ";
	std::cout << b->type;
	std::cout << "\n-------------------------~~~~~~~~~~~~~~~~~~~~~~~~~************************\n";*/
	if( (a->type == BALL && b->type == PLAYER) || (a->type == PLAYER && b->type == BALL) ){
	//	std::cout << "\nBall hit Player\n";
		Ball* ball = a->type == BALL?BallManager::BallControl.getBall(a->index):BallManager::BallControl.getBall(b->index);
		Player* player=a->type == PLAYER?PlayerManager::PlayerControl.getPlayer(a->index):PlayerManager::PlayerControl.getPlayer(b->index);
		if(ball->isDangerous())
		{
			player->setInPlay(false);
		}
		else if(!player->hasBall())
		{
			player->pickupBallPhysics(ball);
		}
		
	}else if( (a->type == BALL && b->type == ENEMY) || (a->type == ENEMY && b->type == BALL) ){
	//	std::cout << "\nBall hit Player\n";
		Ball* ball = a->type == BALL?BallManager::BallControl.getBall(a->index):BallManager::BallControl.getBall(b->index);
		Enemy* enemy=a->type == ENEMY?PlayerManager::PlayerControl.getEnemy(a->index):PlayerManager::PlayerControl.getEnemy(b->index);
		if(ball->isDangerous())
		{
			enemy->setInPlay(false);
		}
		else if(!enemy->hasBall())
		{
			enemy->pickupBallPhysics(ball);
		}
		
	} else if( (a->type == BALL && b->type == WALL) || (a->type == WALL && b->type == BALL) ){
	//	std::cout << "\nBall hit Wall\n";
		Ball* ball = a->type == BALL?BallManager::BallControl.getBall(a->index):BallManager::BallControl.getBall(b->index);
		if(ball->isDangerous())
			ball->setDanger(false);
	}
	return false;
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
	world->addRigidBody(body);//, COL_WALL, COL_BALL);
	bodies.push_back(new bulletObject(body, WALL,-1));
	body->setUserPointer(bodies[bodies.size()-1]);
	return body;
}

btRigidBody* Simulator::addSphere(float rad,float x,float y,float z,float mass, int index)
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
  body->setRestitution(0.9);
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);	
	body->setLinearVelocity(btVector3(0,0,0));
	world->addRigidBody(body);//, COL_BALL, COL_WALL|COL_PLAYER|COL_ENEMY|COL_BALL);	//and let the world know about it
	bodies.push_back(new bulletObject(body, BALL,index));
	body->setUserPointer(bodies[bodies.size()-1]);
	return body;
}

btRigidBody* Simulator::addCylinder(float d,float h,float x,float y,float z,float mass, bool isPlayer, int index)
{
	btTransform t;
  t.setIdentity();
  t.setOrigin(btVector3(x,y,z));
  btCylinderShape* sphere=new btCylinderShape(btVector3(d/2.0,h/2.0,d/2.0));
  btVector3 inertia(0,0,0);
  if(mass!=0.0)
	  sphere->calculateLocalInertia(mass,inertia);
     
  btMotionState* motion=new btDefaultMotionState(t);
  btRigidBody::btRigidBodyConstructionInfo info(mass,motion,sphere,inertia);
  btRigidBody* body=new btRigidBody(info);
  world->addRigidBody(body);	
  bodies.push_back(new bulletObject(body, isPlayer?PLAYER:ENEMY, index));
  body->setUserPointer(bodies[bodies.size()-1]);
  return body;
}

btDiscreteDynamicsWorld* Simulator::setupSimulator(void)
{
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new	btCollisionDispatcher(collisionConfiguration);
	btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
	world = new btDiscreteDynamicsWorld(dispatcher,overlappingPairCache,solver,collisionConfiguration);
	world->setGravity(btVector3(0,-40,0));

	addPlane(-100,0,0,btVector3(1,0,0));
	addPlane(100,0,0,btVector3(-1,0,0));
  	addPlane(0,-100,0,btVector3(0,1,0));
	addPlane(0,100,0,btVector3(0,-1,0));
	addPlane(0,0,-300,btVector3(0,0,1));
	addPlane(0,0,300,btVector3(0,0,-1));
	
	std::cout << "****************************************************************************************setup complete";
	gContactAddedCallback = callbackFunc;
	return world;
}


void Simulator::deletePhysics(void)
{
	// free all resources
}
btDiscreteDynamicsWorld* Simulator::getWorld(void)
{
	return world;
}
