//Enemy.h
#ifndef _ENEMY_H_
    #define _ENEMY_H_

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

#include <Ball.h>
#include <GUIManager.h>

class Enemy{
	private:
		Ogre::SceneManager* mSceneMgr;
		Ogre::Camera* camEnemy;
		Ogre::Entity* entEnemy;
		Ogre::SceneNode* nodeEnemy;
		Ogre::RaySceneQuery* mRayScnQuery;

		Ball* ball;
		bool mHasBall;
		bool mThrowing;
		Ogre::Real mPower;
		bool mRelease;
		bool inPlay;
		btRigidBody* body;
		Ogre::Vector3 spawnPoint;
	public:
		Enemy(Ogre::SceneManager* sceneMgr, int i, int x, int z,int ind);
		Ogre::Vector3 getPosition();
		bool hasBall();
		void pickupBall(Ball* ball);
		void pickupBallPhysics(Ball* baller);
		void beginThrow();
		void chargeThrow();
		void endThrow(Ogre::Vector3 playerloc);
		void extThrow(btVector3 dir, Ogre::Real pow);
		void setRelease(bool b);
		bool isReleasing();
		bool isThrowing();
		void getNearBall(Ball* ball, const Ogre::FrameEvent& evt);
		void getAwayBall(Ball* ball, const Ogre::FrameEvent& evt);
		btVector3 throwDir();
		Ogre::Real throwPower();
		bool isInPlay();
		void setInPlay(bool b);
		void respawn();

};

#endif
