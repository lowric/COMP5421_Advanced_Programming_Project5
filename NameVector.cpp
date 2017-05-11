#include<algorithm>
#include<numeric>
#include<iostream>
#include<iterator>
#include<iomanip>
#include<stdexcept>
#include<string>
#include<vector>
#include"NameVector.h"

using namespace std;

NameVector::NameVector(istream & sin)
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

void NameVector::insert(string name)
{
	MyPair<string, int> p(name, 1);

	iter = find(nameVec.begin(),nameVec.end(),p); // looks for the name inside the container

	if (iter != nameVec.end()) ++(iter->second); // if the name exists already increment frequency
	else nameVec.push_back(p); // else add it to the container
}

// overloaded operator () with one string parameter
void NameVector::operator()(string name)
{
	insert(name); // insert the name if it doesn't already exists
}

//overloaded operator () with two parameters (map<string,int>, map<string,int>): used in the sort algorithm
bool NameVector::operator()(pair<string, int> pair1, pair<string, int> pair2)
{
	return pair1.first < pair2.first;
}

//overloaded operator () with two parameters (int, map<string,int>): used in accumulate algorithm
int NameVector::operator()(int val, pair<string, int>  aPair)
{
	val = val + aPair.second;

	return val;
}

int NameVector::lookup(string name) const
{
	MyPair<string, int> p(name, 1);
	
	if (find(nameVec.begin(), nameVec.end(),p) != nameVec.end()) return find(nameVec.begin(), nameVec.end(),p)->second;

	return 0; // looks for the name inside the container and returns its frequency if it exists
}

int NameVector::size() const
{
	return nameVec.size(); // returns the size of the container
}

void NameVector::sort()
{
	std::sort(nameVec.begin(), nameVec.end(), *this); // sorts the container
}

int NameVector::sum_frequency_count() const
{
	// returns the sum of the frequencies stored in the container
	return accumulate(nameVec.begin(), nameVec.end(), 0, *this);
}

void NameVector::print()
{
	for_each(nameVec.begin(),nameVec.end(), [](const pair<string,int> & p)->void{cout << setw(18) << p.first << p.second << '\n';});
}

bool NameVector::remove(string name)
{
	if (lookup(name) > 0)
	{
		MyPair<string, int> p(name, lookup(name));
		auto it = find(nameVec.begin(), nameVec.end(), p);
		nameVec.erase(it);

		return true;
	}

	return false;
}



