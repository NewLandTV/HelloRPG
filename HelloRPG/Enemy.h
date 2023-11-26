#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Vector2.h"
#include "Object.h"
#include "Player.h"

class Enemy : public Object
{
private:
	int hp;
	Vector2* targetPosition;
	int damage;
	int attackDelay;

public:
	Enemy(const char* name, const char sprite, Vector2 position, Vector2 scale, int hp, Vector2* targetPosition, int damage, int attackDelay);
	void Move(Player* player, int speed, const Object& collisionObject);
	void Attack(Player* player);
	bool CheckHp();
	int GetHp();
	Vector2* GetTarget();
	int GetDamage();
	int GetAttackDelay();
	void SetHp(int newHp);
	void SetTarget(Vector2* newTargetPosition);
	void SetDamage(int newDamage);
	void SetAttackDelay(int newAttackDelay);
};

#endif