//PlayerManager.h
#ifndef _PLAYERMANAGER_H_
    #define _PLAYERMANAGER_H_

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
#include "Player.h"
#include <GUIManager.h>

class PlayerManager{
	private:
		std::vector<Player*> players;

	public:
		PlayerManager();
		Player* getPlayer(int x);
		Player* getPlayer(char* str);

};

#endif
