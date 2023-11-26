#include <cstring>
#include "Map.h"
#include "Game.h"

Map::Map(int id, const char* name)
{
	this->id = id;

	int nameLength = strlen(name) + 1;

	this->name = new char[nameLength];

	strcpy_s(this->name, nameLength, name);

	showMapNameSprite = Sprite(Vector2::Zero(), Vector2(CONSOLE_WIDTH, CONSOLE_HEIGHT), 3, '/');
	showMapNameText = Text(Vector2((CONSOLE_WIDTH >> 1) - (strlen(name) >> 1), CONSOLE_HEIGHT >> 1), name);
}

Map::~Map()
{
	if (name != nullptr)
	{
		delete[] name;
	}

	if (!objects.empty())
	{
		for (auto obj : objects)
		{
			delete obj;
		}
	}

	if (!enemies.empty())
	{
		for (auto enemy : enemies)
		{
			delete enemy;
		}
	}
}

void Map::ShowMapName()
{
	int i;
	int x;
	int y;

	if (UIManager::GetOnUI())
	{
		return;
	}

	UIManager::SetOnUI(true);

	showMapNameSprite.Draw();
	showMapNameText.Draw();

	Sleep(5000);

	UIManager::SetOnUI(false);

	system("cls");

	for (x = 0; x < CONSOLE_WIDTH; x++)
	{
		for (y = 0; y < CONSOLE_HEIGHT; y++)
		{
			Gotoxy(x, y);
			SetColor(9, 7);

			std::cout << " ";
		}
	}

	for (i = 0; i < CONSOLE_WIDTH; i++)
	{
		Gotoxy(i, FLOOR_Y);

		std::cout << "#";
	}

	for (auto obj : objects)
	{
		obj->Draw();
	}

	for (auto enemy : enemies)
	{
		enemy->Draw();
	}
}

void Map::AddObject(Object* object)
{
	objects.push_back(object);
}

void Map::AddEnemy(Enemy* enemy)
{
	enemies.push_back(enemy);
}

void Map::RemoveObject(int index)
{
	objects.erase(objects.begin() + index);
}

void Map::RemoveEnemy(int index)
{
	enemies.erase(enemies.begin() + index);
}

Object* Map::GetMapObject(const char* name)
{
	for (auto obj : objects)
	{
		if (strcmp(obj->GetName(), name) == 0)
		{
			return obj;
		}
	}
}

Enemy* Map::GetMapEnemy(const char* name)
{
	for (auto enemy : enemies)
	{
		if (strcmp(enemy->GetName(), name) == 0)
		{
			return enemy;
		}
	}
}