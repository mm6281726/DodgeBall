//PlayerManager.cpp
#include <PlayerManager.h>

PlayerManager PlayerManager::PlayerControl;
std::vector<Player*> player_list;
std::vector<Enemy*> enemy_list;

PlayerManager::PlayerManager(){}

void PlayerManager::addPlayer(Player* player){
    player_list.push_back(player);
}

void PlayerManager::addEnemy(Enemy* enemy){
    enemy_list.push_back(enemy);
}

int PlayerManager::player_size(){
    return player_list.size();
}

int PlayerManager::enemy_size(){
    return enemy_list.size();
}

Player* PlayerManager::getPlayer(int i){
	return player_list[i];
}

Enemy* PlayerManager::getEnemy(int i){
    return enemy_list[i];
}

bool PlayerManager::isClosestEnemy(Ogre::Vector3 enemyloc, Ogre::Vector3 ballloc){
    if(enemy_list.size() == 1)
        return true;

    Ogre::Vector3 enemydist = enemyloc - ballloc;
    enemydist.y=0;
    for(int i = 0; i < enemy_list.size(); i++){
	Ogre::Vector3 relLoc=enemy_list[i]->getPosition() - ballloc;
	relLoc.y=0;
        if(enemydist.length() > relLoc.length())
            return false;
    }
    return true;
}

Enemy* PlayerManager::closestEnemy(Ogre::Vector3 loc){
    if(enemy_list.size() == 1)
        return enemy_list[0];
    Enemy* closest=enemy_list[0];
    Ogre::Vector3 enemyloc = enemy_list[0]->getPosition();
    Ogre::Vector3 enemydist = enemyloc - loc;
    enemydist.y=0;
    for(int i = 1; i < enemy_list.size(); i++){
	Ogre::Vector3 relLoc=enemy_list[i]->getPosition() - loc;
	relLoc.y=0;
        if(enemydist.length() > relLoc.length())
	{
            enemydist=relLoc;
	    closest=enemy_list[i];
	}
    }
    return closest;
}


Player* PlayerManager::closestPlayer(Ogre::Vector3 loc){
    if(player_list.size() == 1)
        return player_list[0];
    Player* closest=player_list[0];
    Ogre::Vector3 playerloc = player_list[0]->getPosition();
    Ogre::Vector3 playerdist = playerloc - loc;
    playerdist.y=0;
    for(int i = 1; i < player_list.size(); i++){
	Ogre::Vector3 relLoc=player_list[i]->getPosition() - loc;
	relLoc.y=0;
        if(playerdist.length() > relLoc.length())
	{
            playerdist=relLoc;
	    closest=player_list[i];
	}
    }
    return closest;
}

int PlayerManager::playersLeft()
{
	int total=0;
	for(int i=0;i<player_list.size();i++)
	{
		total+=(int)(player_list[i]->isInPlay()?1:0);
	}
	return total;
}

int PlayerManager::enemiesLeft()
{
	int total=0;
	for(int i=0;i<enemy_list.size();i++)
	{
		total+=(int)(enemy_list[i]->isInPlay()?1:0);
	}
	return total;
}





