//PlayerManager.h
#ifndef _PLAYERMANAGER_H_
    #define _PLAYERMANAGER_H_

#include <Player.h>
#include <Enemy.h>

class PlayerManager{
	private:
		std::vector<Player*> player_list;
		std::vector<Enemy*> enemy_list;

	public:
		PlayerManager();
		void addPlayer(Player* player);
		void addEnemy(Enemy* enemy);
		int player_size();
		int enemy_size();
		Player* getPlayer(int i);
		Enemy* getEnemy(int i);

		static PlayerManager PlayerControl;
};

#endif
