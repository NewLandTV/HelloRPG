/*
 * Project Name : Hello RPG
 * Project Version : 0.8.0
 * Made By JkhTV
 */

#include "System.h"
#include "Game.h"

int main(void)
{
	Init();
	Start();

	while (1)
	{
		Update();
	}

	return 0;
}