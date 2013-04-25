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
	public:
		Ball(Ogre::SceneManager* sceneMgr, Simulator* s);
		void setPosition(int x, int y, int z);
		void setPosition(const Ogre::Vector3 &  pos);
		Ogre::Vector3 getPosition();
		void translate(const Ogre::Vector3 & d, Ogre::Node::TransformSpace relativeTo = Ogre::Node::TS_PARENT);
		void yaw(Ogre::Degree d);
		btRigidBody* getBody();
		Simulator* simulator;
		void addToBullet(btVector3 dir);
		void removeFromBullet(void);
};

#endif
