#include "UIManager.h"

// UIManager class

bool UIManager::onUI = false;

// Constructor and destructor
UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

// Sprite class

// Constructor and destructor
Sprite::Sprite() : position(0, 0), scale(0, 0), color(0), source(' ')
{

}

Sprite::Sprite(Vector2 position) : position(position), scale(0, 0), color(0), source(' ')
{

}

Sprite::Sprite(Vector2 position, Vector2 scale) : position(position), scale(scale), color(0), source(' ')
{

}

Sprite::Sprite(Vector2 position, Vector2 scale, int color) : position(position), scale(scale), color(color), source(' ')
{

}

Sprite::Sprite(Vector2 position, Vector2 scale, int color, char source) : position(position), scale(scale), color(color), source(source)
{

}

// Method
void Sprite::Draw()
{
	int x;
	int y;

	for (y = 0; y < scale.GetY(); y++)
	{
		for (x = 0; x < scale.GetX(); x++)
		{
			Gotoxy(position.GetX() + x, position.GetY() + y);
			SetColor(15, color);

			std::cout << source;
		}
	}
}

// Text class

// Constructor and destructor
Text::Text() : position(0, 0), content(0)
{

}

Text::Text(Vector2 position) : position(position), content(0)
{

}

Text::Text(Vector2 position, const char* content) : position(position)
{
	int contentLength = strlen(content) + 1;

	this->content = new char[contentLength];

	strcpy_s(this->content, contentLength, content);
}

// Method
void Text::Draw()
{
	Gotoxy(position.GetX(), position.GetY());

	std::cout << content;
}