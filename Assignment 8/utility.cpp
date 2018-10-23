//Vinh Vu, 015347252, Assignment Eight
#include "utility.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
#include "stack.h"
Utility::Utility()
{

}

string Utility::reverse(string s)
{
	if (s.length() <= 1) return s;
	else return s.at(s.length() - 1) + reverse(s.substr(0,s.length() - 1));
}

int Utility::factorial(int n)
{
	if (n <= 1) return n; 
	else return n*factorial(n - 1);
}

int Utility::countOccurances(char a, string s)
{
	if (s.length() == 0) return 0;
	else if (s.length() == 1) return ((a == s.at(0) ? 1 : 0));
	else if (a == s.at(0)) return 1 + countOccurances(a, s.substr(1, s.length() - 1));
	else if (a != s.at(0)) return 0 + countOccurances(a, s.substr(1, s.length() - 1));
}

bool Utility::isPalindrome(string s)
{
	if (s.length() <= 1) return true;
	else if (s.at(0) != s.at(s.length() - 1)) return false;
	else return isPalindrome(s.substr(1, s.length() - 2));
}

int Utility::gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int Utility::mult(int a, int b)
{
	if (b == 0) return 0;
	else if (b == 1) return a;
	else return (a + mult(a, b - 1));
}
void move(Stack &from, Stack &to)
{
	int toPush = from.getTop();
	from.pop();
	to.push(toPush);
	cout << "Move " << toPush << " from Stack " << from.getName() << " to " << to.getName() << endl;
}
void solve(Stack &from, Stack &to, Stack &temp, int n)
{
	if (n == 1) move(from, to);
	if (n > 1)
	{
		solve(from, temp, to, n - 1);
		move(from, to);
		solve(temp, to, from, n - 1);
	}
}
void Utility::towers(int n)
{
	Stack tower1("Tower 1");
	Stack tower2("Tower 2");
	Stack tower3("Tower 3");
	for (int i = n; i > 0; --i)
	{
		tower1.push(i);
	}
	cout << "TowersofHanoi(" << n << ")" << endl;
	solve(tower1, tower2, tower3, n);
	if (n > 0)  cout << "Required " << pow(2, n) - 1 << " moves" << endl;
}
