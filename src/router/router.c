#include <stdio.h>
#include "query_classifier.h"
#include "../connection/db.h"

void route_query(const char* query)
{
const char* primary_conn = "host=127.0.0.1 port=5432 user=postgres password=1234";
const char* replica_conn = "host=127.0.0.1 port=5433 user=postgres password=1234";

    if (is_read_query(query))
    {
        printf("→ REPLICA\n");
        execute_query(replica_conn, query);
    }
    else
    {
        printf("→ PRIMARY\n");
        execute_query(primary_conn, query);
    }
}