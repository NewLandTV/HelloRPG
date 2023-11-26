#include <iostream>
#include <cstring>
#include "Enemy.h"
#include "Game.h"
#include "System.h"

Enemy::Enemy(const char* name, const char sprite, Vector2 position, Vector2 scale, int hp, Vector2* targetPosition, int damage, int attackDelay) : Object(name, sprite, position, scale)
{
	this->hp = hp;
	this->targetPosition = targetPosition;
	this->damage = damage;
	this->attackDelay = attackDelay;
}

void Enemy::Move(Player* player, int speed, const Object& collisionObject)
{
	if (GetPosition()->GetY() + 1 != FLOOR_Y && !collisionObject.Collision(Vector2(GetPosition()->GetX(), GetPosition()->GetY() + 1)))
	{
		Gotoxy(GetPosition()->GetX(), GetPosition()->GetY());

		std::cout << " ";

		GetPosition()->SetY(GetPosition()->GetY() + 1);
	}

	static int waitCount;

	waitCount++;

	if (waitCount > speed)
	{
		waitCount = 0;

		Vector2 direction = Vector2(Vector2::Normalized(targetPosition->GetX() - GetPosition()->GetX()), 0);

		if (targetPosition != nullptr)
		{
			if (0 <= GetPosition()->GetX() + direction.GetX() && GetPosition()->GetX() + direction.GetX() < CONSOLE_WIDTH && 0 <= GetPosition()->GetY() + direction.GetY() && GetPosition()->GetY() + direction.GetY() < CONSOLE_HEIGHT)
			{
				Gotoxy(GetPosition()->GetX(), GetPosition()->GetY());

				std::cout << " ";

				GetPosition()->Set(GetPosition()->GetX() + direction.GetX(), GetPosition()->GetY() + direction.GetY());

				Gotoxy(GetPosition()->GetX(), GetPosition()->GetY());
				SetColor(9, 11);

				std::cout << "!";
			}
		}
	}
}

void Enemy::Attack(Player* player)
{
	static int waitCount;

	waitCount++;

	if (waitCount > attackDelay && targetPosition != nullptr && targetPosition->GetX() == GetPosition()->GetX() && targetPosition->GetY() == GetPosition()->GetY())
	{
		waitCount = 0;

		player->SetHp(player->GetHp() - damage);
	}
}

bool Enemy::CheckHp()
{
	if (hp <= 0)
	{
		targetPosition = nullptr;

		Gotoxy(GetPosition()->GetX(), GetPosition()->GetY());
		SetColor(9, 12);
		printf("%c", GetSprite());

		return true;
	}

	return false;
}

int Enemy::GetHp()
{
	return hp;
}

Vector2* Enemy::GetTarget()
{
	return targetPosition;
}

int Enemy::GetDamage()
{
	return damage;
}

int Enemy::GetAttackDelay()
{
	return attackDelay;
}

void Enemy::SetHp(int newHp)
{
	hp = newHp;
}

void Enemy::SetTarget(Vector2* newTargetPosition)
{
	targetPosition = newTargetPosition;
}

void Enemy::SetDamage(int newDamage)
{
	damage = newDamage;
}

void Enemy::SetAttackDelay(int newAttackDelay)
{
	attackDelay = newAttackDelay;
}