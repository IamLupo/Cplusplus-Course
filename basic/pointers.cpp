#include <iostream>

using namespace std;

/*
	int*		->	int
	0xb81420	->	1337
*/
int main()
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
	
	system("pause");
	
	return 0;
}