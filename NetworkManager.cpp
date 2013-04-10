//NetworkManager.cpp
#include "NetworkManager.h"

NetworkManager NetworkManager::NetworkControl;
bool globalQuit = false;
bool server = false;
TCPsocket targetSocket;

NetworkManager::NetworkManager(){}

void NetworkManager::NetworkHost(void)      //http://content.gpwiki.org/index.php/SDL:Tutorial:Using_SDL_net <- good code here, adapt messages accordingly
{                           //http://jcatki.no-ip.org:8080/SDL_net/SDL_net.html <- good documentation here
  TCPsocket sd;      /* Call this function once Host button is selected */
  IPaddress ip;
  char buffer[512];
  server = true;
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Resolving the host using NULL make network interface to listen */
	if (SDLNet_ResolveHost(&ip, NULL, 2000) < 0)
	{
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Open a connection with the IP provided (listen on the host's port) */
	if (!(sd = SDLNet_TCP_Open(&ip)))
	{
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Wait for a connection*/
	while (!(targetSocket = SDLNet_TCP_Accept(sd)))
	{
		
	}
	std::cout<<"accepted client";
 
}
void NetworkManager::NetworkClient(char* str)    //http://content.gpwiki.org/index.php/SDL:Tutorial:Using_SDL_net <- good code here, adapt messages accordingly
{                           //http://jcatki.no-ip.org:8080/SDL_net/SDL_net.html <- good documentation here
	IPaddress ip;           /* Call this function once client is selected (after accepting a host if that is possible via GUI) */         
	int len;
	char buffer[512];
	server = false;
	host=str;							//If a GUI - entered host name is possible, add it to the function arguments and set this to it.
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Resolve the host we are connecting to */
	if (SDLNet_ResolveHost(&ip, host, 2000) < 0)
	{
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Open a connection with the IP provided (listen on the host's port) */
	if (!(targetSocket = SDLNet_TCP_Open(&ip)))
	{
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
}

void NetworkManager::NetworkCommunicator()    //make it receive paddlemanagers and ballmanagers to change positions into messages (break up server messages since it'll send ball and paddle to network... easy to write, not to read)
{                           //call this from game loop
	int len;				//	commented out code should be correct (I can't check it yet though) once networking works right
	char buffer[512];	
	//
	char str[512];
	if(!server)
	{
		//strcpy(buffer,NetworkManager::Vector3ToString(clientPaddle->getPosition()));
		len = strlen(buffer) + 1;
		if (SDLNet_TCP_Send(targetSocket, (void *)buffer, len) < len)
		{
			fprintf(stderr, "SDLNet_TCP_Send: %s\n", SDLNet_GetError());
			exit(EXIT_FAILURE);
		}
		if (SDLNet_TCP_Recv(targetSocket, buffer, 512) > 0)
		{
			std::string decode = std::string(buffer);
			unsigned found = decode.find_first_of("&");
			Ogre::Vector3 v = NetworkManager::StringToVector3(buffer,0);
			//hostPaddle->setPosition(v);
			v = NetworkManager::StringToVector3(buffer,found+1);
			//ball->setPosition(v);
			printf("Host say: %s\n", buffer);
		
		}
	}
	else
	{

		if (SDLNet_TCP_Recv(targetSocket, buffer, 512) > 0)
		{
			Ogre::Vector3 v = NetworkManager::StringToVector3(buffer,0);
			//clientPaddle->setPosition(v);
			printf("Client say: %s\n", buffer);
		}
		//strcpy(str, NetworkManager::Vector3ToString(hostPaddle->getPosition()));
		strcat(str, " ");
		//strcat(str, NetworkManager::Vector3ToString(ball->getPosition()));
		strcpy(buffer,str);
		//strcpy(buffer,"test reply");
		int len = strlen(buffer) + 1;
		if (SDLNet_TCP_Send(targetSocket, (void *)buffer, len) < len)
		{
			fprintf(stderr, "SDLNet_TCP_Send: %s\n", SDLNet_GetError());
			exit(EXIT_FAILURE);
		}
	}
}

char* NetworkManager::Vector3ToString(Ogre::Vector3 vic)		//formatting: &x,y,z#
{
	std::stringstream ss (std::stringstream::in | std::stringstream::out);
	std::string result="&";
	ss << vic.x;
	result+=ss.str()+",";
	ss.str(std::string());
	ss << vic.y;
	result+=ss.str()+",";
	ss.str(std::string());
	ss << vic.z;
	result+=ss.str()+"#";
	char* finn = new char [result.length()+1];
  	std::strcpy (finn, result.c_str());
	return finn;
}

Ogre::Vector3 NetworkManager::StringToVector3(char* str, int i)		//formatting: &x,y,z#
{								//Note: only converts one string to one Ogre::Vector3
	std::string decode = std::string(str);
	unsigned found = decode.find_first_of("&",i);
	Ogre::Vector3 result = Ogre::Vector3(0,0,0);
	if (found!=std::string::npos)
	{
		int index=found+1;
		unsigned comma = decode.find_first_of(",#",index+1);
		result.x=atof(decode.substr(index,comma-index).c_str());
		index=comma+1;
		comma = decode.find_first_of(",#",index+1);
		result.y=atof(decode.substr(index,comma-index).c_str());
		index=comma+1;
		comma = decode.find_first_of(",#",index+1);
		result.z=atof(decode.substr(index,comma-index).c_str());
		index=comma+1;
		comma = decode.find_first_of(",#",index+1);
	}
	return result;
}

void NetworkManager::Quit(void)
{
	globalQuit = true;
	SDLNet_TCP_Close(targetSocket);
	SDLNet_Quit();	
}

bool NetworkManager::IsHost(void)
{
	return server;
}

void NetworkManager::SetHost(bool b)
{
	server = b;
}

