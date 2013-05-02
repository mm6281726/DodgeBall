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
    for(int i = 0; i < enemy_list.size(); i++){
        if(enemydist.x > (enemy_list[i]->getPosition() - ballloc).x || enemydist.z > (enemy_list[i]->getPosition() - ballloc).z)
            return false;
    }
    return true;
}