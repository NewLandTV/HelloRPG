#ifndef __SAVELOAD_H__
#define __SAVELOAD_H__

#include "Player.h"
#include "Enemy.h"

class SaveData
{
private:
	Player* player;
	Enemy* enemy;

public:
	~SaveData();
	void Save();
	void Load();
	Player* GetPlayer();
	Enemy* GetEnemy();
	void SetPlayer(Player* player);
	void SetEnemy(Enemy* enemy);
};

#endif