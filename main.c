#include <stdio.h>
#include "src/router/router.h"

int main()
{
    char query1[] = "SELECT * FROM users;";
    char query2[] = "INSERT INTO users VALUES (1);";

    route_query(query1);
    route_query(query2);

    return 0;
}