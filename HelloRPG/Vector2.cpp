#include "Vector2.h"

Vector2 Vector2::zero(0, 0);

Vector2::Vector2(int x, int y) : x(x), y(y)
{

}

int Vector2::GetX()
{
	return x;
}

int Vector2::GetY()
{
	return y;
}

void Vector2::Set(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Vector2::SetX(int newX)
{
	x = newX;
}

void Vector2::SetY(int newY)
{
	y = newY;
}

bool Vector2::IsZero()
{
	return x == 0 && y == 0;
}

Vector2 Vector2::Zero()
{
	return zero;
}

Vector2 Vector2::Normalized(Vector2 vector)
{
	return Vector2(vector.x > 0 ? 1 : vector.x < 0 ? -1 : 0, vector.y > 0 ? 1 : vector.y < 0 ? -1 : 0);
}

int Vector2::Normalized(int x)
{
	return x > 0 ? 1 : x < 0 ? -1 : 0;
}

bool operator == (Vector2& vector1, Vector2& vector2)
{
	return vector1.GetX() == vector2.GetX() && vector1.GetY() == vector2.GetY();
}

bool operator != (Vector2& vector1, Vector2& vector2)
{
	return vector1.GetX() != vector2.GetX() || vector1.GetY() != vector2.GetY();
}