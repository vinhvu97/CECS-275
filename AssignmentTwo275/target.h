//Vinh Vu, 015347252, Assignment Two
#ifndef TARGET_H
#define TARGET_H

#include "circle.h"
#include <iostream>
#include<vector>
using namespace std;

class Target
{
public:
	/*
	* Method Name:  Target
	*
	*    Initialize and construct a target with default coordinate, radius, and number of ring
	*
	* Input Only:
	*      x- the x coordinate
	*	   y- the y coordinate
	*	   radius- the radius
	*	   ring- the number of circles
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
	*     Construct a Target
	*	  Add target to a vector of circles
	*/
	Target(int x=0, int y=0, int radius=0, int count=0);

	/*
	* Method Name:  Target
	*
	*    Construct a circle using Circle and ring
	*
	* Input Only:
	*	  ring- the number of circles
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*     otherCircle- call by reference to circle 2
	*
	* Returns:
	*     none
	*
	* Side Effects:
	*     Construct target 2 using Circle
	*/
	Target(Circle &otherCircle, int count);

	/*
	* Method Name:  Target
	*
	*    Construct a copy of target 2
	*
	* Input Only:
	*     none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherTarget- call to reference to a copy
	*
	* Returns:
	*     none
	*
	* Side Effects:
	*     Construct target 3
	*
	*/
	Target(Target &otherTarget);

	/*
	* Method Name:  ~Target
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
	~Target();
	 
	/*
	* Method Name:  getBullsEye
	*
	*    Get center and radius from class Circle
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
	*     mBullsEye- contains center and radius, 1 circle
	*
	* Side Effects:
	*     none
	*
	*/
	Circle getBullsEye();

	/*
	* Method Name:  getTarget
	*
	*    Vector function to store all circles that form a target
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
	*     mTarget- the created target from circles
	*
	* Side Effects:
	*     none
	*
	*/
	vector<Circle> getTarget();

	/*
	* Method Name:  getRingRadius
	*
	*    Retrieve a certain circle's radius
	*
	* Input Only:
	*      circleNumber- the circle's number in the vector
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     the radius
	*
	* Side Effects:
	*     none
	*
	*/
	int getRingRadius(int circleNumber);

	/*
	* Method Name:  setRingRadius
	*
	*    Retrieve certain circles' radii and switch them
	*
	* Input Only:
	*      circleNumber- the circle's number in the vector
	*	   intputRadius- value of radius to switch
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     New circle's radius 
	*
	* Side Effects:
	*     One circle's radius is switched out
	*
	*/
	vector <Circle> setRingRadius(int circleNumber, int inputRadius);

	/*
	* Method Name:  getCount
	*
	*    Get number of circles
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
	*     mCount- number of circles
	*
	* Side Effects:
	*     none
	*
	*/
	int getCount();

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
	*      otherTarget- address to a copy of a target
	*
	* Returns:
	*     the distance
	*
	* Side Effects:
	*     none
	*
	*/
	double getDistance(Target &otherTarget);

	/*
	* Method Name:  operator==
	*
	*    Check the conditions of the otherTarget: center, radius, rings
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      otherTarget- call by reference to the other circle
	*
	* Returns:
	*     true if the center and radii are the same
	*	  false if the center and radii are not the same
	*
	* Side Effects:
	*     none
	*
	*/
	bool operator==(Target &otherTarget);
  
	/*
	* Method Name:  ostream& operator<<
	*
	*    Output center, radius, and ring values for each target
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      os-output stream object
	*	   target- address to target to output values
	*
	* Returns:
	*    os-operating system
	*
	* Side Effects:
	*     none
	*
	*/
	friend ostream& operator<<(ostream &os, Target &t);

private:
	void init(Circle circle, int count);
	void copy(Target &target);
	void deleteAll();
	void generateTarget();

	vector<Circle> mTarget;
	Circle mBullsEye;
	int mCount;
};

#endif