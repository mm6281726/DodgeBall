//NetworkManager.h

#ifndef _NETWORKMANAGER_H_
    #define _NETWORKMANAGER_H_

#include "SDL_net.h"
#include <sstream>
#include <string>
#include <OgreEntity.h>

class NetworkManager{
	public:
		NetworkManager();
		void NetworkHost(void);
		void NetworkClient(char* str);
		void Quit(void);
		void NetworkCommunicator();
		static char* Vector3ToString(Ogre::Vector3 vic);
		static Ogre::Vector3 StringToVector3(char* str, int i);
		bool IsHost(void);
		void SetHost(bool b);
		static NetworkManager NetworkControl;
		char* host;

	private:
		bool globalQuit;
		bool server;
		TCPsocket targetSocket;
};

#endif
