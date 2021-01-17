#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <exception>
#include <fstream>

#include "myclass.h"

using namespace std;

void exampleConsole()
{
	cout << "Hello world!" << endl;
	cout << "-----------------------" << endl;
}

void exampleString()
{
	string my_string;
	
	// Set string
	my_string = "Hello World";
	cout << "my_string = " << my_string << endl;
	
	// modify string
	my_string += "!";
	cout << "my_string = " << my_string << endl;
	
	// Replace characters
	my_string = std::regex_replace(my_string, std::regex("o"), "0");
	cout << "my_string = " << my_string << endl;
	
	cout << "-----------------------" << endl;
}

template<typename T>
void printVector(const string &name, const vector<T> &list)
{
	cout << name << " = { ";
	
	for(T v : list)
	{
		cout << v << " ";
	}
	
	cout << "}" << endl;
}

void exampleVector()
{
	vector<int> my_numbers;
	vector<int>::iterator my_numbers_it;
	vector<string> my_strings;
	
	// Create list
	my_numbers = {2, 3, 5, 11, 7};
	printVector<int>("my_numbers", my_numbers);
	
	// Sort integer list
	sort(my_numbers.begin(), my_numbers.end());
	printVector<int>("my_numbers", my_numbers);
	
	// Use iterate pointer to read the list
	cout << "my_numbers = { ";
	for (my_numbers_it = my_numbers.begin() ; my_numbers_it != my_numbers.end(); ++my_numbers_it)
	{
		cout << *my_numbers_it << " ";
	}
	cout << "}" << endl;
	
	// Set string
	my_strings = { "Hello", "World", "!" };
	printVector<string>("my_strings", my_strings);
	
	cout << "-----------------------" << endl;
}

void myCrashyCrashyFunc(int a, int b)
{
	if(a > b)
	{
		throw runtime_error("myCrashyCrashyFunc: a can't be bigger then b");
	}
	
	cout << "myCrashyCrashyFunc(" << a << ", " << b << ") = " << (a + b) << endl;
}

void exampleTryCatch()
{
	try
	{
		myCrashyCrashyFunc(10, 15);
		myCrashyCrashyFunc(21, 15);
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}
	
	cout << "-----------------------" << endl;
}

MyClass* getResult()
{
	MyClass* my_ref_class;
	
	// Create a MyClass object without its limited by the stack
	my_ref_class = new MyClass("Hello my reference class! :D");
	
	return my_ref_class;
}

void exampleClass()
{
	MyClass my_class("Henkie Spenkie");
	MyClass* my_ref_class;
	
	// Execute MyFunction
	my_class.MyFunction();
	
	// Get reference of our class
	my_ref_class = &my_class;
	cout << "my_ref_class = " << std::hex << my_ref_class << std::dec << endl;
	
	// Execute MyFunction
	my_ref_class->MyFunction();
	
	// Get a pointer class
	my_ref_class = getResult();
	cout << "my_ref_class = " << std::hex << my_ref_class << std::dec << endl;
	
	// Execute MyFunction
	my_ref_class->MyFunction();
	
	// destroy our result out of our memory
	delete my_ref_class;
	
	cout << "-----------------------" << endl;
}

/*
	Reference:
		http://www.cplusplus.com/reference/fstream/ifstream/open/
		http://www.cplusplus.com/reference/fstream/ofstream/open/
*/
void exampleIOFiles()
{
	ofstream ofile;
	ifstream ifile;
	string line;
	
	cout << "[*] Create test.txt" << endl;
	ofile.open("test.txt", std::ofstream::out);
	
	if(ofile.is_open())
	{
		cout << "[*] Send message to test.txt" << endl;
		ofile << "Hello World!" << endl;
		
		cout << "[*] Close test.txt" << endl;
		ofile.close();
	}
	
	
	cout << "[*] Open test.txt" << endl;
	ifile.open("test.txt", std::ifstream::in);
	if(ifile.is_open())
	{
		cout << "[*] read all lines and display." << endl;
		while(getline(ifile, line))
		{
			cout << line << endl; 
		}
	}
	
	cout << "-----------------------" << endl;
}

void examplePointers()
{
	int* number_ptr;
	
	// Create space to store the integer value
	number_ptr = new int;
	
	// Set value
	*number_ptr = 1337;
	
	// Draw number_ptr
	cout << "number_ptr adress = " << std::hex << number_ptr << std::dec << endl;
	cout << "*number_ptr = " << *number_ptr << endl;
	
	// Destroy data
	delete number_ptr;
	
	cout << "-----------------------" << endl;
}

int main()
{
	exampleConsole();
	exampleString();
	exampleVector();
	exampleTryCatch();
	exampleClass();
	exampleIOFiles();
	examplePointers();
	
	return 0;
}