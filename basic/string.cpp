#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string my_string;
	string my_string_patch;
	
	// Set string
	my_string = "Hello World";
	cout << "my_string = " << my_string << endl;
	
	// modify string
	my_string += "!";
	cout << "my_string = " << my_string << endl;
	
	// Replace characters
	my_string_patch = regex_replace(my_string, regex("o"), "0");
	
	cout << "my_string = " << my_string << endl;
	cout << "my_string_patch = " << my_string_patch << endl;
	
	system("pause");
	
	return 0;
}
