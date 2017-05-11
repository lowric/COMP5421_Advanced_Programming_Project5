// Assignment 5 Test Driver Program
#include <fstream>
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <limits>
#include <stdexcept>      // std::invalid_argument

#include "MyPair.h"
#include "NameVector.h"
#include "NameMap.h"
#include "NameMultiSet.h"
//#include "NameCollectionInterface.h"


// allow the following names into the current name space
using std::string;
using std::istream;
using std::ifstream;
using std::invalid_argument;
using std::toupper;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

// Test function prototypes
void TestNameVector(const string& input_file);
void TestNameMap(const string& input_file);
void TestNameMultiSet(const string& input_file);

// helper function prototypes
void open_input_stream(ifstream& input_file_stream, const string& input_file);
void pause();

// definitions
int main()
{
	string input_file;
	cout << "Enter the name of the input file (enter empty name to quit): ";
	getline(cin, input_file);

	if (!input_file.empty())   // for simplicity just quit on empty file name
	{
		try
		{
			TestNameMap(input_file);          // test NameMap
			pause();

			TestNameMultiSet(input_file);    // test NameMultiSet
			pause();

			TestNameVector(input_file);         //test NameVector
			pause();

		}
		catch (const std::invalid_argument & ia)
		{
			cout << "Invalid Argument Error: " << ia.what() << endl;
			// can re-throw, in case an extended scope is prepared to handle the current exception
			// throw;         
		}
		catch (const std::exception & e)
		{
			cout << "Error: " << e.what() << endl;
			// can re-throw, in case an extended scope is prepared to handle the current exception
			// throw;         
		}
		catch (...)
		{
			cout << "Error: unknown" << endl;
			// can re-throw, in case an extended scope is prepared to handle the current exception
			// throw;
		}
	}
	cout << "bye" << endl;
	return 0;
}


// consume and discard input characters until the Enter key is pressed
// Pre: none
// Post: all input characters up to but not including 
//       the Enter key will be consumed and discarded.
void pause()
{
	cout << "Press Enter to Continue . . . ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// Pre: none
// post: the stream input_file_stream will represent the file input_file
// Throws: std::invalid_argument, if input_file cannot be opened for input
void open_input_stream(ifstream& input_file_stream, const string& input_file)
{
	input_file_stream.open(input_file.c_str());
	if (!input_file_stream)
	{
		throw std::invalid_argument("Could not open input file: " + input_file);
	}
}

// Pre: none
// post: test run has been a success
// Throws: std::invalid_argument, if input_file cannot be opened for input
void TestNameMap(const string& input_file)
{
	ifstream inputStream;
	open_input_stream(inputStream, input_file);

	NameMap namemap(inputStream);
	int size = namemap.size();
	namemap.insert("BBB");
	namemap.insert("BBB");
	namemap.insert("BBB");
	namemap.insert("AAA");
	namemap.insert("AAA");
	namemap.insert("AAA");
	namemap.insert("CCC");
	namemap.insert("CCC");
	namemap.insert("CCC");
	assert(namemap.lookup("BBB") == 3);
	assert(namemap.lookup("AAA") == 3);
	assert(namemap.lookup("CCC") == 3);
	assert(namemap.size() == size + 3);

	namemap.remove("AAA");
	assert(namemap.lookup("AAA") == 0);
	namemap.remove("CCC");
	namemap.remove("CCC");
	assert(namemap.lookup("CCC") == 0);
	assert(namemap.size() == size + 1);

	cout << "\n===========" << endl;
	cout << "TestNameMap" << endl;
	cout << "===========" << endl;

	namemap.print();
	cout << "-------------------------------" << endl;
	cout << "NameMap container size :" << namemap.size() << endl;
	cout << "NameMap total frequency count :" << namemap.sum_frequency_count() << endl;
	cout << "-------------------------------" << endl;

	inputStream.close();
}

// Pre: none
// post: test run has been a success
// Throws: std::invalid_argument, if input_file cannot be opened for input
void TestNameMultiSet(const string& input_file)
{
	ifstream inputStream;
	open_input_stream(inputStream, input_file);

	NameMultiSet nameset(inputStream);
	int size = nameset.size();
	nameset.insert("BBB");
	nameset.insert("BBB");
	nameset.insert("BBB");
	nameset.insert("AAA");
	nameset.insert("AAA");
	nameset.insert("AAA");
	nameset.insert("CCC");
	nameset.insert("CCC");
	nameset.insert("CCC");
	assert(nameset.lookup("BBB") == 3);
	assert(nameset.lookup("AAA") == 3);
	assert(nameset.lookup("CCC") == 3);
	assert(nameset.size() == size + 9);

	nameset.remove("AAA");
	assert(nameset.lookup("AAA") == 0);
	nameset.remove("CCC");
	nameset.remove("CCC");
	assert(nameset.lookup("CCC") == 0);
	assert(nameset.size() == size + 3);

	cout << "\n================" << endl;
	cout << "TestNameMultiSet" << endl;
	cout << "================" << endl;

	nameset.print();
	cout << "-----------------------------------" << endl;
	cout << "NameMultiSet container size :" << nameset.size() << endl;
	cout << "NameMultiSet total frequency count :" << nameset.size() << endl;
	cout << "-----------------------------------" << endl;

	inputStream.close();
}

// Pre: none
// post: test run has been a success
// Throws: std::invalid_argument, if input_file cannot be opened for input
void TestNameVector(const string& input_file)
{
	ifstream inputStream;
	open_input_stream(inputStream, input_file);

	NameVector namevec(inputStream);
	int size = namevec.size();
	namevec.insert("BBB");
	namevec.insert("BBB");
	namevec.insert("BBB");
	namevec.insert("AAA");
	namevec.insert("AAA");
	namevec.insert("AAA");
	namevec.insert("CCC");
	namevec.insert("CCC");
	namevec.insert("CCC");
	assert(namevec.lookup("BBB") == 3);
	assert(namevec.lookup("AAA") == 3);
	assert(namevec.lookup("CCC") == 3);
	assert(namevec.size() == size + 3);

	namevec.remove("AAA");
	assert(namevec.lookup("AAA") == 0);
	namevec.remove("CCC");
	namevec.remove("CCC");
	assert(namevec.lookup("CCC") == 0);
	assert(namevec.size() == size + 1);

	cout << "\n========================" << endl;
	cout << "TestNameVector: unsorted" << endl;
	cout << "========================" << endl;
	namevec.print();

	pause();

	namevec.sort();
	cout << "\n======================" << endl;
	cout << "TestNameVector: sorted" << endl;
	cout << "======================" << endl;
	namevec.print();

	cout << "----------------------------------" << endl;
	cout << "NameVector container size :" << namevec.size() << endl;
	cout << "NameVector total frequency count :" << namevec.sum_frequency_count() << endl;
	cout << "----------------------------------" << endl;

	inputStream.close();
}
