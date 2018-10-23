//Vinh Vu, 015347252, Assignment Nine
#include "bst.h"
#include <iostream>
using namespace std;
BST::BST()
{
	mRoot = NULL;
}

void BST::add(int key, string data)
{
	if (mRoot == NULL)
	{
		mRoot = new Node(key,data);
	}
	else
	{
		mRoot->add(key, data);
	}
}

bool BST::isPresent(int key) const
{
	if (mRoot==NULL) return false;
	else return mRoot->isPresent(key);
}

vector<string> BST::getTraversal(TraversalOrder order) const
{
	vector<string> answers;
	mRoot->Traversal(order,answers);
	return answers;
}

double BST::evaluate()
{
	if (mRoot == NULL) return 0.0;
	return mRoot->evaluate();
}

double BST::evaluateAt(int key)
{
	Node *here = find(key);
	if (here == NULL) return 0.0;
	else return here->evaluate();
}
BST::Node* BST::find(int key)
{
	if (mRoot == NULL) return NULL;
	else return mRoot->find(key);
}
