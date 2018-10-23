//Vinh Vu, 015347252, Assignment Two
#include <math.h>
#include <stdio.h>

using namespace std;

#include "circle.h"

static const double PI = 3.1459;
static const double DEGREES_PER_RADIAN = 180.0 / PI;

//////////////////////////////////////////////////////////////
// Public
//////////////////////////////////////////////////////////////
Circle::Circle(int x, int y, int radius)
{
	init(Point(x, y), radius);
}
Circle::Circle(const Point &center, int radius)
{
	init(center, radius);
}
Circle::~Circle()
{
	deleteAll();
}
int Circle::getRadius() const
{
	return mRadius;
}
Point Circle::getCenter() 
{
	return mCenter;
}
bool Circle::operator==(Circle &otherCircle)
{
	return (getCenter() == otherCircle.getCenter()) && (getRadius() == otherCircle.getRadius());
}
bool Circle::operator!=(Circle &otherCircle)
{
	return!(*this == otherCircle);

}
void Circle::move(int deltaX, int deltaY)
{
	(mCenter.move(deltaX, deltaY));
}
double Circle::getDistance( Circle &otherCircle) const
{
	return(mCenter.getDistance(otherCircle.getCenter()));
}
//////////////////////////////////////////////////////////////
// Friends
//////////////////////////////////////////////////////////////
ostream& operator<<(ostream &os, Circle &c)
{
	os << "(" << c.getCenter().getX() << "," << c.getCenter().getY() << ")"<<", Radius: " << c.getRadius();
	return os;
}

//////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////
void Circle::init(Point center, int radius)
{
	mCenter = center;
	mRadius = radius;
}
void Circle::copy(Point center, int radius)
{
	init(center, radius);
}

void Circle::deleteAll()
{

}