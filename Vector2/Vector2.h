#ifndef Vector2_H
#define Vector2_H

#include <iostream>
using namespace std;

class Vector2
{
public:
	Vector2(int x = 0, int y = 0);
	Vector2(const Vector2& vector);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void print();
private:
	int m_x;
	int m_y;
};

#endif