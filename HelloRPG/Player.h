#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Vector2.h"
#include "Object.h"

class Enemy;

class Player
{
private:
	char* name;
	int hp;
	int damage;
	int currentMapId;
	Vector2* position;
	ObjectDirection direction;
	Object* attackObject;

public:
	Player(const char* name, int hp, int damage, Vector2 position, ObjectDirection direction, Object attackObject);
	void Move(Vector2 direction, int movementBlock, const Object& collisionObject);
	void Attack(Enemy* target, Object* object);
	void DrawHp();
	const char* GetName();
	int GetHp();
	int GetDamage();
	int GetCurrentMapId();
	ObjectDirection GetDirection();
	void SetName(const char* newName);
	void SetHp(int newHp);
	void SetDamage(int newDamage);
	void SetCurrentMapId(int id);
	void SetDirection(ObjectDirection newDirection);
	Vector2* GetPosition();
	~Player();
};

#endif