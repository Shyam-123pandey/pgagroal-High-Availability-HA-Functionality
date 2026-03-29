#include <stdio.h>
#include <libpq-fe.h>

void execute_query(const char* conninfo, const char* query)
{
    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK)
    {
        printf("Connection failed: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return;
    }

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) == PGRES_TUPLES_OK)
    {
        int rows = PQntuples(res);
        int cols = PQnfields(res);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%s ", PQgetvalue(res, i, j));
            }
            printf("\n");
        }
    }
    else
    {
        printf("Query executed.\n");
    }

    PQclear(res);
    PQfinish(conn);
}