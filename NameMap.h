#ifndef NAMEMAP_H
#define NAMEMAP_H

#include<map>
#include<string>
#include<istream>

using namespace std;

class NameMap
{
	private:
		map<string, int> names;

	public:
		NameMap(istream & file);
		int size() const; // returns the size of the container
		void insert(string name); //adds a new name to the container if it doesn't exists already
		bool remove(string name); // removes a name from the continer
		int lookup(string name) const; // searches though the container for a given name
		int sum_frequency_count() const; // sums up the frquences
		void operator()(string name);
		void print(); // prints the names to the console
		int operator()(int val, pair<string,int> aPair);
		
};

#endif
