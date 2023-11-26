#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Object.h"
#include "Enemy.h"
#include "UIManager.h"

class Map
{
private:
	int id;
	char* name;

	std::vector<Object*> objects;
	std::vector<Enemy*> enemies;

	Sprite showMapNameSprite;
	Text showMapNameText;

public:
	// Constructor and destructor
	Map(int id, const char* name);
	~Map();

	void ShowMapName();

	// 맵에 오브젝트나 몬스터 추가, 제거
	void AddObject(Object* object);
	void AddEnemy(Enemy* enemy);
	void RemoveObject(int index);
	void RemoveEnemy(int index);

	// 맵에 있는 오브젝트나 몬스터 찾기
	Object* GetMapObject(const char* name);
	Enemy* GetMapEnemy(const char* name);
};

#endif