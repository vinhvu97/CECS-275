//Vinh Vu, 015347252, Assignment Six
#include <iostream>
using namespace std;

#include "stack.h"

static const string S_EMPTY = "List is Empty";

/////////////////////////////////////////////////
//Public
/////////////////////////////////////////////////
Stack::Stack()
{
	init();
}

Stack::Stack(const Stack & other)
{
	init();
	copy(other);
}

Stack Stack::operator=(const Stack & other)
{
	deleteAll();
	init();
	copy(other);
	return *this;
}

Stack::~Stack()
{
	deleteAll();
}

void Stack::push(string item)
{
	mList.addToFront(item);
}

void Stack::pop() throw(string)
{
	if (isEmpty()) throw S_EMPTY;
	mList.removeFront();
}

string Stack::getTop() const throw(string)
{
	if (isEmpty()) throw S_EMPTY;
	 return mList.getFront();
	
}

bool Stack::isEmpty() const
{
	return mList.isEmpty();
}

/////////////////////////////////////////////////
//Friend
/////////////////////////////////////////////////
ostream & operator<<(ostream & os, const Stack & s)
{
	cout << s.mList << endl;
	return os;
}
/////////////////////////////////////////////////
//Private
/////////////////////////////////////////////////
void Stack::init()
{
	
}

void Stack::copy(const Stack & other)
{
	mList = other.mList;
}

void Stack::deleteAll()
{
	
}


