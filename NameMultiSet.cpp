#include<algorithm>
#include<string>
#include<iterator>
#include<stdexcept>
#include<iostream>
#include"NameMultiSet.h"
#include"CompareNames.h"

using namespace std;

NameMultiSet::NameMultiSet(istream & sin)
{
	try
	{
		istream_iterator<string> start(sin), finish; // creates an istream iterator to start and end of sin
		for_each(start, finish, *this); // extract strings from the istream object and insert them in the names container
	}
	catch (invalid_argument & iA)
	{
		cout << iA.what() << endl;
	}
}

void NameMultiSet::insert(const string & name)
{
	nameSet.insert(name); // inserts a name to the container
}

int NameMultiSet::lookup(const string & name) const
{
	if(binary_search(nameSet.begin(),nameSet.end(),name))
	{
		return count(nameSet.begin(),nameSet.end(),name); // returns the number of elements in the range (frequency of the name)
	}

	return 0; // returns 0 if not found
}

// overloaded operator () with one string parameter
void NameMultiSet::operator()(string name)
{
	insert(name);
}

int NameMultiSet::size() const
{
	return nameSet.size();
}

void NameMultiSet::print()
{
	ostream_iterator<string> itOut(cout, "\n");
	std::copy(nameSet.begin(), nameSet.end(), itOut);
}

bool NameMultiSet::remove(string name)
{
	//std::remove(nameSet.begin(), nameSet.end(), name);
	if(nameSet.find(name) != nameSet.end())
	{
		nameSet.erase(name);
	}

	if (lookup(name) == 0) return true;
	else return false;
}
