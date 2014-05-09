/* Processed by ecpg (4.5.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "output.pgc"
#include	<stdio.h>

/* exec sql begin declare section */


		
		
		
		
		
		
 

#line 12 "output.pgc"
 struct { 
#line 6 "output.pgc"
 char prod [ 21 ] ;
 
#line 7 "output.pgc"
 int mMonth ;
 
#line 8 "output.pgc"
 int mYear ;
 
#line 9 "output.pgc"
 int cnt1 ;
 
#line 10 "output.pgc"
 int cnt2 ;
 
#line 11 "output.pgc"
 int avg1 ;
 } mf_structure [ 500 ] ;
/* exec sql end declare section */
#line 13 "output.pgc"


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

#line 14 "output.pgc"
 
 
 
 
void	output_record(); 

int main(int argc, char* argv[])
{ 

	{ ECPGconnect(__LINE__, 0, "jrodrig9" , "jrodrig9" , "Johny10353976" , NULL, 0); }
#line 23 "output.pgc"

	/* exec sql whenever sqlerror  sqlprint ; */
#line 24 "output.pgc"



	printf(" prod	| month	| year	| cnt1	| cnt2	| avg1	| \n");
 
 

	/* declare mycursor cursor for select distinct prod , month , year from sales where year = 1997 */
#line 31 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 32 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 32 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for select distinct prod , month , year from sales where year = 1997", ECPGt_EOIT, ECPGt_EORT);
#line 33 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 33 "output.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[0].prod),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[0].mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[0].mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 34 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 34 "output.pgc"

	int index = 1;
	while (sqlca.sqlcode == 0)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(mf_structure[index].prod),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mMonth),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mf_structure[index].mYear),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 38 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 38 "output.pgc"

		index++;
	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);
#line 41 "output.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 41 "output.pgc"



output_record();
	//A WHILE LOOP FOR VAR 1 WILL BE INSERTED HERE
	//A WHILE LOOP FOR VAR 2 WILL BE INSERTED HERE
	//A WHILE LOOP FOR VAR 3 WILL BE INSERTED HERE
	return 0;
}

void output_record()
{
	int i =0;
	for (; i < 10; i++) 
	{
		printf(" %-5s | ",mf_structure[i].prod);
		printf(" %-5i | ",mf_structure[i].mMonth);
		printf(" %-5i | \n",mf_structure[i].mYear);
	}
}
