#include <iostream>
#include <vector>
#include <string>
#include "libpq-fe.h"

using namespace std;

static void exit_nicely(PGconn *conn)
{
	PQfinish(conn);
	exit(1);
}

int main()
{
	string dbname = "sales";
	string select_line;
	string num_of_grouping_vars;
	string groupingAttr;
	string fvect;
	string such_that;
	string having;

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
			getline(fin, line);
			
			// need to do the logic here after shower now :)
		}
	}
}