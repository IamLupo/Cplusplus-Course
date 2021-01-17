#include <iostream>
#include <exception>

using namespace std;

void myCrashyCrashyFunc(int a, int b)
{
	if(a > b)
	{
		throw runtime_error("myCrashyCrashyFunc: a can't be bigger then b");
	}
	
	cout << "myCrashyCrashyFunc(" << a << ", " << b << ") = " << (a + b) << endl;
}

int main()
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
	
	system("pause");
	
	return 0;
}
