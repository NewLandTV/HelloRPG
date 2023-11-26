#include <iostream>
#include <cstring>
#include "Object.h"
#include "System.h"

Object::Object(const char* name, char sprite, Vector2 position, Vector2 scale)
{
	int nameLength = strlen(name) + 1;

	this->name = new char[nameLength];

	strcpy_s(this->name, nameLength, name);

	this->sprite = sprite;
	this->position = new Vector2(position.GetX(), position.GetY());
	this->scale = new Vector2(scale.GetX(), scale.GetY());
}

const char* Object::GetName()
{
	return name;
}

const char Object::GetSprite()
{
	return sprite;
}

Vector2* Object::GetPosition()
{
	return position;
}

Vector2* Object::GetScale()
{
	return scale;
}

void Object::SetName(const char* name)
{
	if (name != nullptr)
	{
		delete[] name;
	}

	int nameLength = strlen(name) + 1;

	this->name = new char[nameLength];

	strcpy_s(this->name, nameLength, name);
}

void Object::SetSprite(const char newSprite)
{
	sprite = newSprite;
}

int Object::Collision(Vector2 target) const
{
	int x;
	int y;

	for (x = 0; x < scale->GetX(); x++)
	{
		for (y = 0; y < scale->GetX(); y++)
		{
			if (position->GetX() + x == target.GetX() && position->GetY() + y == target.GetY())
			{
				return 1;
			}
		}
	}

	return 0;
}

void Object::Draw()
{
	int x;
	int y;

	for (x = position->GetX(); x < position->GetX() + scale->GetX(); x++)
	{
		for (y = position->GetY(); y < position->GetY() + scale->GetY(); y++)
		{
			Gotoxy(x, y);

			std::cout << sprite;
		}
	}
}

Object::~Object()
{
	if (name != nullptr)
	{
		delete[] name;
	}

	if (position != nullptr)
	{
		delete position;
	}

	if (scale != nullptr)
	{
		delete scale;
	}
}