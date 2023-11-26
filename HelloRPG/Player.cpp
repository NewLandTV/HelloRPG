#include <iostream>
#include <cstdio>
#include <cstring>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "System.h"

Player::Player(const char* name, int hp, int damage, Vector2 position, ObjectDirection direction, Object attackObject)
{
	int nameLength = strlen(name) + 1;

	this->name = new char[nameLength];

	strcpy_s(this->name, nameLength, name);

	this->hp = hp;
	this->damage = damage;

	this->position = new Vector2(position.GetX(), position.GetY());

	this->direction = direction;

	this->attackObject = new Object(attackObject.GetName(), attackObject.GetSprite(), *attackObject.GetPosition(), *attackObject.GetScale());
}

void Player::Move(Vector2 direction, int movementBlock, const Object& collisionObject)
{
	if (position->GetY() + 1 != FLOOR_Y && !collisionObject.Collision(Vector2(position->GetX(), position->GetY() + 1)))
	{
		Gotoxy(position->GetX(), position->GetY());

		std::cout << " ";

		position->SetY(position->GetY() + 1);
	}

	this->direction = Vector2::Normalized(direction.GetX()) == -1 ? Left : Vector2::Normalized(direction.GetX()) == 1 ? Right : this->direction;

	for (int i = 0; i < movementBlock; i++)
	{
		if (0 <= position->GetX() + direction.GetX() && position->GetX() + direction.GetX() < CONSOLE_WIDTH && 0 <= position->GetY() + direction.GetY() && position->GetY() + direction.GetY() < CONSOLE_HEIGHT)
		{
			Gotoxy(position->GetX(), position->GetY());

			std::cout << " ";

			position->Set(position->GetX() + direction.GetX(), position->GetY() + direction.GetY());

			Gotoxy(position->GetX(), position->GetY());
			SetColor(9, 11);

			std::cout << "@";
		}
	}
}

void Player::Attack(Enemy* target, Object* object)
{
	int maxDistance = 5;
	int x;

	attackObject->GetPosition()->Set(position->GetX(), position->GetY());
	attackObject->Draw();

	SetColor(9, 6);

	if (direction == Left)
	{
		for (x = 0; x < maxDistance; x++)
		{
			Gotoxy(attackObject->GetPosition()->GetX(), attackObject->GetPosition()->GetY());
			printf(" ");

			if (object->Collision(Vector2(attackObject->GetPosition()->GetX() - 1, attackObject->GetPosition()->GetY())))
			{
				return;
			}

			if (attackObject->Collision(*target->GetPosition()))
			{
				target->SetHp(target->GetHp() - damage);

				return;
			}

			attackObject->GetPosition()->SetX(attackObject->GetPosition()->GetX() - 1);
			attackObject->Draw();

			Sleep(50);
		}
	}
	else
	{
		for (x = 0; x < maxDistance; x++)
		{
			Gotoxy(attackObject->GetPosition()->GetX(), attackObject->GetPosition()->GetY());
			printf(" ");

			if (object->Collision(Vector2(attackObject->GetPosition()->GetX() + 1, attackObject->GetPosition()->GetY())))
			{
				return;
			}

			if (attackObject->Collision(*target->GetPosition()))
			{
				target->SetHp(target->GetHp() - damage);

				return;
			}

			attackObject->GetPosition()->SetX(attackObject->GetPosition()->GetX() + 1);
			attackObject->Draw();

			Sleep(50);
		}
	}
}

void Player::DrawHp()
{
	Gotoxy(2, 1);
	SetColor(9, 12);
	printf("HP : %05d", hp);
}

const char* Player::GetName()
{
	return name;
}

int Player::GetHp()
{
	return hp;
}

int Player::GetDamage()
{
	return damage;
}

int Player::GetCurrentMapId()
{
	return currentMapId;
}

ObjectDirection Player::GetDirection()
{
	return direction;
}

void Player::SetName(const char* newName)
{
	if (name != nullptr)
	{
		delete[]name;
	}

	int nameLength = strlen(newName) + 1;

	name = new char[nameLength];

	strcpy_s(name, nameLength, newName);
}

void Player::SetHp(int newHp)
{
	hp = newHp;
}

void Player::SetDamage(int newDamage)
{
	damage = newDamage;
}

void Player::SetCurrentMapId(int id)
{
	currentMapId = id;
}

void Player::SetDirection(ObjectDirection newDirection)
{
	direction = newDirection;
}

Vector2* Player::GetPosition()
{
	return position;
}

Player::~Player()
{
	if (name != nullptr)
	{
		delete[]name;
	}

	if (position != nullptr)
	{
		delete position;
	}

	if (attackObject != nullptr)
	{
		delete attackObject;
	}
}