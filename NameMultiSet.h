#ifndef NAMEMULTISET_H
#define NAMEMULTISET_H

#include<string>
#include<istream>
#include<set>
#include"CompareNames.h"

using namespace std;

class NameMultiSet
{
	private:
		multiset<string, CompareNames> nameSet;

	public:
		NameMultiSet(istream & file);
		int size() const; // returns the size of the container
		void insert(const string & name); // adds a new name to the container
		bool remove(string name); // removes a name from the container
		void print(); // prints the names from the container to the console
		int lookup(const string & name) const; // searches a name in the container
		void operator()(string name); // overloaded operator () used to insert a name in the container
};


#endif
