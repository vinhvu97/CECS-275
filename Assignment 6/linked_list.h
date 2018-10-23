//Vinh Vu, 015347252, Assignment Six
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
	void addAt(string element, int index); // Indices: 0, 1, ..., n-1
	void addBefore(string elementToAdd, string elementToAddBefore);
	void addAfter(string elementToAdd, string elementToAddAfter);

	void remove(string element);
	void removeAt(int index); // Indices: 0, 1, ..., n-1
	void removeFront();
	void removeRear();

	string getAt(int index) const; // Indices: 0, 1, ..., n-1
	string getFront() const;
	string getRear() const;

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
