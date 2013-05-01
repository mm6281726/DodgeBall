//Player.h
#ifndef _PLAYER_H_
    #define _PLAYER_H_

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

class Player{
	private:
		Ogre::SceneManager* mSceneMgr;
		Ogre::Camera* camPlayer;
		Ogre::Entity* entPlayer;
		Ogre::SceneNode* nodePlayer;
		Ogre::RaySceneQuery* mRayScnQuery;

		Ball* ball;
		bool mHasBall;
		bool mThrowing;
		Ogre::Real mPower;
		bool mRelease;
		bool isEnemy;
	public:
		Player(Ogre::SceneManager* sceneMgr, int x, int z, bool enemy);
		void move(const Ogre::FrameEvent& evt);
		void startMove(Ogre::String key);
		void stopMove(Ogre::String key);
		void lookAround(const OIS::MouseEvent &arg);
		bool hasBall();
		void pickupBall(Ball* ball);
		void beginThrow();
		void chargeThrow();
		void endThrow();
		void extThrow(btVector3 dir, Ogre::Real pow);
		void setRelease(bool b);
		bool isReleasing();
		bool isThrowing();
		void getNearBall(Ball* ball, const Ogre::FrameEvent& evt);
		btVector3 throwDir();
		Ogre::Real throwPower();

};

#endif
