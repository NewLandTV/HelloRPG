#ifndef __GAME_H__
#define __GAME_H__

#include <Windows.h>

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 30
#define FLOOR_Y (CONSOLE_HEIGHT - 3)
#define PLAYER_JUMP_FORCE 4
#define MAP_COUNT 3

void Start();
void Update();
void End();
BOOL CtrlHandler(DWORD fdwCtrlType);

#endif