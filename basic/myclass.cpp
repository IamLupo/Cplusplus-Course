#include <iostream>

#include "myclass.h"

using namespace std;

MyClass::MyClass(const string &name)
{
	cout << "MyClass execute constructor." << endl;
	
	this->_name = name;
}

MyClass::~MyClass()
{
	cout << "MyClass execute de-constructor." << endl;
}

void MyClass::MyFunction()
{
	cout << "MyClass execute MyFunction." << endl;
	cout << "name = " << this->_name << endl;
}