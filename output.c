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



	printf(" prod	| month	| year	| avg1	| cnt2	| max1	| sum3	| \n");
 
 
	printf("womp4");
	/* declare mycursor cursor for select distinct prod , month , year from sales where year = 1997 */
#line 49 "output.pgc"

	printf("womp3");
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 51 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 51 "output.pgc"

	printf("womp2");
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for select distinct prod , month , year from sales where year = 1997", ECPGt_EOIT, ECPGt_EORT);
#line 53 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 53 "output.pgc"

	printf("womp1");
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[index].prod),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 55 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 55 "output.pgc"

	printf("womp");
	while (sqlca.sqlcode == 0)
	{
		
		//mf_structure[index].avg_quant_1 = 0;
		//mf_structure[index].cnt_quant_2 = 0;
		//mf_structure[index].max_quant_1 = 0;
		//mf_structure[index].sum_quant_3 = 0;
		index++;
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[index].prod),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 65 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 65 "output.pgc"

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);
#line 67 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 67 "output.pgc"


	
	output_record();
	//A WHILE LOOP FOR VAR 1
	count = 0;
	sum = 0;
	/* declare mycursor1 cursor for select * from sales */
#line 74 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 75 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 75 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor1 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 76 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 76 "output.pgc"

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
#line 77 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 77 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (sale_rec.state == 'NY' && sale_rec.mYear == 1997 && sale_rec.prod == mf_structure[index].prod)
			{
					sum = sum + sale_rec.quant;
					count++;
 					mf_structure[index].avg_quant_1= sum/count;
					if ( sale_rec.quant > mf_structure[index].max_quant_1)
					{
						mf_structure[index].max_quant_1 = sale_rec.quant;
					}
			}
		}
	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor1", ECPGt_EOIT, ECPGt_EORT);
#line 95 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 95 "output.pgc"






	//A WHILE LOOP FOR VAR 2
	count = 0;
	sum = 0;
	/* declare mycursor2 cursor for select * from sales */
#line 104 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 105 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 105 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor2 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 106 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 106 "output.pgc"

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
#line 107 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 107 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (sale_rec.state=='CT')
			{
					mf_structure[index].cnt_quant_2++;
			}
		}
	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor2", ECPGt_EOIT, ECPGt_EORT);
#line 119 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 119 "output.pgc"






	//A WHILE LOOP FOR VAR 3
	count = 0;
	sum = 0;
	/* declare mycursor3 cursor for select * from sales */
#line 128 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 129 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 129 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor3 cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 130 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 130 "output.pgc"

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
#line 131 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 131 "output.pgc"

	while (sqlca.sqlcode == 0)
	{
		index = 0;
		while (index <= 500)
		{
			if (sale_rec.state=='NJ')
			{
					mf_structure[index].sum_quant_3 = mf_structure[index].sum_quant_3 + sale_rec.quant;
			}
		}
	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor3", ECPGt_EOIT, ECPGt_EORT);
#line 143 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 143 "output.pgc"






	return 0;
}

void output_record()
{
}
