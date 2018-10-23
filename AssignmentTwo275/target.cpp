//Vinh Vu, 015347252, Assignment Two
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "target.h"
using namespace std;


static const double PI = 3.1459;
static const double DEGREES_PER_RADIAN = 180.0 / PI;

//////////////////////////////////////////////////////////////
// Public
/////////////////////////////////////////////////////////////
Target::Target(int x, int y,int radius, int count)
{
	init(Circle(Point(x, y), radius), count);
	generateTarget();
}
Target::Target(Circle &otherCircle, int count)
{
	init(otherCircle, count);
	generateTarget();
}
Target::Target(Target &target)
{
	copy(target);
	generateTarget();
}
Target::~Target()
{
	deleteAll();
}
void Target::generateTarget()
{
	int newRadius = getBullsEye().getRadius();
	for (int i = 0; i < getCount(); i++)
	{
		Circle newCircle = Circle(getBullsEye().getCenter(), newRadius);
		mTarget.push_back(newCircle);
		newRadius = newRadius + getBullsEye().getRadius();
	}
}
vector<Circle> Target::getTarget()
{
	return mTarget;
}
Circle Target::getBullsEye()
{
	return mBullsEye;
}
int Target::getCount()
{
	return mCount;
}
bool Target::operator==(Target &otherTarget)
{
	for (int i = 0; i < getCount(); i++)
	{
		if (getBullsEye().getCenter() == otherTarget.getBullsEye().getCenter() && getBullsEye().getRadius() == otherTarget.getBullsEye().getRadius() && getTarget()[i].getRadius() == otherTarget.getTarget()[i].getRadius())
		{
			continue;
		}
		else
		{
			return false;
		}
	}return true;

}
int Target::getRingRadius(int circleNumber)
{
	return(getTarget()[circleNumber].getRadius());
}
vector<Circle> Target::setRingRadius(int circleNumber, int inputRadius)
{
	Circle newCircle = Circle(getBullsEye().getCenter(), inputRadius);
	mTarget[circleNumber] = (newCircle);
	return (getTarget());
}
double Target::getDistance(Target &target)
{
	return (getBullsEye().getDistance(target.getBullsEye()));
}
void Target::move(int deltaX, int deltaY)
{
	mBullsEye.move(deltaX, deltaY);
}
//////////////////////////////////////////////////////////////
// Friends
//////////////////////////////////////////////////////////////
ostream & operator<<(ostream &os, Target &t)
{
	os << " Target has " << t.getTarget().size() << " rings" << endl;
	for (int i = 0; i < t.getCount(); i++)
	{
		os << "Ring " << i << " .Center: " << t.getBullsEye().getCenter() << "," << "Radius: " << t.getTarget()[i].getRadius()<<endl;
	}
	return os;
}
//////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////
void Target::init(Circle circle, int count)
{
	mBullsEye = circle;
	mCount = count;
}
void Target::copy(Target &target)
{
	init(target.getBullsEye(), target.getCount());
}

void Target::deleteAll()
{

}
