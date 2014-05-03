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

/* Parsing the input file and filling all this vectors up */
vector<string> select_attr;
int numGroupingVars;
vector<string> grouping_attr;
vector<string> fvect;
vector<string> phi;

/* combination of unique attributes of select_attr and fvect */ 
vector<string> mf_define;

class Agr
{
public:
	string colName;
	string dataType;
	string fnName;
	int num;
	int maxlength;

	Agr(string column_name, string function_name, int num) :
		colName(column_name),
		fnName(function_name),
		num(num),
		maxlength(-1)
	{

	}

	void setDataType(string mType)
	{
		dataType = mType;
	}

	void setMaxLength(int len)
	{
		maxlength = len;
	}
};

vector<string> split(string& str, char delim, int num)
{
	vector<string> contents;
	string mystr;
	stringstream splitString(str);

	while(getline(splitString, mystr, delim))
	{
		if(num == 1)
		{
			select_attr.push_back(mystr);
		}

		else if(num == 3)
		{
			grouping_attr.push_back(mystr);
		}

		else if(num == 4)
		{
			fvect.push_back(mystr);
		}
	}

	return contents;
}

void fileParser()
{
	ifstream fin;
	fin.open("input.txt");

	if(!fin.good())
	{
		cout << "There's some problem with your input file" << endl;
		exit(EXIT_FAILURE);
	}

	if(fin.is_open())
	{
		int counter;
		counter = 0;

		string line;
		char* strtoken;

		while(!fin.eof())
		{
			counter++;

			getline(fin, line);

			if(counter == 1 || counter == 3 || counter == 4)
			{
				split(line, ',', counter);
			}

			else if(counter == 2)
			{
				numGroupingVars = atoi((char*)line.c_str());
			}

			else
			{
				phi.push_back(line);
			}
		}
	}

	fin.close();
}

void makeNewVector()
{
	bool add;

	mf_define = fvect;

	for(unsigned int i = 0; i < select_attr.size(); i++)
	{
		add = true;

		for(unsigned int j = 0; j < fvect.size(); j++)
		{
			cout << "Comparing " << select_attr[i] << " with " <<  fvect[j] << endl;

			if(fvect[j] == select_attr[i])
			{
				add = false;
				break;
			}
		}

		if(add)
		{
			mf_define.push_back(select_attr[i]);
		}
	}
}

int main()
{
	PGconn          *conn;
	PGresult        *res;
	int             rec_count;
	int             row;
	int             col;

	string dbname = "sales";

	// call the function to get all the vectors ready for us
	fileParser();

	// makes the combination of select clause and fvector
	makeNewVector();

	cout << endl << "makeNewVector test" << endl;

	for(unsigned int i = 0; i < mf_define.size(); i++)
	{
		cout << mf_define[i] << endl;
	}

	conn = PQconnectdb("dbname=jrodrig9 host=postgres.cs.stevens.edu user=jrodrig9 password=Johny10353976");

    if (PQstatus(conn) == CONNECTION_BAD) 
    {
            puts("We were unable to connect to the database");
            return 0;
    }
	
	string query = "SELECT column_name, data_type, character_maximum_length FROM information_schema.columns WHERE table_name = 'sales'";
   	res = PQexec(conn, query.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) 
	{
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