#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Vector2.h"

typedef enum _ObjectDirection
{
	Left,
	Right
} ObjectDirection;

class Object
{
private:
	char* name;
	char sprite;
	Vector2* position;
	Vector2* scale;

public:
	Object(const char* name, char sprite, Vector2 position, Vector2 scale);
	const char* GetName();
	const char GetSprite();
	Vector2* GetPosition();
	Vector2* GetScale();
	void SetName(const char* name);
	void SetSprite(const char newSprite);
	int Collision(Vector2 target) const;
	void Draw();
	virtual ~Object();
};

#endif