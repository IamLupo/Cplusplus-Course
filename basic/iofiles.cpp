#include <iostream>
#include <fstream>

using namespace std;

/*
	Reference:
		http://www.cplusplus.com/reference/fstream/ifstream/open/
		http://www.cplusplus.com/reference/fstream/ofstream/open/
*/

int main()
{
	ifstream ifile;
	ofstream ofile;
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
	
	system("pause");
	
	return 0;
}
