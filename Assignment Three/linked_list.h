//Vinh Vu, 015347252, Assigment Three
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>
#include <string>
using namespace std;

class LinkedList
{
public:
	/*
	* Method Name:  LinkedList
	*
	*    Create an empty list with dummy front and rear
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
	LinkedList();

	/*
	* Method Name:  LinkedList
	*
	*    Create a list with elements from a string vector 
	*
	* Input Only:
	*      none
	* Input & Output:
	*      strings- a vector of string
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     none
	*
	* Side Effects:
	*     A list is created 
	*
	*/
	LinkedList(vector<string> &strings);

	/*
	* Method Name:  LinkedList
	*
	*    Create an empty list and a copy with dummy front and rear
	*
	* Input Only:
	*      other- a copy of a list 
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
	*     A copy of a list is created
	*
	*/
	LinkedList(const LinkedList &other);

	/*
	* Method Name:  LinkedList operator=
	*
	*    Make sure that the content of the copy is the same as the original 
	*
	* Input Only:
	*      other- call by reference to a copy of linked list
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
	*     A new list is created 
	*
	*/
	LinkedList operator=(const LinkedList &other);

	/*
	* Method Name:  ~Linked List
	*
	*		A destructor that clears up memory
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
	~LinkedList();

	/*
	* Method Name:  add
	*
	*    Adding a string element to the list, default to the end of the list
	*
	* Input Only:
	*      element- a string to add to the list
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
	*     add a string to the empty list
	*
	*/
	void add(string element);

	/*
	* Method Name:  addToFront
	*
	*    Adding a string element to the front of a list
	*
	* Input Only:
	*      element- a string to add to the list
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
	*     The front of a list will have a string
	*
	*/
	void addToFront(string element);

	/*
	* Method Name:  addToRear
	*
	*    Adding a string element to the the end of list
	*
	* Input Only:
	*      element- a string to add to the list
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
	*     The end of the list will have a string
	*
	*/
	void addToRear(string element);


	/*
	* Method Name:  addAt
	*
	*    Adding a string element to a wanted index within the list
	*
	* Input Only:
	*      element- a string to add to the list
	*	   index- the place to put the string
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
	*     A string is added to a wanted index
	*
	*/
	void addAt(string element, int index); // Indices: 0, 1, ..., n-1

	
	/*
	* Method Name:  addBefore
	*
	*    Adding a string element before a existing string
	*
	* Input Only:
	*      elementToAdd- a string to add to the list
	*	   elementToAddBefore- the string to put elementToAdd before it
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
	*     A string will be added before an already existing string
	*
	*/
	void addBefore(string elementToAdd, string elementToAddBefore);

	/*
	* Method Name:  addAfter
	*
	*    Adding a string element after a existing string
	*
	* Input Only:
	*      elementToAdd- a string to add to the list
	*	   elementToAddAfrer- the string to put elementToAdd before it
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
	*     A string will be added to afer already existing string
	*
	*/
	void addAfter(string elementToAdd, string elementToAddAfter);

	/*
	* Method Name:  remove
	*
	*    Remove a string from the list
	*
	* Input Only:
	*      element- a string to add to remove
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
	*     A string will be removed
	*
	*/
	void remove(string element);

	/*
	* Method Name:  removeAt
	*
	*    Remove a string at a wanted index
	*
	* Input Only:
	*	   index- the index of the string to be removed
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
	*     A string will be removed at a certain index
	*
	*/
	void removeAt(int index); // Indices: 0, 1, ..., n-1

	/*
	* Method Name:  removeFront
	*
	*    Remove a string from the front list
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
	*     The first string will be removed
	*
	*/
	void removeFront();

	/*
	* Method Name:  removeRear
	*
	*    Remove a string from the end list
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
	*     The last string will be removed
	*
	*/
	void removeRear();

	/*
	* Method Name:  getAt
	*
	*    Get the string at a certain index
	*
	* Input Only:
	*      index- the index to retrieve a string
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     returnString- the string at the index
	*
	* Side Effects:
	*     none
	*
	*/ 
	string getAt(int index) const; // Indices: 0, 1, ..., n-1

	/*
	* Method Name:  getFront
	*
	*    Get the first string of the list
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
	*     frontString- the string at the index
	*
	* Side Effects:
	*     none
	*
	*/
	string getFront() const;

	/*
	* Method Name:  getRear
	*
	*    Get the last string of the list
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
	*     rearString- the last string 
	*
	* Side Effects:
	*     none
	*
	*/
	string getRear() const;

	/*
	* Method Name:  getCount
	*
	*    Count the number of elements within a list
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
	*     count- the number of elements
	*
	* Side Effects:
	*     none
	*
	*/
	int getCount() const;

	/*
	* Method Name:  isEmpty
	*
	*    Check whether the list is empty or not
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
	*     true if the list is empty
	*	  false if the list has at least 1 element
	*
	* Side Effects:
	*     none
	*
	*/
	bool isEmpty() const;

	/*
	* Method Name:  isPresent
	*
	*    Check if a certain string is in the list
	*
	* Input Only:
	*      element- string to check 
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     true if the string is in the list
	*     false if the string is not in it 
	*
	* Side Effects:
	*     none
	*
	*/
	bool isPresent(string element) const;

	/*
	* Method Name:  toVector 
	*
	*    Convert a linked list into a vector
	*
	* Input Only:
	*      sorted- a bool value, 
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     vectorOfList- the converted vector of string
	*
	* Side Effects:
	*     The linked list is converted into a vector 
	*
	*/
	vector<string> toVector(bool sorted) const;

	/*
	* Method Name:  operator+
	*
	*    Overloading the + operator
	*
	* Input Only:
	*      other- copy of a linked list 
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     newList- the overloaded linked list
	*
	* Side Effects:
	*     none
	*
	*/
	LinkedList operator+(const LinkedList &other);

	/*
	* Method Name:  operator-
	*
	*    Overloading the - operator
	*
	* Input Only:
	*      other- copy of a linked list
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     newList- the overloaded linked list
	*
	* Side Effects:
	*     none
	*
	*/
	LinkedList operator-(const LinkedList &other);

	/*
	* Method Name:  operator==
	*
	*    Check if the linked list copy has the same elements
	*
	* Input Only:
	*      other- copy of the linked list
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     true- if the elements all the same
	*	  false- if the elements are not the same
	* Side Effects:
	*     none
	*
	*/
	bool operator==(const LinkedList &other);

	/*
	* Method Name:  ostream& operator<<
	*
	*    Output elements within the linked list
	*
	* Input Only:
	*      os-output stream object
	*	   target- address to target to output values
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
	*     none
	*
	*/
	friend ostream &operator<<(ostream &os, const LinkedList &list);

private:

	class Node
	{
		friend class LinkedList;

	private:
		inline Node(string data)
		{
			mPrevious = mNext = 0;
			mData = data;
		}

		string mData;
		Node *mPrevious;
		Node *mNext;
	};

	void init();
	void copyAll(const LinkedList &other);
	void deleteAll();

	int find(string s) const;

	Node *mFront;
	Node *mRear;

};
#endif
