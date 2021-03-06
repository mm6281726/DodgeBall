//Ball.h
#ifndef _BALL_H_
#define _BALL_H_

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <Simulator.h>

class Ball{
	private:
		Ogre::SceneManager* mSceneMgr;
		Ogre::Entity* entBall;
		Ogre::SceneNode* nodeBall;
		btRigidBody* physicsBall;
		int dangerous;
		Ogre::Vector3 spawnPoint;
		bool mThrownByEnemy;
		bool mIsPickedUp;
	public:
		Ball(Ogre::SceneManager* sceneMgr, Simulator* s, Ogre::String name, int x,int ind);
		void gotPickedUp();
		void gotThrown();
		bool isPickedUp();
		void setPosition(int x, int y, int z);
		void setPosition(const Ogre::Vector3 &  pos);
		Ogre::Vector3 getPosition();
		void translate(const Ogre::Vector3 & d, Ogre::Node::TransformSpace relativeTo = Ogre::Node::TS_PARENT);
		void yaw(Ogre::Degree d);
		btRigidBody* getBody();
		Simulator* simulator;
		void addToBullet(btVector3 dir, Ogre::Real power);
		void removeFromBullet(void);
		int numBounces(void);
		bool bounceCheck(void);
		void setDanger(int dan);
		int isDangerous(void);
		bool towardsPos(Ogre::Vector3 pos);
		void thrownBy(bool thrownByEnemy);
		bool thrownBy();
		void respawn();
};

#endif
