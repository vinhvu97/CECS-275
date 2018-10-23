//Vinh Vu, 015347252, Assignment Nine
#ifndef BST_H
#define BST_H

#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

class BST
{
public:

	enum TraversalOrder { PREORDER, INORDER, POSTORDER };

	/*
	* Method Name:  BST()
	*
	*    Constructor that initiates NULL mRoot
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     An empty BST is created
	*
	* Side Effects:
	*     none
	*
	*/
	BST();

	/*
	* Method Name:  add
	*
	*    Add an element to the BST
	*
	* Input Only:
	*      key- the key of the node, location
	*      data- the data to input
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
	*     An element is added to BST
	*
	*/
	void add(int key, string data);

	/*
	* Method Name:  isPresent
	*
	*    Check whether a key is in the BST
	*
	* Input Only:
	*      key- the key of the node
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     True if key is there, false otherwise
	*
	* Side Effects:
	*    none
	*
	*/
	bool isPresent(int key) const;

	/*
	* Method Name:  getTraversal
	*
	*    Put the existing BST in chosen order
	*
	* Input Only:
	*      order- the type of order to be put in
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     A string vector with the BST elements in chosen order
	*
	* Side Effects:
	*    none
	*
	*/
	vector<string> getTraversal(TraversalOrder order) const;

	/*
	* Method Name:  evaluate
	*
	*    Evaluate the value of the tree
	*
	* Input Only:
	*      none
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     the value of the tree
	*
	* Side Effects:
	*     none
	*
	*/
	double evaluate();

	/*
	* Method Name:  evaluateAt
	*
	*    Evaluate the subtree value at a certain key
	*
	* Input Only:
	*      key- the key to evaluate its subtree
	*
	* Input & Output:
	*      none
	*
	* Output Only:
	*      none
	*
	* Returns:
	*     the value of the subtree
	*
	* Side Effects:
	*     none
	*
	*/
	double evaluateAt(int key);

private:

	class Node
	{
		friend class BST;
	private:
		inline Node(int key, string data)
		{
			mLeft = mRight = NULL;
			mData = data;
			mKey = key;
		}
		double mValue;
		string mData;
		int mKey;
		Node *mLeft;
		Node *mRight;
		void Node::add(int key, string data)
		{
			if (key < mKey)
			{
				if (mLeft == NULL) mLeft = new Node(key, data);
				else return mLeft->add(key, data);
			}
			else
			{
				if (mRight == NULL) mRight = new Node(key, data);
				else return mRight->add(key, data);
			}

		}
		bool Node::isPresent(int key)
		{
			if (find(key) == NULL) return false;
			else return true;
		}
		void Node::Traversal(TraversalOrder type, vector<string> &answers)
		{
			if (type == PREORDER) answers.push_back(mData);
			if (mLeft!=NULL) mLeft->Traversal(type, answers);
			if (type == INORDER) answers.push_back(mData);
			if (mRight!=NULL) mRight->Traversal(type, answers);
			if (type == POSTORDER) answers.push_back(mData);
		}
		Node *find(int key)
		{
			if (key == mKey)
			{
				return this;
			}
			else if (key < mKey)
			{
				if (mLeft == NULL) return NULL;
				else return mLeft->find(key);
			}
			else
			{
				if (mRight == NULL) return NULL;
				else return mRight->find(key);
			}
		}
		double Node::evaluate()
		{			
			if (mLeft == NULL && mRight == NULL)
			{
				mValue = stod(mData);
			}
			else
			{
				if (mLeft != NULL) mLeft->evaluate();
				if (mRight != NULL) mRight->evaluate();
				double left = mLeft->mValue;
				double right = mRight->mValue;
				if (mData.at(0) == '+') mValue = left + right;
				if (mData.at(0) == '-') mValue = left - right;
				if (mData.at(0) == '*') mValue = left * right;
				if (mData.at(0) == '/') mValue = left / right;
			}
			return mValue;
		}
	};//closes node

	Node *find(int key);
	Node *mRoot;

};

#endif
