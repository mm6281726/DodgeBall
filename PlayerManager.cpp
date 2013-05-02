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