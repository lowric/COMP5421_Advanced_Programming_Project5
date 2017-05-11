#ifndef COMPARENAMES_H
#define COMPARENAMES_H

#include<string>

using namespace std;

class CompareNames
{
	public:
		// overloaded operator () : compares the size of two strings
		bool operator()(string s1, string s2)
		{
			if (s1.length() == s2.length()) return s1 < s2;
			else return s1.length() < s2.length();
		}
};


#endif