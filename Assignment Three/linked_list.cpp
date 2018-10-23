//Vinh Vu, 015347252, Assignment Three
#include <algorithm>
#include "linked_list.h"
using namespace std;

/////////////////////////////////////////////////
//Public
/////////////////////////////////////////////////
LinkedList::LinkedList()
{
	init();
}
LinkedList::LinkedList(vector<string> &strings)
{
	init();
	int i = 0;
	int size = strings.size();
	for (i = 0; i < size; i++)
	{
		add(strings[i]);
	}
}
LinkedList::LinkedList(const LinkedList &other)
{
	deleteAll();
	init();
	copyAll(other);
}

LinkedList LinkedList::operator=(const LinkedList &other)
{
	LinkedList newList;
	newList.copyAll(other);
	return newList;
}
LinkedList::~LinkedList()
{
	deleteAll();
}

void LinkedList::add(string element)
{
	Node *nNode = new Node(element);
	nNode->mNext = mRear;
	nNode->mPrevious = mRear->mPrevious;
	nNode->mNext->mPrevious = nNode;
	nNode->mPrevious->mNext = nNode;

}
void LinkedList::addAt(string element, int index)
{
	int ind = 0;
	Node *current = mFront->mNext;
	for (ind = 0; ind < index; ++ind)
	{
		current = current->mNext;
	}
	Node *nNode = new Node(element);

	nNode->mPrevious = current->mPrevious;
	nNode->mNext = current;

	nNode->mPrevious->mNext = nNode;
	nNode->mNext->mPrevious = nNode;
}

void LinkedList::addBefore(string elementToAdd, string elementToAddBefore)
{
	int index = find(elementToAddBefore);
	if (index == 0)
	{
		addToFront(elementToAdd);
	}
	else
	{
		addAt(elementToAdd, index);
	}

}
void LinkedList::addAfter(string elementToAdd, string elementToAddAfter)
{
	int index = find(elementToAddAfter);
	if (index > getCount())
	{
		addToRear(elementToAdd);
	}
	else addAt(elementToAdd, index + 1);
}

void LinkedList::addToFront(string element)
{
	addAt(element, 0);
}
void LinkedList::addToRear(string element)
{
	add(element);
}


void LinkedList::remove(string element)
{
	removeAt(find(element));
}

void LinkedList::removeAt(int index)
{
	int ind = 0;
	Node *del = mFront->mNext;
	Node *before = mFront;
	Node *after = del->mNext;
	if (index == 0)
	{
		mFront->mNext = after;
		after->mPrevious = mFront;
		delete del;
	}
	else
	{
		for (ind = 0; ind < index; ++ind)
		{
			del = del->mNext;
			before = before->mNext;
			after = after->mNext;
		}delete del;
		before->mNext = after;
		after->mPrevious = before;
	}

}
void LinkedList::removeFront()
{
	removeAt(0);
}
void LinkedList::removeRear()
{
	removeAt(getCount() - 1);
}

string LinkedList::getAt(int index) const
{
	int ind = 0;
	Node *current = mFront->mNext;
	for (ind = 0; ind < index; ++ind)
	{
		current = current->mNext;
	}

	return current->mData;
}

string LinkedList::getFront() const
{
	string frontString = mFront->mNext->mData;
	return frontString;

}

string LinkedList::getRear() const
{
	string backString = mRear->mPrevious->mData;
	return backString;
}


int LinkedList::getCount() const
{
	int count = 0;
	Node *current = mFront->mNext;
	while (current != mRear)
	{
		count++;
		current = current->mNext;
	}
	return count;
}

bool LinkedList::isEmpty() const
{
	if (mFront->mNext == mRear)return true;
	else return false;
}

bool LinkedList::isPresent(string element) const
{
	Node *current = mFront->mNext;
	while (current->mData != element)
	{
		current = current->mNext;
		if (current->mData == element) return true;
	}
	return false;
}
vector<string> LinkedList::toVector(bool sorted) const
{
	vector<string> vectorOfList;
	vector<string> sortedVector;
	int index = 0;
	for (index = 0; index < getCount(); ++index)
	{
		vectorOfList.push_back(getAt(index));
	}
	if (sorted = true)
	{
		sort(vectorOfList.begin(), vectorOfList.end());
		return vectorOfList;
	}
	else
	{
		return vectorOfList;
	}
}
LinkedList LinkedList::operator+(const LinkedList & other)
{

	LinkedList newList;
	newList.copyAll(*this);
	int index = 0;
	int size = other.getCount();
	Node *otherNode = other.mFront->mNext;
	for (index = 0; index < size; ++index)
	{
		newList.add(otherNode->mData);
		otherNode = otherNode->mNext;
	}
	return newList;
}

LinkedList LinkedList::operator-(const LinkedList & other)
{
	LinkedList newList;
	newList.copyAll(*this);
	int index = 0;
	int size = other.getCount();
	Node *otherNode = other.mFront->mNext;
	for (index = 0; index < size; ++index)
	{
		newList.remove(otherNode->mData);
		otherNode = otherNode->mNext;
	}
	return newList;
}

bool LinkedList::operator==(const LinkedList & other)
{
	int ii;
	for (ii = 0; ii < getCount(); ii++)
	{
		if (getAt(ii) == other.getAt(ii))
		{
			continue;
		}
		else return false;
	}return true;
}

/////////////////////////////////////////////////
//Friend
/////////////////////////////////////////////////
ostream &operator<<(ostream &os, const LinkedList &list)
{
	int index = 0;
	for (index = 0; index < list.getCount(); index++)
	{
		os << list.getAt(index) << " ";
	}
	return os;
}

/////////////////////////////////////////////////
//Private
/////////////////////////////////////////////////
void LinkedList::init()
{
	mFront = new Node("Dummy");
	mRear = new Node("Dummy");
	mFront->mNext = mRear;

	mRear->mPrevious = mFront;


}

void LinkedList::copyAll(const LinkedList & other)
{
	for (int i = 0; i < other.getCount(); ++i)
	{
		add(other.getAt(i));
	}
}

int LinkedList::find(string s) const
{
	int index = 0;
	Node *current = mFront->mNext;
	while (current->mData != s)
	{
		index++;
		current = current->mNext;

	}
	return index;
}


void LinkedList::deleteAll()
{
	Node *current = mFront;
	Node *delNode = NULL;
	while (current != mRear)
	{
		delNode = current;
		current = current->mNext;
		if (delNode->mPrevious)
		{
			delNode->mPrevious = NULL;
		}
		if (delNode->mNext)
		{
			delNode->mNext = NULL;
		}
	}
}