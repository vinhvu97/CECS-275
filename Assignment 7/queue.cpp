//Vinh Vu, 015347252, Assignment Seven
#include <string>
#include "queue.h"
#include <iostream>
#pragma warning( disable : 4290 )
using namespace std;

static const string Q_Full = "Q Full";
static const string Q_EMPTY = "Q Empty";
/////////////////////////////////////////////////
//Private
/////////////////////////////////////////////////
void Queue::init(int size)
{
	mQueue = new string[size];
	mFront = mRear = mCount = 0;
	mSize = size;
}
void Queue::copyAll(const Queue & other)
{
	for (int i = 0; i < mSize; ++i)
	{
		mQueue[i] = other.mQueue[i];
	}
	mFront = other.mFront;
	mRear = other.mRear;
	mSize = other.mSize;
	mCount = other.mCount;
}
void Queue::deleteAll()
{
	delete [] mQueue;
}
/////////////////////////////////////////////////
//Public
/////////////////////////////////////////////////
Queue::Queue(int size)
{
	init(size);
}

Queue::Queue(const Queue & other)
{
	init(other.mSize);
	copyAll(other);
}

Queue Queue::operator=(const Queue & other)
{
	deleteAll();
	init(other.mSize);
	copyAll(other);
	return *this;
}

Queue::~Queue()
{
	deleteAll();
}

void Queue::add(string s) throw(string)
{
	if (mCount==mSize) throw Q_Full;
	mQueue[mRear] = s;
	mRear = (mRear + 1) % mSize;
	++mCount;
}

string Queue::remove() throw(string)
{
	if (isEmpty()) throw Q_EMPTY;
	string removedString = mQueue[mFront];
	mFront = (mFront + 1) % mSize;
	--mCount;
	return removedString;
}

bool Queue::isEmpty() const
{
	return mCount == 0;
}
/////////////////////////////////////////////////
//Friend
/////////////////////////////////////////////////
ostream & operator<<(ostream & os, const Queue & q)
{
	for (int i=0; i<q.mSize;++i)
	{ 
		cout << q.mQueue[i]<<" ";
	}
	return os; 
}
