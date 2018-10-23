//Vinh Vu, 015347252, Assignment Two
#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
public:
	/*
	* Method Name:  Point
	*
	*    Initialize and construct a point with default coordinate
	*
	* Input Only:
	*      x- the x coordinate
	*	   y- the y coordinate 
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
	*     Construct a point
	*
	*/
		Point(int x = 0, int y = 0);

	/*
	* Method Name:  Point
	*
	*    Construct a copy of a point
	*
	* Input Only:
	*     none 
	*	   
	* Input & Output:
	*      none
	*
	* Output Only:
	*      fromPoint- call by reference to p1
	*
	* Returns:
	*     none
	*
	* Side Effects:
	*     Make a copy of point 1 
	*
	*/
		Point(const Point &fromPoint);

	/*
	* Method Name:  Point operator=
	*
	*    Copy and overload the point 
	*
	* Input Only:
	*    none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherPoint- call by reference to copy of point 1
	*
	* Returns:
	*     Hidden address *this to a copy of point
	*
	* Side Effects:
	*     Have a copy of point 1
	*
	*/
		Point operator=(const Point &otherPoint);

	/*
	* Method Name:  ~Point
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
		~Point();

	/*
	* Method Name:  getX
	*
	*    Get x value
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
	*     mX- x value
	*
	* Side Effects:
	*     none
	*
	*/
		int getX() const;

	/*
	* Method Name:  getY
	*
	*    Get y value
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
	*     mY- y value
	*
	* Side Effects:
	*     none
	*
	*/
		int getY() const;

	/*
	* Method Name:  operator==
	*
	*    Check x and y coordinate of the otherPoint
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherPoint- call by reference to the other point
	*
	* Returns:
	*     Whether (x,y) is the same in the copy of point 
	*
	* Side Effects:
	*     none
	*
	*/
		bool operator==(Point &otherPoint);

	/*
	* Method Name:  operator=!
	*
	*    Check the values using the hidden address to otherPoint
	*
	* Input Only:
	*	   none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherPoint- call by reference to the other point
	*
	* Returns:
	*     Whether the hidden copy and otherPoint have the same (x,y) values
	*
	* Side Effects:
	*     none
	*
	*/
		bool operator!=(Point &otherPoint);

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
	*     (x,y) have new values
	*
	*/
		void move(int deltaX, int deltaY);

	/*
	* Method Name:  getDistance
	*
	*    Get the distance between the old and new x,y coordinates
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherPoint- call by reference to copy of a point
	*
	* Returns:
	*     the distance
	*
	* Side Effects:
	*     none
	*
	*/
		double getDistance(const Point &otherPoint) const;

	/*
	* Method Name:  getPolarCoordinate
	*
	*    Get the polar coordinate between the old and new x,y coordinates
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      rho- the distance between the old and new coordinates
	*	   theta- an integer to get the polar coordinate
	* Returns:
	*     none
	*
	* Side Effects:
	*     delete the origin
	*
	*/
		void getPolarCoordinate(double &rho, double &theta);

	/*
	* Method Name:  ostream& operator<<
	*
	*    Output (x,y) coordinates
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      os-output stream object 
	*	   p- point 
	*
	* Returns:
	*     os- operating system
	*
	* Side Effects:
	*     none
	*
	*/
		friend ostream& operator<<(ostream &os, Point &p);
		
	private:
					
		void init(int x, int y);
		void copy(const Point &otherPoint);
		void deleteAll();
		
		int mX;
		int mY;
};

#endif
