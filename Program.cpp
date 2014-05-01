// to run use: g++ -lpq program.cpp -o program
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <list>
#include <sstream>
#include <fstream>
#include <postgresql/libpq-fe.h>

using namespace std;

class AggregateFn
{
public:
	string column_name;
	string type;
	string aggregate_function;
	int num;
	int max_length;

	// constructor
	AggregateFn(string column_name, string aggregate_function, int num) : 
		name(column_name),  
		function(aggregate_function), 
		num(num),
		max_length(-1)
	{

	}

	void setType(string mType)
	{
		type = mType;
	}

	void setMaxLength(int len)
	{
		max_length = len;
	}
};

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
	vector<string> phi;
	
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
 					// strtoken = strtoken.erase (std::remove (strtoken.begin(), strtoken.end(), ' '), strtoken.end());
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
 					// strtoken = strtoken.erase (std::remove (strtoken.begin(), strtoken.end(), ' '), strtoken.end());
 					fvect.push_back(strtoken);
 					strtoken = strtok(NULL, ", ");
 				}
			}

			// phi operator
			else
			{	
				phi.push_back(line);
			}
		}
		
		for(unsigned int i = 0; i < phi.size(); i++)
		{
			cout << "phi: " << i << " " << phi[i] << endl;
		}
	}
	
	string argument;
	string search = "_";

	// sum_quant_1
	string agrFn;
	string colName;
	int numGrVar;

	// for each object in the fvect we are making object add will add it to the list
	for(unsigned int i = 0; i < fvect.size(); i++)
	{
		argument = fvect[i];

		if(argument.find(search) != -1)
		{
			vector<string> contents = split(argument, "_");
			agrFn = contents[0];
			colName = contents[1];
			numGrVar = atoi(contents[2]);
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

	fin.close();
	return 0; 
}
