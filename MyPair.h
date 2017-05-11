#ifndef MYPAIR_H
#define MYPAIR_H

#include<string>
#include<utility>

using namespace std;

template<class K, class V >

class MyPair: public pair<K,V>
{
	public:

		MyPair(){};
		MyPair(const K & x, const V & y) : pair<K, V>(x, y) {}; // uses the base class ctor

		//overloaded operator() : compares key elements of two MyPair objects
		bool operator()(const MyPair & p1, const MyPair & p2)
		{
			return p1.first < p2.first;
		}

		//overloaded operator == : tests the equality between the key of two MyPair objects
		friend bool operator==(const MyPair & p1, const MyPair & p2)
		{
			return p1.first == p2.first;
		}

};


#endif