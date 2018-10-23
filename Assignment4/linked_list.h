//Vinh Vu, 015347252, Assignment Four
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma warning( disable : 4290 )  

#include <vector>
#include <string>
using namespace std;

class LinkedList
{
public:
	LinkedList();
	LinkedList(vector<string> &strings);
	LinkedList(const LinkedList &other);
	LinkedList operator=(const LinkedList &other);
	~LinkedList();

	void add(string element);
	void addToFront(string element);
	void addToRear(string element);
	void addAt(string element, int index) throw (string); // Indices: 0, 1, ..., n-1
	void addBefore(string elementToAdd, string elementToAddBefore) throw(string);
	void addAfter(string elementToAdd, string elementToAddAfter)  throw(string);

	void remove(string element) throw (string);
	void removeAt(int index) throw (string); // Indices: 0, 1, ..., n-1
	void removeFront() throw (string);
	void removeRear() throw (string);

	string getAt(int index) const throw (string) ; // Indices: 0, 1, ..., n-1
	string getFront() const throw (string);
	string getRear() const throw (string);

	int getCount() const;
	bool isEmpty() const;
	bool isPresent(string element) const;

	vector<string> toVector(bool sorted) const;

	LinkedList operator+(const LinkedList &other);
	LinkedList operator-(const LinkedList &other);
	bool operator==(const LinkedList &other);

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
