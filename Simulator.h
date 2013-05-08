#ifndef __Simulator_h_
#define __Simulator_h_
#include <OgreSceneManager.h>
#include <OgreEntity.h>


#include "btBulletDynamicsCommon.h"


#define BIT(x) (1<<(x))
enum collisiontypes {
	COL_NOTHING = 0, 			//<Collide with nothing
	COL_BALL = BIT(1), 		//<Collide with ball
	COL_WALL = BIT(2), 		//<Collide with walls
	COL_PLAYER = BIT(3),	//<Collide with player
	COL_ENEMY = BIT(4) 		//<Collide with enemy
};

enum objectType {
	BALL = 0,
	WALL = 1,
	PLAYER = 2,
	ENEMY = 3
};

struct bulletObject{
	objectType type;
	int index;
	btRigidBody* body;
	bulletObject(btRigidBody *b, objectType t, int i) : body(b), type(t), index(i){};
};

class Simulator
{
	public:
		Simulator();
		virtual ~Simulator(void);
		btDiscreteDynamicsWorld* setupSimulator(void);
		void deletePhysics(void);
		btRigidBody* addPlane(float x,float y,float z,btVector3 normal);
		btRigidBody* addSphere(float rad,float x,float y,float z,float mass,int index);
		btRigidBody* addCylinder(float d,float h,float x,float y,float z,float mass, bool isPlayer,int index);
		btDiscreteDynamicsWorld* getWorld();
		static Simulator Simulation;
	protected:
		btDiscreteDynamicsWorld* world;
		std::vector<bulletObject*> bodies;

};
#endif // #ifndef __Simulator_h_
