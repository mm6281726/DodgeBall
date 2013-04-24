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

class Ball{
	private:
		Ogre::SceneManager* mSceneMgr;
		Ogre::Entity* entBall;
		Ogre::SceneNode* nodeBall;
	public:
		Ball(Ogre::SceneManager* sceneMgr);
		Ogre::Vector3 getPosition();
		void setPosition(int x, int y, int z);
		void translate(const Ogre::Vector3 & d, Ogre::Node::TransformSpace relativeTo = Ogre::Node::TS_PARENT);
};

#endif