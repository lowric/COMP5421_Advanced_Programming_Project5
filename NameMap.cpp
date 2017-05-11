#include<algorithm>
#include<iostream>
#include<ostream>
#include<string>
#include<map>
#include<iterator>
#include<stdexcept>
#include<iomanip>
#include<numeric>
#include"NameMap.h"

using namespace std;

NameMap::NameMap(istream & sin)
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

void NameMap::insert(string name)
{
	map<string, int>::iterator iter = names.find(name); // look for the name

	if (iter == names.end()) names.insert(pair<string, int>(name, 1)); // if name doesn't exist then insert in the container
	else iter->second++; // otherwise increment frequency
}

//overloaded operator () with on string parameter
void NameMap::operator()(string name)
{
	insert(name);
}

//overloaded operator () with two parameters (int, map<string,int>): used in accumulate algorithm
int NameMap::operator()(int val, pair<string,int>  aPair)
{
	val = val + aPair.second;

	return val;
}

int NameMap::lookup(string name) const
{
	if (names.find(name) != names.end())
	{
		return names.find(name)->second;
	}
	return 0; // searches a name through the container and return the frequency
}

int NameMap::sum_frequency_count() const
{
	return accumulate(names.begin(), names.end(), 0,*this); // returns the sum of the names' frequency in the container
}

void NameMap::print()
{
	for_each(names.begin(),names.end(), [](const pair<string,int> & p)->void{cout << setw(18) << p.first << p.second << '\n';});
}

int NameMap::size() const
{
	return names.size(); // returns the size of the container
}


bool NameMap::remove(const string name)
{

	if (names.find(name) != names.end())
	{
		names.erase(name);
		return true;
	}

	return false;
}
