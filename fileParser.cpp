#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string line;
	ifstream fin;	
	fin.open("input.txt");
	
	if(!fin.good())
	{
		cout << "Problem with your input file" << endl;
		return -1;
	}
	
	if(fin.is_open())
	{
		while(!fin.eof())
		{
			getline(fin, line);
		}
	}
}
