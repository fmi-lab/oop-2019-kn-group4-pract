#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Point
{
	double x;
	double y;
public:
	Point()
	{
		this->x = 0;
		this->y = 0;
	}
	Point(double _x, double _y)
	{
		this->x = _x;
		this->y = _y;
	}
	double getX() const
	{
		return this->x;
	}
	double getY() const
	{
		return this->y;
	}
	void setX(double newX)
	{
		this->x = newX;
	}
	void setY(double newY)
	{
		this->y = newY;
	}
	void changeInX(double dx)
	{
		this->x += dx;
	}
	void changeInY(double dy)
	{
		this->y += dy;
	}
};

class Circle
{
	Point center;
	double radius;
	char color[16];
public:
	Circle()
	{
		radius = 0;
		color[0] = '\0';
	}
	Circle(const Point & _center, double _radius, char * _color)
	{
		this->center.setX(_center.getX());
		this->center.setY(_center.getY());
		
		this->radius = _radius;
		
		strcpy(this->color, _color);
	}
	
	/// GET-ters
	Point getCenter() const
	{
		return this->center;
	}
	double getRadius() const
	{
		return this->radius;
	}
	void getColor(char * returnColor) const
	{
		strcpy(returnColor, this->color);
	}
	
	/// SET-ters
	void setCenter(const Point & newCenter)
	{
		this->center.setX(newCenter.getX());
		this->center.setY(newCenter.getY());
	}
	void setRadius(double newRadius)
	{
		this->radius = newRadius;
	}
	void setColor(char * newColor)
	{
		strcpy(this->color, newColor);
	}
};

int main()
{
	// Tests
	
	Point p;
	Circle c;
	
	p = c.getCenter();
	assert(p.getX() == 0);
	
	p.setX(10);
	
	c.setCenter(p);
	
	assert(c.getCenter().getX() == 10);
		
	return 0;
}