// to run use: g++ -lpq program.cpp -o program
#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <postgresql/libpq-fe.h>

using namespace std;

vector<string>& split(const string& str, char delimeter)
{
	vector<string> contents
	string mystr;
	stringstream splitString(str);
	
	while(getline(splitString, mystr, delimeter))
	{
		contents.push_back(mystr);
	}
	
	return contents;
}

int main()
{
	PGconn          *conn;
	PGresult        *res;
	int             rec_count;
	int             row;
	int             col;

	string dbname = "sales";
	string select_line;
	int num_of_grouping_vars;
	string groupingAttr;
	// string fvect;
	string such_that;
	
	string where;

	vector<string> select_attr;
	vector<string> grouping_attr;
	vector<string> fvect;
	
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
				strtoken = strtok((char *)line.c_str(), ", ");

				while(strtoken != NULL)
				{
					//cout << "select_attr: " << strtoken << endl;
					//strtoken = strtoken.erase (std::remove (strtoken.begin(), strtoken.end(), ' '), strtoken.end());
					select_attr.push_back(strtoken);
					strtoken = strtok(NULL, ", ");
				}

				where = "AND column_name = '" + select_attr[0] + "' ";
				for(int i=1; i<select_attr.size(); i++)
				{
					//cout << select_attr[i] << endl;
					where = where + "OR column_name = '" + select_attr[i] + "' ";
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
				strtoken = strtok((char *)line.c_str(), ", ");
  
 				while(strtoken != NULL)
 				{
 					cout << "grouping_attr: " << strtoken << endl;
 					//strtoken = strtoken.erase (std::remove (strtoken.begin(), strtoken.end(), ' '), strtoken.end());
 					grouping_attr.push_back(strtoken);
 					strtoken = strtok(NULL, ", ");
 				}
			}

			// aggregate functions
			else if(count == 4)
			{
				strtoken = strtok((char *)line.c_str(), ", ");
  
 				while(strtoken != NULL)
 				{
 					cout << "fvect: " << strtoken << endl;
 					//strtoken = strtoken.erase (std::remove (strtoken.begin(), strtoken.end(), ' '), strtoken.end());
 					fvect.push_back(strtoken);
 					strtoken = strtok(NULL, ", ");
 				}
			}

			else
			{

			}
		}
	}
	
	
	conn = PQconnectdb("dbname=jrodrig9 host=postgres.cs.stevens.edu user=jrodrig9 password=Johny10353976");

        if (PQstatus(conn) == CONNECTION_BAD) {
                puts("We were unable to connect to the database");
                return 0;
        }
		string query = "SELECT column_name, data_type, character_maximum_length FROM information_schema.columns WHERE table_name = 'sales'" + where;
       res = PQexec(conn, query.c_str());

		if (PQresultStatus(res) != PGRES_TUPLES_OK) {
               puts("We did not get any data!");
               return 0;
		}

		rec_count = PQntuples(res);

		cout << "EXEC SQL BEGIN DECLARE SECTION;" << endl;
		cout << "struct{" << endl;

		for (row=0; row<rec_count; row++) {
				
			if (atoi(PQgetvalue(res, row, 2)) <= 0)
			{
				if (string(PQgetvalue(res, row, 1)) == "integer")
					cout << "int\t";
				else 
					cout << PQgetvalue(res, row, 1) << "\t";
					cout << PQgetvalue(res, row, 0) << endl;   // Column
			}
				
			else
			{
				cout << "char\t";
				cout << PQgetvalue(res, row, 0);   // Column
				cout << "[" << (atoi(PQgetvalue(res, row, 2))+1)<< "];" << endl;
			}
       }
		cout << "} mf_structure[500];" << endl;
		cout << "EXEC SQL END DECLARE SECTION;" << endl;
		cout << "EXEC SQL INCLUDE sqlca;" << endl;
		PQclear(res);

        PQfinish(conn);

         return 0; 
}
