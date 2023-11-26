#include <iostream>
#include <conio.h>
#include <thread>
#include "Game.h"
#include "System.h"
#include "SaveLoad.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "UIManager.h"
#include "Map.h"

Player* player;
SaveData* saveData;

Map* maps[MAP_COUNT] =
{
	new Map(0, "Ÿġ ��"),
	new Map(1, "��� ���"),
	new Map(2, "�ߴ� ����")
};

Sprite sprite;

void Start()
{
	int i;
	int x;
	int y;
	char* inputName;
	char buffer[20];

	inputName = buffer;

	// Screen initialize
	for (x = 0; x < CONSOLE_WIDTH; x++)
	{
		for (y = 0; y < CONSOLE_HEIGHT; y++)
		{
			Gotoxy(x, y);
			SetColor(3, 14);

			std::cout << " ";
		}
	}

	// UI
	sprite = Sprite(Vector2::Zero(), Vector2(CONSOLE_WIDTH, CONSOLE_HEIGHT), 12, '+');

	saveData = new SaveData();

	saveData->Load();

	// Has data
	if (saveData->GetPlayer() != nullptr && saveData->GetEnemy() != nullptr)
	{
		player = saveData->GetPlayer();

		maps[player->GetCurrentMapId()]->AddObject(new Object("Test Object", '+', Vector2((CONSOLE_WIDTH >> 1) - 7, FLOOR_Y - 6), Vector2(5, 5)));
		maps[player->GetCurrentMapId()]->AddEnemy(saveData->GetEnemy());

		for (i = 0; i < rand() % 3 + 24; i++)
		{
			Gotoxy((CONSOLE_WIDTH >> 1) - 5, 6);

			std::cout << "�ҷ����� ��";

			switch (i % 3)
			{
			case 0:
				std::cout << ".";

				break;
			case 1:
				std::cout << "..";

				break;
			case 2:
				std::cout << "...";

				break;
			}

			Sleep(125);
			system("cls");
		}

		// �̸� �Է��� �ޱ� ���� ȭ�� �׸���
		for (x = 0; x < CONSOLE_WIDTH; x++)
		{
			for (y = 0; y < CONSOLE_HEIGHT; y++)
			{
				Gotoxy(x, y);
				SetColor(9, 7);

				std::cout << " ";
			}
		}

		switch (player->GetCurrentMapId())
		{
		case 0:
			maps[0]->GetMapObject("Test Object")->Draw();

			break;
		case 1:

			break;
		case 2:

			break;
		}

		maps[player->GetCurrentMapId()]->ShowMapName();

		return;
	}

	SetCursorVisible(1);

	std::cout << "��ſ� �̸���? ";
	std::cin >> inputName;

	SetCursorVisible(0);

	if (inputName != nullptr)
	{
		player = new Player(inputName, 100, 5, Vector2(CONSOLE_WIDTH >> 1, FLOOR_Y - 1), Left, Object("Player Attack Object", '%', Vector2(CONSOLE_WIDTH >> 1, FLOOR_Y - 1), Vector2(1, 1)));
	}

	system("cls");

	std::cout << player->GetName() << "�� Hello RPG ���迡 ���� ���� ȯ���մϴ�.";

	_getch();
	system("cls");

	std::cout << "W, DŰ�� �¿� �̵���,";

	_getch();
	system("cls");

	std::cout << "SpaceŰ�� ������ �� �� �ֽ��ϴ�.";

	_getch();
	system("cls");

	std::cout << "�ϴ� ���踦 �����Ӱ� �����̸鼭 ������!";

	_getch();
	system("cls");

	for (i = 0; i < CONSOLE_WIDTH; i++)
	{
		Gotoxy(i, FLOOR_Y);

		std::cout << "#";
	}

	// ���� ó�� ���� �� �� ���̵� ����
	player->SetCurrentMapId(0);

	maps[player->GetCurrentMapId()]->AddObject(new Object("Test Object", '+', Vector2((CONSOLE_WIDTH >> 1) - 7, FLOOR_Y - 6), Vector2(5, 5)));
	maps[player->GetCurrentMapId()]->AddEnemy(new Enemy("Enemy 1", '!', Vector2((CONSOLE_WIDTH >> 1) + 12, FLOOR_Y - 1), Vector2(1, 1), 10, player->GetPosition(), 4, 200));

	maps[player->GetCurrentMapId()]->GetMapObject("Test Object")->Draw();

	maps[player->GetCurrentMapId()]->ShowMapName();
}

void Update()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		End();
	}

	int i;
	int x = 0;
	int y = 0;

	// T, t
	if (GetAsyncKeyState(84) & 0x0001 || GetAsyncKeyState(116) & 0x0001)
	{
		if (!UIManager::GetOnUI())
		{
			UIManager::SetOnUI(!UIManager::GetOnUI());

			if (!UIManager::GetOnUI())
			{
				sprite.Draw();
			}
			else
			{
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

				maps[player->GetCurrentMapId()]->GetMapObject("Test Object")->Draw();
			}
		}
	}

	if (UIManager::GetOnUI())
	{
		// P, p
		if (GetAsyncKeyState(80) & 0x0001 || GetAsyncKeyState(112) & 0x0001)
		{
			player->Attack(maps[player->GetCurrentMapId()]->GetMapEnemy("Enemy 1"), maps[player->GetCurrentMapId()]->GetMapObject("Test Object"));
		}
		// D, d
		if (GetAsyncKeyState(68) || GetAsyncKeyState(100))
		{
			x = 1;
		}
		// A, a
		if (GetAsyncKeyState(65) || GetAsyncKeyState(97))
		{
			x = -1;
		}
		// Spacebar
		if (GetAsyncKeyState(32) & 0x0001 && player->GetPosition()->GetY() == FLOOR_Y - 1)
		{
			y = -PLAYER_JUMP_FORCE;
		}

		player->DrawHp();

		if (!maps[player->GetCurrentMapId()]->GetMapObject("Test Object")->Collision(Vector2(player->GetPosition()->GetX() + x, player->GetPosition()->GetY() + y)))
		{
			player->Move(Vector2(x, y), 1, *maps[player->GetCurrentMapId()]->GetMapObject("Test Object"));
		}
		else
		{
			player->Move(Vector2::Zero(), 1, *maps[player->GetCurrentMapId()]->GetMapObject("Test Object"));
		}

		if (!maps[player->GetCurrentMapId()]->GetMapEnemy("Enemy 1")->CheckHp())
		{
			maps[player->GetCurrentMapId()]->GetMapEnemy("Enemy 1")->SetTarget(player->GetPosition());
			maps[player->GetCurrentMapId()]->GetMapEnemy("Enemy 1")->Move(player, 5, *maps[player->GetCurrentMapId()]->GetMapObject("Test Object"));
			maps[player->GetCurrentMapId()]->GetMapEnemy("Enemy 1")->Draw();
			maps[player->GetCurrentMapId()]->GetMapEnemy("Enemy 1")->Attack(player);
		}
	}
	
	Sleep(30);
}

void End()
{
	int i;

	// Save
	saveData->SetPlayer(player);
	saveData->SetEnemy(maps[player->GetCurrentMapId()]->GetMapEnemy("Enemy 1"));
	saveData->Save();

	delete player;
	delete saveData;

	// Delete map objects
	for (i = 0; i < MAP_COUNT; i++)
	{
		delete maps[i];
	}

	system("cls");
	Gotoxy((CONSOLE_WIDTH >> 1) - 11, 6);

	std::cout << "������ ����Ǿ����ϴ�.";

	exit(0);
}

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
	case CTRL_BREAK_EVENT:
	default:
		End();
	}

	return FALSE;
}