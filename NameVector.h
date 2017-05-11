#ifndef NAMEVECTOR_H
#define NAMEVECTOR_H


#include<string>
#include<istream>
#include<vector>
#include"MyPair.h"

using namespace std;

class NameVector
{
private:
	vector<MyPair<string, int> > nameVec;
	vector<MyPair<string, int> >::iterator iter;

public:
	NameVector(istream & file);
	int size() const; // returns the size of the container
	void sort(); // sorts the names in the container
	void insert(string name); // adds a name to the container
	bool remove(string name); // removes a name from the container
	void print(); // prints the names and frequency from the container to the console
	int lookup(string name) const; // searches for a given name in the container
	int sum_frequency_count() const; // sums up the frequencies
	void operator()(string name); // overloaded operator () used to insert names in the container
	bool operator()(pair<string, int> pair1, pair<string, int> pair2); // overloaded operator () with two pair as parameters (used to compare two elements of the vector of Mypair<string,int>)
	int operator()(int val, pair<string, int>  aPair); // used in the accumulate algorithm
};


#endif
