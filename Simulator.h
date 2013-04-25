#ifndef __Simulator_h_
#define __Simulator_h_
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include "btBulletDynamicsCommon.h"

class Simulator
{
	public:
		Simulator();
		virtual ~Simulator(void);
		bool updatePaddle(Ogre::Vector3 location);
		btDiscreteDynamicsWorld* setupSimulator(void);
		void deletePhysics(void);
		void runSimulator(bool sim);
		btVector3 getBallLocation(void);
		void handleCollisions(void);
		btRigidBody* addPlane(float x,float y,float z,btVector3 normal);
		btRigidBody* addSphere(float rad,float x,float y,float z,float mass);
		btDiscreteDynamicsWorld* getWorld();
	protected:
		btVector3 paddleLocation;
		btRigidBody* ballBody;
		btRigidBody* paddleBody;
		bool simulate;
		btDiscreteDynamicsWorld* world;
		std::vector<btRigidBody*> bodies;

};
#endif // #ifndef __Simulator_h_
