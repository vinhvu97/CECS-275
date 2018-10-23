//Vinh Vu, 015347252, Assignment Six
#include <iostream>
using namespace std;
#include "queue.h"

/////////////////////////////////////////////////
//Public
/////////////////////////////////////////////////
Queue::Queue()
{
	init();
}

Queue::Queue(const Queue & other)
{
	init();
	copyAll(other);
}

Queue Queue::operator=(const Queue & other)
{
	deleteAll();
	init();
	copyAll(other);
	return *this;
}

Queue::~Queue()
{
	deleteAll();
}

void Queue::add(string s)
{
	mList.add(s);
}

string Queue::remove()
{
	string removedString = mList.getFront();
	mList.removeFront();
	return removedString; 
}

bool Queue::isEmpty() const
{
	return mList.isEmpty();
}
/////////////////////////////////////////////////
//Friend
/////////////////////////////////////////////////
ostream & operator<<(ostream & os, const Queue & q)
{ 
	cout << q.mList << endl;
	return os; 
}

/////////////////////////////////////////////////
//Private
/////////////////////////////////////////////////
void Queue::init()
{
	
}

void Queue::copyAll(const Queue & other)
{
	mList = other.mList; 
}

void Queue::deleteAll()
{
	
}


