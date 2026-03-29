#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_read_query(const char* query)
{
    while (isspace(*query)) query++;  // skip spaces

    if (strncasecmp(query, "SELECT", 6) == 0)
        return 1;

    if (strncasecmp(query, "SHOW", 4) == 0)
        return 1;

    if (strncasecmp(query, "DESCRIBE", 8) == 0)
        return 1;

    return 0; // write query
}