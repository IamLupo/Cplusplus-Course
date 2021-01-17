#include <iostream>

#include "myclass.h"

using namespace std;

MyClass* getResult()
{
	MyClass* my_ref_class;
	
	// Create a MyClass object without its limited by the stack
	my_ref_class = new MyClass("Hello my reference class! :D");
	
	return my_ref_class;
}

int main()
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
	
	system("pause");
	
	return 0;
}
