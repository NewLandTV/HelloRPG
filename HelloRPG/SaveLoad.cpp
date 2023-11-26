#include <iostream>
#include <cstring>
#include <string>
#include "SaveLoad.h"
#include "Game.h"

SaveData::~SaveData()
{
	if (player != nullptr)
	{
		delete player;
	}

	if (enemy != nullptr)
	{
		delete enemy;
	}
}

void SaveData::Save()
{
	FILE* wfp;

	fopen_s(&wfp, "C:/NewLand/HelloRPG/data.hellorpg", "w");

	if (wfp != nullptr)
	{
		fprintf(wfp, "%s|", player->GetName());
		fprintf(wfp, "%d|", player->GetPosition()->GetX());
		fprintf(wfp, "%d|", player->GetPosition()->GetY());
		fprintf(wfp, "%d|", player->GetHp());
		fprintf(wfp, "%d|", player->GetDamage());
		fprintf(wfp, "%d|", (int)player->GetDirection());
		fprintf(wfp, "%c|", enemy->GetSprite());
		fprintf(wfp, "%d|", enemy->GetPosition()->GetX());
		fprintf(wfp, "%d|", enemy->GetPosition()->GetY());
		fprintf(wfp, "%d|", enemy->GetScale()->GetX());
		fprintf(wfp, "%d|", enemy->GetScale()->GetY());
		fprintf(wfp, "%d|", enemy->GetHp());
		fprintf(wfp, "%d|", enemy->GetDamage());
		fprintf(wfp, "%d", enemy->GetAttackDelay());
		fclose(wfp);
	}
}

void SaveData::Load()
{
	FILE* rfp;

	int i = 0;
	char buffer[256];
	char* next;
	char* context = nullptr;

	fopen_s(&rfp, "C:/NewLand/HelloRPG/data.hellorpg", "r");

	if (rfp == nullptr)
	{
		return;
	}

	player = new Player("", 0, 0, Vector2::Zero(), Left, Object("", '%', Vector2::Zero(), Vector2(1, 1)));
	enemy = new Enemy("", ' ', Vector2::Zero(), Vector2::Zero(), 0, nullptr, 0, 0);

	fgets(buffer, 256, rfp);

	next = strtok_s(buffer, "|", &context);

	player->SetName(next);

	next = strtok_s(nullptr, "|", &context);

	player->GetPosition()->SetX(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	player->GetPosition()->SetY(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	player->SetHp(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	player->SetDamage(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	player->SetDirection((ObjectDirection)std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	enemy->SetSprite(next[0]);

	next = strtok_s(nullptr, "|", &context);

	enemy->GetPosition()->SetX(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	enemy->GetPosition()->SetY(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	enemy->GetScale()->SetX(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	enemy->GetScale()->SetY(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	enemy->SetHp(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	enemy->SetDamage(std::stoi(next));

	next = strtok_s(nullptr, "|", &context);

	enemy->SetAttackDelay(std::stoi(next));

	fclose(rfp);
}

Player* SaveData::GetPlayer()
{
	return player;
}

Enemy* SaveData::GetEnemy()
{
	return enemy;
}

void SaveData::SetPlayer(Player* player)
{
	this->player = player;
}

void SaveData::SetEnemy(Enemy* enemy)
{
	this->enemy = enemy;
}