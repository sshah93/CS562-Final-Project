// to run use: g++ -lpq program.cpp -o program
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <list>
#include <sstream>
#include <fstream>
#include <cstddef>
#include <postgresql/libpq-fe.h>

using namespace std;

ofstream outfile ("output.pgc");
void fileParser();
void split(string& str, char delim, int num);
void makeNewVector();
void makeObjects();
void printInput();

/* Parsing the input file and filling all this vectors up */
vector<string> select_attr;
int numGroupingVars;
vector<string> grouping_attr;
vector<string> fvect;
vector<vector<string>> phi(1, vector<string>(1));

string whereClause;
vector<string> firstSelect;

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

	virtual ~Agr()
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
	
	void getName()
	{
		if (fnName == "none")
			outfile << colName;
		else
			outfile << fnName << num;			
	}
	
	void printMFStruct()
	{
		outfile << "\t";
		if (fnName == "cnt")
			outfile << "int\t";
		else
			outfile << dataType << "\t";
		
		if (fnName == "none")
		{
			if (colName == "month")
				outfile << "mMonth";
			else if (colName == "year")
				outfile << "mYear";
			else if (colName == "day")
				outfile << "mDay";
			else
				outfile << colName;
		}
		else 
			outfile << fnName << "_" << colName << "_" << num;
		
		if (maxlength <= 0)
			outfile << ";" << endl;
		else
			outfile << "[" << maxlength << "];" << endl;
	}
	
	/*string getGroupAttr()
	{
		if (fnName == "none")
		{
			if (colName == "month")
				return "mMonth";
			else if (colName == "year")
				return "mYear";
			else if (colName == "day")
				return "mDay";
			else
				return colName;
		}
		else
			return "";
	}*/

	/* cout << endl << "List" << endl;
	
	for(unsigned int i = 0; i < mylist.size(); i++)
	{
		cout << mylist[i]->colName << endl;
	} 

	cout << endl << "function name" << endl;
	
	for(unsigned int i = 0; i < mylist.size(); i++)
	{
		cout << mylist[i]->fnName << endl;
	} 

	cout << endl << "number" << endl;
	
	for(unsigned int i = 0; i < mylist.size(); i++)
	{
		cout << mylist[i]->num << endl;
	} */
};

/* list that contains all the objects that will be inserted in our mf struct */
vector<Agr*> mylist;

void split(string& str, char delim, int num)
{
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
		int numTemp;
		counter = 0;

		string line;
		char* strtoken;

		while(!fin.eof())
		{
			counter++;

			/* cout << "Counter = " << counter << endl; */

			getline(fin, line);

			if(counter == 1 || counter == 3 || counter == 4)
			{
				split(line, ',', counter);
			}

			else if(counter == 2)
			{
				numGroupingVars = atoi((char*)line.c_str());
			}

			else if(counter == 5)
			{
				whereClause = line;
			}

			else
			{
				numTemp = atoi(line.c_str());

				if(numTemp != 0)
				{	
					phi[numTemp-1].push_back(line);
				}

				//phi.push_back(line);
			}
		}
	}

	fin.close();
	// printInput();
}

void printInput()
{
	int i;

	for(i=0; i<select_attr.size();i++)
	{
		cout << select_attr[i] << endl;
	}

	cout << endl << "Number of grouping variables= " << numGroupingVars << endl << endl;

	for(i=0; i<grouping_attr.size(); i++)
	{
		cout << grouping_attr[i] << endl;
	}

	for(i=0; i<fvect.size(); i++)
	{
		cout << fvect[i] << endl;
	}

	cout << endl << "Where clause = " << whereClause << endl << endl;

	for (i=0; i<phi.size(); i++)
	{
		cout << phi[i] << endl;
	}
}

void makeNewVector()
{
	bool add;

	mf_define = select_attr;

	for(unsigned int i = 0; i < fvect.size(); i++)
	{
		add = true;

		for(unsigned int j = 0; j < select_attr.size(); j++)
		{
			// cout << "Comparing " << select_attr[i] << " with " <<  fvect[j] << endl;

			if(fvect[i] == select_attr[j])
			{
				add = false;
				break;
			}
		}

		if(add)
		{
			mf_define.push_back(fvect[i]);
		}
	}
}

void makeObjects()
{
	char delim = '_';
	string str;
	string fn_name;
	string col_name;
	int number;

	for(int i = 0; i < mf_define.size(); i++)
	{
		str = mf_define[i];

		if(str.find('_') != std::string::npos)
		{
			// cout << "function_name" << endl;
			fn_name = str.substr(0, str.find_first_of('_'));
			// cout << "column_name" << endl;
			col_name = str.substr(str.find_first_of('_')+1, str.find_last_of('_')-4);
			// cout << "number" << endl;
			string num = str.substr(str.find_last_of('_')+1);
			number = atoi(num.c_str());
		}

		else
		{
			fn_name = "none";
			number = 0;
			col_name = mf_define[i]; 
		}
		
		Agr* newAgr = new Agr(col_name, fn_name, number);
		mylist.push_back(newAgr); 
	}
}

string convertName(string str)
{
	if (str == "month")
		return "mMonth";
	else if (str == "year")
		return "mYear";
	else if (str == "day")
			return "mDay";
	else
		return str;
}
	
int main()
{
	// postgres local vars
	PGconn          *conn;
	PGresult        *res;
	int             rec_count; 

	string dbname = "sales";
	vector<string> getColName;
	vector<string> getDataType;

	phi.resize(numGroupingVars);

	for(int i = 0; i <= numGroupingVars; i++)
	{
		phi[i].resize(numGroupingVars);
	} 

	// call the function to get all the vectors ready for us
	fileParser();

	// makes the combination of select clause and fvector
	makeNewVector();

	// make objects for each element in the mf_define vector
	makeObjects();

	// postgres code
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

	for (unsigned int row=0; row<rec_count; row++) 
	{					
		for (unsigned int i = 0; i < mylist.size(); i++)
		{
			if (string(PQgetvalue(res, row, 0)) == mylist[i]->colName)
			{
				if (string(PQgetvalue(res, row, 1)) == "integer")
					mylist[i]->setDataType("int");
				else if (string(PQgetvalue(res, row, 1)) == "character varying" || string(PQgetvalue(res, row, 1)) == "character")
					mylist[i]->setDataType("char");
				else 
					mylist[i]->setDataType(string(PQgetvalue(res, row, 1)));
				
				if (atoi(PQgetvalue(res, row, 2)) > 0)
					mylist[i]->setMaxLength(atoi(PQgetvalue(res, row, 2))+1);
			}
		}	
   	}
	
	PQclear(res);
	
	outfile << "#include\t<stdio.h>\n" << endl;
	outfile << "EXEC SQL BEGIN DECLARE SECTION;" << endl;
	outfile << "struct\n{" << endl;
	for (unsigned int i=0; i < mylist.size(); i++)
		mylist[i]->printMFStruct();
	outfile << "} mf_structure[500]; \n\n" << endl;
	outfile << "struct\n{\n\t";
	outfile << "char	*cust;\n\t";
	outfile << "char	*prod;\n\t";
	outfile << "int    mDay;\n\t";
	outfile << "int    mMonth;\n\t";
	outfile << "int	 mYear;\n\t";
	outfile << "char	*state;\n\t";
	outfile << "int	 quant;\n";
	outfile << "} 	sale_rec;\n";
	outfile << "EXEC SQL END DECLARE SECTION;" << endl;
	outfile << "EXEC SQL INCLUDE sqlca; \n \n \n \n";
	outfile << "void	output_record(); \n\n";
	outfile << "int main(int argc, char* argv[])\n";
	outfile << "{ \n\n";
	outfile << "\n\tint index = 1;" << endl;
	outfile << "\tEXEC SQL CONNECT TO jrodrig9 USER jrodrig9 IDENTIFIED BY Johny10353976;\n";
	outfile << "\tEXEC SQL WHENEVER sqlerror sqlprint;\n\n\n";
	
	//PRINT HEADER:
	outfile << "\tprintf(\" ";
	for (unsigned int i=0; i < mylist.size(); i++)
	{
		mylist[i]->getName();
		outfile << "\t| ";
	}
	outfile << "\\n\");\n \n \n" << endl;
	
	// FIRST SCAN
	outfile << "\tEXEC SQL DECLARE mycursor CURSOR FOR SELECT DISTINCT " << grouping_attr[0];
	for (unsigned int i=1; i < grouping_attr.size(); i++)
		outfile << ", " << grouping_attr[i];
	outfile << " FROM sales WHERE " << whereClause << ";\n";
	outfile << "\tEXEC SQL SET TRANSACTION read only;\n";
	outfile << "\tEXEC SQL OPEN mycursor;" << endl;
	outfile << "\tEXEC SQL FETCH FROM mycursor INTO :mf_structure[0]." << convertName(grouping_attr[0]);
	for (unsigned int i=1; i < grouping_attr.size(); i++)
		outfile << ", :mf_structure[0]." << convertName(grouping_attr[i]);
	
	outfile << ";\n\twhile (sqlca.sqlcode == 0)\n\t{\n";
	outfile << "\t\tEXEC SQL FETCH FROM mycursor INTO :mf_structure[index]." << convertName(grouping_attr[0]);
	for (unsigned int i=1; i < grouping_attr.size(); i++)
		outfile << ", :mf_structure[index]." << convertName(grouping_attr[i]);
	outfile << ";\n\t\tindex++;\n\t}\n";
	outfile << "\tEXEC SQL CLOSE mycursor;\n\n" << endl;
	outfile << "output_record();\n";
	
	for (unsigned int i=1; i <= numGroupingVars; i++)
	{
		outfile << "\t//A WHILE LOOP FOR VAR " << i << " WILL BE INSERTED HERE\n";
		outfile << "\tEXEC SQL DECLARE mycursor CURSOR FOR SELECT * FROM sales;\n";
		outfile << "\tEXEC SQL SET TRANSACTION read only;\n";
		outfile << "\tEXEC SQL OPEN mycursor;\n";
		outfile << "\tEXEC SQL FETCH FROM mycursor INTO :sale_rec;\n";
		outfile << "\twhile (sqlca.sqlcode == 0)\n\t{\n";
		outfile << "\t\tindex = 0;\n\t\t";
		outfile << "while (index <= 500)\n\t\t{\n\t\t\t";
		outfile << "if (mf_structure[index].";
		outfile << "\n\n\n";
	}
	outfile << "\treturn 0;\n}\n\n";
	outfile << "void output_record()\n{\n";
	outfile << "\tint i =0;\n";
	outfile << "\tfor (; i < 10; i++) \n\t{\n";
	outfile << "\t\tprintf(\" %-5s | \",mf_structure[i]." << convertName(grouping_attr[0]) << ");\n\t}\n}\n";
	
	
	
	

    PQfinish(conn);

	return 0; 
}