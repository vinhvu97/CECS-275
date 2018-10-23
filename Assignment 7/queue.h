#ifndef QUEUE_H
#define QUEUE_H
#pragma warning( disable : 4290 )
#include <string>
using namespace std;

#include "linked_list.h"

class Queue
{
public:
	Queue(int size = 200);
	Queue(const Queue &other);
	Queue operator=(const Queue &other);
	~Queue();

	void add(string s) throw(string);
	string remove() throw(string);
	bool isEmpty() const;

	friend ostream &operator<<(ostream &os, const Queue &q);

private:
	void init(int size);
	void copyAll(const Queue &other);
	void deleteAll();

	string *mQueue;
	int mSize;
	int mCount;
	int mFront;
	int mRear;

};
#endif
