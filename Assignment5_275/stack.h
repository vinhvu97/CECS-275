//Vinh Vu, 015347252, Assignment Five
#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

#include "linked_list.h"

class Stack
{
public:
	/*
	* Method Name:  Stack
	*
	*    Initiate an empty stack with linked list
	*
	* Input Only:
	*      none
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
	*     An empty list is created
	*
	*/
	Stack();

	/*
	* Method Name:  Stack
	*
	*    Initiate an empty stack with linked list and copy the content of first stack
	*
	* Input Only:
	*      other- copy of a stack
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
	*     An empty list is created
	*
	*/
	Stack(const Stack &other);

	/*
	* Method Name:  Stack operator=
	*
	*    Create a new linked list and copy all of the elements from a copy
	*
	* Input Only:
	*      other- call by reference to a copy of stack
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     *this- reference point to the copy
	*
	* Side Effects:
	*     none
	*
	*/
	Stack operator=(const Stack &other);

	/*
	* Method Name:  ~Stack
	*
	*	   A destructor that clears up memory
	*
	* Input Only:
	*      none
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
	*		Cleared memory
	*
	*/
	~Stack();

	/*
	* Method Name:  push
	*
	*    Adding an item to the front of the stack
	*
	* Input Only:
	*      item- an item to add to the top of the stack
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
	*     An item is added to the stack
	*
	*/
	void push(string item);

	/*
	* Method Name:  pop
	*
	*    Removing an item to the front of the stack
	*
	* Input Only:
	*      none
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
	*     An item is removed from the stack
	* Throws:
	*     S_EMPTY- when stack is empty and nothing to remove
	*
	*/
	void pop() throw(string);  // Throws if stack is empty

	/*
	* Method Name:  getTop
	*
	*    Get the top element of the stack
	*
	* Input Only:
	*      none
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     Top element of the stack
	*
	* Side Effects:
	*     none
	* Throws:
	*     S_EMPTY- when stack is empty and cannot return a top element
	*
	*/
	string getTop() const throw(string); // Throws if stack is empty

	/*
	* Method Name:  isEmpty
	*
	*    Check if the stack is empty or not
	*
	* Input Only:
	*      none
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*      bool- true if it's empty, false if it's not
	*
	* Side Effects:
	*     none
	* Throws:
	*     S_EMPTY- when stack is empty and cannot return a top element
	*
	*/
	bool isEmpty() const;

	/*
	* Method Name:  ostream& operator<<
	*
	*    Output elements within the stack
	*
	* Input Only:
	*      os-output stream object
	*	   s- address to stack to output
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*	   none
	* Returns:
	*    os-operating system
	*
	* Side Effects:
	*     Output the elements of the stack
	*
	*/
	friend ostream &operator<<(ostream &os, const Stack &s);

private:
	void init();
	void copy(const Stack &other);
	void deleteAll();

	LinkedList mList;
};

#endif
