//PlayerManager.cpp
#include <PlayerManager.h>
#include <sstream>



PlayerManager::PlayerManager(){
}

Player* PlayerManager::getPlayer(int x){
	return players[x];
}

Player* PlayerManager::getPlayer(char* str){
	return players[0];//fix, obviously
}

/*  std::stringstream ss (std::stringstream::in | std::stringstream::out);
    ss << camPlayer->getDerivedDirection().x;
        std::cout<<"throw dir: x="+ss.str();
        ss.str(std::string());
        ss << camPlayer->getDerivedDirection().y;
        std::cout<<" y="+ss.str();
        ss.str(std::string());
        ss << camPlayer->getDerivedDirection().z;
        std::cout<<" z="+ss.str()+"\n";*/
