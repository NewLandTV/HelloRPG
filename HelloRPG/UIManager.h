#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include <iostream>
#include "System.h"
#include "Vector2.h"

class UIManager
{
private:
	// true이면 게임 렌더링을 정지하고 UI를 그림
	static bool onUI;

public:
	// Constructor and destructor
	UIManager();
	~UIManager();

	// Method
	static bool GetOnUI() { return onUI; }
	static void SetOnUI(bool value) { onUI = value; }
};

class Sprite
{
private:
	Vector2 position;
	Vector2 scale;
	int color;
	char source;

public:
	// Constructor and destructor
	Sprite();
	Sprite(Vector2 position);
	Sprite(Vector2 position, Vector2 scale);
	Sprite(Vector2 position, Vector2 scale, int color);
	Sprite(Vector2 position, Vector2 scale, int color, char source);

	// Method
	Vector2* GetPositionAddress() { return &position; }
	Vector2* GetScaleAddress() { return &scale; }
	int* GetColorAddress() { return &color; }

	void Draw();
};

class Text
{
private:
	Vector2 position;
	char* content;

public:
	// Constructor and destructor
	Text();
	Text(Vector2 position);
	Text(Vector2 position, const char* content);

	// Method
	Vector2* GetPositionAddress() { return &position; }
	const char* GetContent() { return content; }

	void Draw();
};

#endif