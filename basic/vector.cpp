#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main()
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
	
	system("pause");
	
	return 0;
}
