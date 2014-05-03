#include <iostream>
#include <postgresql/libpq-fe.h>
#include <string>
#include <stdlib.h> 

using namespace std;

int     main() {
PGconn          *conn;
PGresult        *res;
int             rec_count;
int             row;
int             col;



         conn = PQconnectdb("dbname=jrodrig9 host=postgres.cs.stevens.edu user=jrodrig9 password=Johny10353976");

        if (PQstatus(conn) == CONNECTION_BAD) {
                puts("We were unable to connect to the database");
                return 0;
        }

       res = PQexec(conn,
              "SELECT column_name, data_type, character_maximum_length FROM information_schema.columns WHERE table_name = 'sales'");

		if (PQresultStatus(res) != PGRES_TUPLES_OK) {
               puts("We did not get any data!");
               return 0;
		}

		rec_count = PQntuples(res);

		printf("struct{       \n");

		for (row=0; row<rec_count; row++) {
				
			if (atoi(PQgetvalue(res, row, 2)) <= 0)
			{
				if (string(PQgetvalue(res, row, 1)) == "integer")
					printf("int\t");
				else 
					printf("%s\t",PQgetvalue(res, row, 1));
				printf("%s; \n",PQgetvalue(res, row, 0));   // Column
			}
				
			else
			{
				printf("char\t");
				printf("%s",PQgetvalue(res, row, 0));   // Column
				printf("[%i]; \n",atoi(PQgetvalue(res, row, 2))+1);
			}
       }
		printf("} mf_structure[500] \n");
 
		PQclear(res);

        PQfinish(conn);

         return 0; 
}