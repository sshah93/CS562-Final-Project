#include "header.h"

/* class name */
class AgrObjects
{
public:
	/* class attributes */
	string colName;
	string dataType;
	string fnName;
	int num;
	int maxlength;

	/* class constructor */
	Agr(string column_name, string function_name, int num) :
		colName(column_name),
		fnName(function_name),
		num(num),
		maxlength(-1)
	{

	}

	/* class destructor */
	virtual ~Agr()
	{

	}

	/* setter method for data type attribute */
	void setDataType(string mType)
	{
		dataType = mType;
	}

	/* setter method for max length attribute */
	void setMaxLength(int len)
	{
		maxlength = len;
	}
	
	/* setter method for name attribute */
	void getName()
	{
		if (fnName == "none")
		{
			if (colName == "month")
			{
				outfile << "mMonth";
			}

			else if (colName == "year")
			{
				outfile << "mYear";
			}

			else if (colName == "day")
			{
				outfile << "mDay";
			}	

			else
			{
				outfile << colName;
			}	
		}

		else
		{
			outfile << fnName << "_" << colName << "_" << num;
		}			
	}
	
	/* Pre: function takes in no argument */
	/* Post: function doesn't return anything */
	/* Description: prints out the mfstruct in output file */
	void printMFStruct()
	{
		outfile << "\t";
		
		if (fnName == "cnt")
		{
			outfile << "int\t";
		}

		else
		{
			outfile << dataType << "\t";
		}
		
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
		{
			outfile << fnName << "_" << colName << "_" << num;
		}
		
		if (maxlength <= 0)
		{
			outfile << ";" << endl;
		}

		else
		{
			outfile << "[" << maxlength << "];" << endl;
		}
	}
	
	/* Pre: function takes in no argument */
	/* Post: function doesn't return anything */
	/* Description: initializes the function name and prints in the output file */
	void initAgVariables()
	{
		if (fnName == "none")
		{
			return;
		}
		
		else
		{
			outfile << "\t\tmf_structure[index]." << fnName << "_" << colName << "_" << num << " = 0;\n";
		}
	}
	
	/* Pre: function takes in an int */
	/* Post: function doesn't return anything */
	/* Description: prints out for all the aggregate functions the syntax to compute it */
	void outputFunction(int i)
	{
		if (i != num || fnName == "none")
		{
			return;
		}
			
		else
		{
			string temp;
			string thisName;

			if (fnName == "avg")
			{
				outfile << "\t\t\t\t\tsum = sum + " << "sale_rec." << colName << ";\n";
				outfile << "\t\t\t\t\tcount++;\n ";
				outfile << "\t\t\t\t\tmf_structure[index]."<< fnName << "_" << colName << "_" << num << "= sum/count;\n";	
			}
			
			else if (fnName == "sum")
			{
				outfile << "\t\t\t\t\tmf_structure[index]."<< fnName << "_" << colName << "_" << num;
				outfile << " = mf_structure[index]." << fnName << "_" << colName << "_" << num << " + sale_rec." << colName << ";\n";
			}
			
			else if (fnName == "max")
			{
				outfile << "\t\t\t\t\tif ( sale_rec." << colName << " > mf_structure[index]." << fnName << "_" << colName << "_" << num << ")\n\t\t\t\t\t{\n";
				outfile << "\t\t\t\t\t\tmf_structure[index]." << fnName << "_" << colName << "_" << num << " = sale_rec." << colName << ";\n\t\t\t\t\t}\n";
			}
			
			else if (fnName == "min")
			{
				outfile << "\t\t\t\t\tif ( mf_structure[index]." << fnName << "_" << colName << "_" << num << " == 0)\n\t\t\t\t\t{\n";
				outfile << "\t\t\t\t\t\tmf_structure[index]." << fnName << "_" << colName << "_" << num << "= sale_rec." << colName << ";\n\t\t\t\t\t}\n";
				outfile << "\t\t\t\t\tif ( sale_rec." << colName << " < mf_structure[index]." << fnName << "_" << colName << "_" << num << ")\n\t\t\t\t\t{\n";
				outfile << "\t\t\t\t\t\tmf_structure[index]." << fnName << "_" << colName << "_" << num << "= sale_rec." << colName << ";\n\t\t\t\t\t}\n";
			}
			
			else if (fnName == "cnt")
			{
				outfile << "\t\t\t\t\tmf_structure[index]."<< fnName << "_" << colName << "_" << num <<"++;\n";
			}
		}
	}
};