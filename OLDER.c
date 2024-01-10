#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct log_line
{
    char ip[16];
    char timestamp[32];
    char request[256];
    char user_agent[256];
}log_line;


struct log_line scanLine(){
    FILE *file = fopen("access_statique.log", "r");

    if (file == NULL)
    {
        perror("Erreur d'ouverture du fichier");
    }
    char line[512];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%15s - - [%31[^]]] \"%255[^\"]\" %*d %*d \"%255[^\"]\"\n",
                   log_line.ip, log_line.timestamp, log_line.request, log_line.user_agent) == 4) return log_line;
    }
    fclose(file);
}




int main()
{
    scanLine();


    int jan = 0;
    int feb = 0;
    int mar = 0;
    int apr = 0;
    int may = 0;
    int jun = 0;
    int jul = 0;
    int aug = 0;
    int sep = 0;
    int oct = 0;
    int nov = 0;
    int dec = 0;
    int rq_post = 0;
    int rq_get = 0;
    int rq_header = 0;
    int rq_unknown = 0;
    int sql_injection = 0;
    int total = 0;

    char line[512];
    // printf("IP: %s\n", ip);
    // printf("Timestamp: %s\n", timestamp);
    // printf("Request: %s\n", request);

    if (strstr(log_line.request, "POST") != NULL)
    {
        rq_post++;
    }
    else if (strstr(log_line.request, "GET") != NULL)
    {
        rq_get++;
    }
    else if (strstr(log_line.request, "HEAD") != NULL)
    {
        rq_header++;
    }
    else
    {
        rq_unknown++;
    }
    if (strstr(log_line.timestamp, "Dec") != NULL)
    {
        dec++;
    }
    if (strstr(log_line.timestamp, "Nov") != NULL)
    {
        nov++;
    }
    if (strstr(log_line.timestamp, "Oct") != NULL)
    {
        oct++;
    }
    if (strstr(log_line.timestamp, "Sep") != NULL)
    {
        sep++;
    }
    if (strstr(log_line.timestamp, "Aug") != NULL)
    {
        aug++;
    }
    if (strstr(log_line.timestamp, "Jul") != NULL)
    {
        jul++;
    }
    if (strstr(log_line.timestamp, "Jun") != NULL)
    {
        jun++;
    }
    if (strstr(log_line.timestamp, "May") != NULL)
    {
        may++;
    }
    if (strstr(log_line.timestamp, "Apr") != NULL)
    {
        apr++;
    }
    if (strstr(log_line.timestamp, "Mar") != NULL)
    {
        mar++;
    }
    if (strstr(log_line.timestamp, "Feb") != NULL)
    {
        feb++;
    }
    if (strstr(log_line.timestamp, "Jan") != NULL)
    {
        jan++;
    }
    total++;

    printf("\n");
    printf("\n");
    printf("Nombre de requetes POST : %d\n", rq_post);
    printf("Nombre de requetes GET : %d\n", rq_get);
    printf("Nombre de requetes HEAD : %d\n", rq_header);
    printf("Nombre de requetes inconnues : %d\n", rq_unknown);
    printf("Nombre de requetes en decembre : %d\n", dec);
    printf("Nombre de requetes en novembre : %d\n", nov);
    printf("Nombre de requetes en octobre : %d\n", oct);
    printf("Nombre de requetes en septembre : %d\n", sep);
    printf("Nombre de requetes en aout : %d\n", aug);
    printf("Nombre de requetes en juillet : %d\n", jul);
    printf("Nombre de requetes en juin : %d\n", jun);
    printf("Nombre de requetes en mai : %d\n", may);
    printf("Nombre de requetes en avril : %d\n", apr);
    printf("Nombre de requetes en mars : %d\n", mar);
    printf("Nombre de requetes en fevrier : %d\n", feb);
    printf("Nombre de requetes en janvier : %d\n", jan);
    printf("Nombre de requetes total : %d\n", total);


    return 0;
}