//Vinh Vu, 015347252, Assignment Two
#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include <iostream>

using namespace std;

class Circle
{
public:
	/*
	* Method Name:  Circle
	*
	*    Initialize and construct a circle with passing arguments
	*
	* Input Only:
	*      x- the x coordinate
	*	   y- the y coordinate
	*	   radius- the radius
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     none
	*
	* Side Effects:
	*     Construct a Circle
	*
	*/
	Circle(int x=0, int y=0,int radius=0);

	/*
	* Method Name:  Circle
	*
	*    Construct a circle using Point and a radius
	*
	* Input Only:
	*	  radius- the radius
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*     center- call by reference x and y coordinate
	*
	* Returns:
	*     none
	*
	* Side Effects:
	*     Construct circle 2 using Point
	*
	*/
	Circle(const Point &center, int radius);

	/*
	* Method Name:  ~Circle
	*
	*    Deconstruct all 
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     none
	*
	* Side Effects:
	*     delete all
	*
	*/
	~Circle();

	/*
	* Method Name:  getCenter
	*
	*    Get (x,y) coordinate from Point
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     mCenter- center 
	*
	* Side Effects:
	*     none
	*
	*/
	Point getCenter() ;

	/*
	* Method Name:  getRadius
	*
	*    Get radius
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     mRadius- radius
	*
	* Side Effects:
	*     none
	*
	*/
	int getRadius() const;

	/*
	* Method Name:  operator==
	*
	*    Check values of center and radius of the otherCircle
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherCircle- call by reference to the other circle
	*
	* Returns:
	*     Center (x,y) and radius
	*
	* Side Effects:
	*     none
	*
	*/
	bool operator==(Circle &otherPoint);

	/*
	* Method Name:  operator=!
	*
	*    Check not values of center and radius of otherCircle
	*
	* Input Only:
	*	   none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherCircle- call by reference to the other point
	*
	* Returns:
	*     Hidden address of circle
	*
	* Side Effects:
	*     none
	*
	*/
	bool operator!=(Circle &otherPoint);

	/*
	* Method Name:  move
	*
	*    Move the x and y coordinate
	*
	* Input Only:
	*      deltaX- the change of x
	*	   deltaY- the change of y
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     the new x and y coordinates
	*
	* Side Effects:
	*     New coordinates for x and y
	*
	*/
	void move(int deltaX, int deltaY);

	/*
	* Method Name:  getDistance
	*
	*    Get the distance between the old and new x,y coordinates
	
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherCircle- call by reference to copy of a circle
	*
	* Returns:
	*     the distance
	*
	* Side Effects:
	*     none
	*
	*/
	double getDistance(Circle &otherCircle) const;

	/*
	* Method Name:  ostream& operator<<
	*
	*    Perform formatted input
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      os-output stream object
	*	   c- address to circle to output values
	*
	* Returns:
	*     the input information
	*
	* Side Effects:
	*     Outputing the (x,y) coordinate and radius of circle
	*
	*/
	friend ostream& operator<<(ostream &os, Circle &c);

private:

	void init(Point center, int radius);
	void copy(Point center, int radius);
	void deleteAll();
	Point mCenter;
	int mRadius;
};

#endif
