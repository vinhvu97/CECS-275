//Vinh Vu, 015347252, Assignment Eight
#include "stack.h"
#include <stack>
#include <string>
using namespace std;

Stack::Stack(string name)
{
	mName = name;
}

string Stack::getName() const
{
	return mName; 
}

int Stack::getTop() const
{
	return mStack.top();
} 

void Stack::pop()
{
	mStack.pop();
}

void Stack::push(int item)
{
	mStack.push(item);
}
