#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
	m_x = x;
	m_y = y;
}

Vector2::Vector2(const Vector2& vector)
{
	m_x = vector.m_x;
	m_y = vector.m_y;
}

int Vector2::getX() const
{
	return m_x;
}

int Vector2::getY() const
{
	return m_y;
}

void Vector2::setX(int x)
{
	m_x = x;
}

void Vector2::setY(int y)
{
	m_y = y;
}

void Vector2::print()
{
	cout << "( " << m_x << " , " << m_y << " )" << endl;
}

