//Vinh Vu, 015347252, Assignment Two
#include <math.h>
#include <stdio.h>
 
using namespace std;

#include "point.h"

static const double PI = 3.1459;
static const double DEGREES_PER_RADIAN = 180.0 / PI;

//////////////////////////////////////////////////////////////
// Public
//////////////////////////////////////////////////////////////
Point::Point(int x, int y)
{
	init(x, y);
}

Point::Point(const Point &otherPoint)
{
	copy(otherPoint);
}

Point Point::operator=(const Point &otherPoint)
{
	deleteAll();
	copy(otherPoint);
	return *this;
}

Point::~Point()
{
	deleteAll();
}

void Point::move(int deltaX, int deltaY)
{
	init(getX() + deltaX, getY() + deltaY);
}

bool Point::operator==(Point &otherPoint)
{
	return (getX() == otherPoint.getX()) && (getY() == otherPoint.getY());
}

bool Point::operator!=(Point &otherPoint)
{
	return !(*this == otherPoint);
}

double Point::getDistance(const Point &otherPoint) const
{
	int deltaX = getX() - otherPoint.getX();
	int deltaY = getY() - otherPoint.getY();

	return sqrt((deltaX * deltaX) + (deltaY * deltaY));
}

void Point::getPolarCoordinate(double &rho, double &theta)
{
	Point *origin = new Point(0, 0);
	
	rho = origin->getDistance(*this);
	
	int x = getX();
	int y = getY();

	if (x == 0 && y == 0) theta = 0.0;
	else if (x == 0 && y > 0) theta = 90.0;
	else if (x == 0 && y < 0) theta = 270.0;
	else theta = atan((double)getY() / (double)getX()) * DEGREES_PER_RADIAN;

	delete origin;
}


int Point::getX() const
{
	return mX;
}

int Point::getY() const
{
	return mY;
}

//////////////////////////////////////////////////////////////
// Friends
//////////////////////////////////////////////////////////////
ostream& operator<<(ostream &os, Point &p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

//////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////
void Point::init(int x, int y)
{
	mX = x;
	mY = y;
}

void Point::copy(const Point &otherPoint)
{
	init(otherPoint.getX(), otherPoint.getY());
}

void Point::deleteAll()
{

}
