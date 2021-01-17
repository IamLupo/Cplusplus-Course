#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

class MyClass {
	private:
		std::string _name;
	
	public:
		// Constructor and deconstructor
		MyClass(const std::string &name);
		~MyClass();
		
		void MyFunction();
};

#endif // MYCLASS_H
