#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <fstream>
//#include <postgresql/libpq-fe.h>

using namespace std;

int main()
{
	string dbname = "sales";
	string select_line;
	int num_of_grouping_vars;
	string groupingAttr;
	string fvect;
	string such_that;

	vector<string> select_attr;
	
	string line;
	char* strtoken;

	int count = 0;

	/* input file for arguments */
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
			count++;

			getline(fin, line);

			// select attribute
			if(count == 1)
			{
				strtoken = strtok((char *)line.c_str(), ",");

				while(strtoken != NULL)
				{
					cout << "strtoken: " << strtoken << endl;
					//strtoken = strtoken.erase (std::remove (strtoken.begin(), strtoken.end(), ' '), strtoken.end());
					select_attr.push_back(strtoken);
					strtoken = strtok(NULL, ", ");
				}

				for(int i=0; i<select_attr.size(); i++)
				{
					cout << select_attr[i] << endl;
				}
			}

			// number of grouping variables
			else if(count == 2)
			{
				num_of_grouping_vars = atoi((char *)line.c_str());
				cout << num_of_grouping_vars << endl;
			}

			// grouping attributes
			else if(count == 3)
			{

			}

			// aggregate functions
			else if(count == 4)
			{

			}

			else
			{

			}
		}
	}
}