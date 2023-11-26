#ifndef __VECTOR2_H__
#define __VECTOR2_H__

class Vector2
{
private:
	static Vector2 zero;
	int x;
	int y;

public:
	Vector2(int x, int y);
	int GetX();
	int GetY();
	void Set(int newX, int newY);
	void SetX(int newX);
	void SetY(int newY);
	bool IsZero();
	static Vector2 Zero();
	static Vector2 Normalized(Vector2 vector);
	static int Normalized(int x);
	friend bool operator == (Vector2& vector1, Vector2& vector2);
	friend bool operator != (Vector2& vector1, Vector2& vector2);
};

#endif