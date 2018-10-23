//Vinh Vu, 015347252, Assignment Six
#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

#include "linked_list.h"

class Queue
{
public:
	/*
	* Method Name:  Queue
	*
	*    Initiate an empty queue with linked list
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
	*     An empty queue is created
	*
	*/
	Queue();

	/*
	* Method Name:  Queue
	*
	*    Initiate an empty queue with linked list and copy the content of first queue
	*
	* Input Only:
	*      other- copy of a queue
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
	*     A copy empty queue is created
	*
	*/
	Queue(const Queue &other);

	/*
	* Method Name:  Queue operator=
	*
	*    Create a new linked list and copy all of the elements from a copy queue
	*
	* Input Only:
	*      other- call by reference to a copy of queue
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
	Queue operator=(const Queue &other);

	/*
	* Method Name:  ~Queue
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
	~Queue();

	/*
	* Method Name:  add
	*
	*    Adding an item to the rear of the queue
	*
	* Input Only:
	*      s- a string to add to the rear of the queue
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
	*     An item is added to the queue
	*
	*/
	void add(string s);

	/*
	* Method Name:  remove
	*
	*    Removing an item to the front of the queue
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
	*     An item is removed from the queue
	*/
	string remove();

	/*
	* Method Name:  isEmpty
	*
	*    Check if the queue is empty or not
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
	*/
	bool isEmpty() const;

	/*
	* Method Name:  ostream& operator<<
	*
	*    Output elements within the queue
	*
	* Input Only:
	*	   q- address to queue to output
	*
	* Input & Output:
	*      os-output stream object
	*
	* Output Only:
	*	   none
	*
	* Returns:
	*    os-outputting stream
	*
	* Side Effects:
	*     Output the elements of the queue
	*
	*/
	friend ostream &operator<<(ostream &os, const Queue &q);

private:
	void init();
	void copyAll(const Queue &other);
	void deleteAll();

	LinkedList mList;

};
#endif
