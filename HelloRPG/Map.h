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

	// �ʿ� ������Ʈ�� ���� �߰�, ����
	void AddObject(Object* object);
	void AddEnemy(Enemy* enemy);
	void RemoveObject(int index);
	void RemoveEnemy(int index);

	// �ʿ� �ִ� ������Ʈ�� ���� ã��
	Object* GetMapObject(const char* name);
	Enemy* GetMapEnemy(const char* name);
};

#endif