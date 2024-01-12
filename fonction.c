#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include "lib/libgraphique.h"


struct log_line scanLine(FILE *file, struct log_line *log_line)
{
    char line[512];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%15s - - [%31[^]]] \"%255[^\"]\" %*d %*d \"%255[^\"]\"\n",
                   log_line->ip, log_line->timestamp, log_line->request, log_line->user_agent) == 4)
        {
            return *log_line;
        }
    }

    memset(log_line, 0, sizeof(struct log_line));
    return *log_line;
};



