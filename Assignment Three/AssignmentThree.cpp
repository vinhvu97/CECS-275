#include <string>
#include <iostream>

using namespace std;

#include "linked_list.h"

int main(int argc, char **argv)
{
	vector<string> words = { "exciting", "most", "activity", "life", "CECS", "is", "the", "fun", "in",  "275", "and" };

	LinkedList original(words);
	LinkedList sentence;

	sentence.add("in");
	sentence.addToFront("activity");
	sentence.addBefore("exciting", "activity");
	sentence.addToFront("275");
	sentence.addBefore("CECS", "275");
	sentence.addAfter("is", "275");
	sentence.addBefore("most", "exciting");
	sentence.addAfter("the", "is");
	sentence.addToRear("life");
	sentence.addAfter("and", "exciting");
	sentence.addBefore("fun", "activity");
	
	sentence.addAt("AA", 0);
	sentence.remove("AA");
	
	sentence.addToFront("BB");
	sentence.removeAt(0); 
	
	sentence.addToFront("CC");
	sentence.removeFront();
	
	sentence.addToRear("DD");
	sentence.removeRear();

	cout << "Created by vector<string> constructor" << endl << original << endl << endl;
	cout << "The original sentence created by adds/removes" << endl << sentence << endl << endl;
	cout << "sentence front: " << sentence.getFront() << ", rear: " << sentence.getRear() << ", index 2: " << sentence.getAt(2) << endl << endl;

	vector<string> copy = sentence.toVector(true);
	cout << "toVector(true) results in" << endl;
	cout << copy << endl;
	copy.clear();
	cout << "After toVector, copy and sort the original sentence" << endl;
	cout << sentence << endl << endl;
	
	LinkedList *list1 = new LinkedList(sentence);
	cout << "Result of copy constructor" << endl;
	cout << *list1 << endl;
	delete list1;
	cout << "After copy constructor the original sentence" << endl;
	cout << sentence << endl << endl;
	
	LinkedList list2 = sentence;
	cout << "Result of operator=" << endl;
	cout << list2 << endl;
	while (!list2.isEmpty()) list2.removeFront();
	cout << "After operator= the original sentence" << endl;
	cout << sentence << endl << endl;
	
	LinkedList evens;
	evens.add("2");
	evens.add("4");
	evens.add("6");
	
	LinkedList odds;
	odds.add("3");
	odds.add("5");
	odds.add("7");
		
	LinkedList all = evens + odds;
	LinkedList composites;
	composites.add("4");
	composites.add("6");
	
	LinkedList primes = all - composites;

	cout << "evens: " << evens << endl;
	cout << endl << "odds: " << odds << endl;
	cout << endl << "all (odds + evens): " << all << endl;
	cout << endl << "composites: " << composites << endl;
	cout << endl << "primes (all - composites): " << primes << endl;

	LinkedList empty;
	cout << endl << "Is empty list empty? " << ((empty.isEmpty()) ? "Yes" : "No") << endl;
	cout << "Is empty == empty ? " << ((empty == empty) ? "Yes" : "No") << endl;
	cout << "Is all == sentence ? " << ((all == sentence) ? "Yes" : "No") << endl;
	

	cout << ">>>>> ";
	char a;
	cin >> a;

	return 0;
}