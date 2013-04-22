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

class Player{
	private:
		Ogre::SceneManager* mSceneMgr;
		Ogre::Camera* camPlayer;
		Ogre::Entity* entPlayer;
		Ogre::SceneNode* nodePlayer;

		bool hasBall;
	public:
		Player(Ogre::SceneManager* sceneMgr);
		void move(const Ogre::FrameEvent& evt);
		void startMove(Ogre::String key);
		void stopMove(Ogre::String key);
		void lookAround(const OIS::MouseEvent &arg);
		void pickupBall();
};

#endif