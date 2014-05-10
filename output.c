/* Processed by ecpg (4.5.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "output.pgc"
#include	<stdio.h>

/* exec sql begin declare section */


		
		
		
		
		
		
		
  




		
		
	    
	    
		 
		
		 
 	


#line 13 "output.pgc"
 struct { 
#line 6 "output.pgc"
 char prod [ 21 ] ;
 
#line 7 "output.pgc"
 int mMonth ;
 
#line 8 "output.pgc"
 int mYear ;
 
#line 9 "output.pgc"
 int avg_quant_1 ;
 
#line 10 "output.pgc"
 int cnt_quant_2 ;
 
#line 11 "output.pgc"
 int max_quant_1 ;
 
#line 12 "output.pgc"
 int sum_quant_3 ;
 } mf_structure [ 500 ] ;
 
#line 25 "output.pgc"
 struct { 
#line 18 "output.pgc"
 char * cust ;
 
#line 19 "output.pgc"
 char * prod ;
 
#line 20 "output.pgc"
 int mDay ;
 
#line 21 "output.pgc"
 int mMonth ;
 
#line 22 "output.pgc"
 int mYear ;
 
#line 23 "output.pgc"
 char * state ;
 
#line 24 "output.pgc"
 int quant ;
 } sale_rec ;
/* exec sql end declare section */
#line 27 "output.pgc"


#line 1 "/usr/include/postgresql/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif   /* __CYGWIN__ */
#endif   /* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern		"C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.				*/

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 28 "output.pgc"
 
 
 
 
void	output_record(); 

int main(int argc, char* argv[])
{ 


	int index = 0;
	int count = 0;
	int sum = 0;
	{ ECPGconnect(__LINE__, 0, "jrodrig9" , "jrodrig9" , "Johny10353976" , NULL, 0); }
#line 41 "output.pgc"

	/* exec sql whenever sqlerror  sqlprint ; */
#line 42 "output.pgc"



	printf(" prod	| mMonth	| mYear	| avg_quant_1	| cnt_quant_2	| max_quant_1	| sum_quant_3	| \n");
 
 

	/* declare mycursor cursor for select distinct prod , month , year from sales where year = 1997 */
#line 49 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 50 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 50 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for select distinct prod , month , year from sales where year = 1997", ECPGt_EOIT, ECPGt_EORT);
#line 51 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 51 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[index].prod),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 52 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 52 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		mf_structure[index].avg_quant_1 = 0;
		mf_structure[index].cnt_quant_2 = 0;
		mf_structure[index].max_quant_1 = 0;
		mf_structure[index].sum_quant_3 = 0;
		index++;
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[index].prod),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 60 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 60 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);
#line 62 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 62 "output.pgc"



	//A WHILE LOOP FOR VAR 1
	count = 0;
	sum = 0;
	/* declare mycursor1 cursor for select * from sales */
#line 68 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 69 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 69 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor1 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 70 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 70 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor1", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mDay),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.quant),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 71 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 71 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (strcmp(mf_structure[index].prod, "Eggs") == 0 && sale_rec.mYear == 1997)
			{
					sum = sum + sale_rec.quant;
					count++;
 					mf_structure[index].avg_quant_1= sum/count;
					if ( sale_rec.quant > mf_structure[index].max_quant_1)
					{
						mf_structure[index].max_quant_1 = sale_rec.quant;
					}
			}
			index++;
		}
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor1", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mDay),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.quant),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 89 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 89 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor1", ECPGt_EOIT, ECPGt_EORT);
#line 91 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 91 "output.pgc"





	//A WHILE LOOP FOR VAR 2
	count = 0;
	sum = 0;
	/* declare mycursor2 cursor for select * from sales */
#line 99 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 100 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 100 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor2 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 101 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 101 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor2", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mDay),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.quant),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 102 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 102 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (strcmp(mf_structure[index].prod, "Pepsi") == 0)
			{
					mf_structure[index].cnt_quant_2++;
			}
			index++;
		}
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor2", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mDay),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.quant),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 114 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 114 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor2", ECPGt_EOIT, ECPGt_EORT);
#line 116 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 116 "output.pgc"





	//A WHILE LOOP FOR VAR 3
	count = 0;
	sum = 0;
	/* declare mycursor3 cursor for select * from sales */
#line 124 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 125 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 125 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor3 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 126 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 126 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor3", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mDay),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.quant),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 127 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 127 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (strcmp(mf_structure[index].prod, "Eggs") == 0)
			{
					mf_structure[index].sum_quant_3 = mf_structure[index].sum_quant_3 + sale_rec.quant;
			}
			index++;
		}
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor3", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mDay),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sale_rec.quant),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 139 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 139 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor3", ECPGt_EOIT, ECPGt_EORT);
#line 141 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 141 "output.pgc"





	output_record();
	return 0;
}

void output_record()
{
	int i =0;
	for (; i < 500; i++) 
	{
	if (strcmp(mf_structure[i].prod, "") != 0)
	{
		printf(" %-5s | ",mf_structure[i].prod);
		printf(" %-5d | ",mf_structure[i].mMonth);
		printf(" %-5d | ",mf_structure[i].mYear);
		printf(" %-5d | ",mf_structure[i].avg_quant_1);
		printf(" %-5d | ",mf_structure[i].cnt_quant_2);
		printf(" %-5d | ",mf_structure[i].max_quant_1);
		printf(" %-5d | ",mf_structure[i].sum_quant_3);
		printf("\n");
	}

	}
}
