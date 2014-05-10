/* Processed by ecpg (4.5.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "output.pgc"
#include	<stdio.h>

/* exec sql begin declare section */


		
		
		
		
  




		
		
	    
	    
		 
		
		 
 	


#line 10 "output.pgc"
 struct { 
#line 6 "output.pgc"
 char cust [ 21 ] ;
 
#line 7 "output.pgc"
 int sum_quant_1 ;
 
#line 8 "output.pgc"
 int sum_quant_2 ;
 
#line 9 "output.pgc"
 int sum_quant_3 ;
 } mf_structure [ 500 ] ;
 
#line 22 "output.pgc"
 struct { 
#line 15 "output.pgc"
 char * cust ;
 
#line 16 "output.pgc"
 char * prod ;
 
#line 17 "output.pgc"
 int mDay ;
 
#line 18 "output.pgc"
 int mMonth ;
 
#line 19 "output.pgc"
 int mYear ;
 
#line 20 "output.pgc"
 char * state ;
 
#line 21 "output.pgc"
 int quant ;
 } sale_rec ;
/* exec sql end declare section */
#line 24 "output.pgc"


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

#line 25 "output.pgc"
 
 
 
 
void	output_record(); 

int main(int argc, char* argv[])
{ 


	int index = 0;
	int count = 0;
	int sum = 0;
	{ ECPGconnect(__LINE__, 0, "jrodrig9" , "jrodrig9" , "Johny10353976" , NULL, 0); }
#line 38 "output.pgc"

	/* exec sql whenever sqlerror  sqlprint ; */
#line 39 "output.pgc"



	printf(" cust	| sum_quant_1	| sum_quant_2	| sum_quant_3	| \n");
 
 

	/* declare mycursor cursor for select distinct cust from sales where 1 = 1 */
#line 46 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 47 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 47 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for select distinct cust from sales where 1 = 1", ECPGt_EOIT, ECPGt_EORT);
#line 48 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 48 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[index].cust),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 49 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 49 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		mf_structure[index].sum_quant_1 = 0;
		mf_structure[index].sum_quant_2 = 0;
		mf_structure[index].sum_quant_3 = 0;
		index++;
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[index].cust),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 56 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 56 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);
#line 58 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 58 "output.pgc"



	//A WHILE LOOP FOR VAR 1
	count = 0;
	sum = 0;
	/* declare mycursor1 cursor for select * from sales */
#line 64 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 65 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 65 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor1 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 66 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 66 "output.pgc"

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
#line 67 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 67 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (strcmp(sale_rec.state, "NY") == 0)
			{
					mf_structure[index].sum_quant_1 = mf_structure[index].sum_quant_1 + sale_rec.quant;
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
#line 79 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 79 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor1", ECPGt_EOIT, ECPGt_EORT);
#line 81 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 81 "output.pgc"





	//A WHILE LOOP FOR VAR 2
	count = 0;
	sum = 0;
	/* declare mycursor2 cursor for select * from sales */
#line 89 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 90 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 90 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor2 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 91 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 91 "output.pgc"

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
#line 92 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 92 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (strcmp(sale_rec.state, "NJ") == 0)
			{
					mf_structure[index].sum_quant_2 = mf_structure[index].sum_quant_2 + sale_rec.quant;
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
#line 104 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 104 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor2", ECPGt_EOIT, ECPGt_EORT);
#line 106 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 106 "output.pgc"





	//A WHILE LOOP FOR VAR 3
	count = 0;
	sum = 0;
	/* declare mycursor3 cursor for select * from sales */
#line 114 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 115 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 115 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor3 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 116 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 116 "output.pgc"

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
#line 117 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 117 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (strcmp(sale_rec.state, "CT") == 0)
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
#line 129 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 129 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor3", ECPGt_EOIT, ECPGt_EORT);
#line 131 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 131 "output.pgc"





	output_record();
	return 0;
}

void output_record()
{
	int i =0;
	for (; i < 500; i++) 
	{
	if (strcmp(mf_structure[i].cust, "") != 0)
	{
		printf(" %-5s | ",mf_structure[i].cust);
		printf(" %-5d | ",mf_structure[i].sum_quant_1);
		printf(" %-5d | ",mf_structure[i].sum_quant_2);
		printf(" %-5d | ",mf_structure[i].sum_quant_3);
		printf("\n");
	}

	}
}
