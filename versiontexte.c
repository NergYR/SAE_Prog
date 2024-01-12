#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include "lib/libgraphique.h"

void versiontexte()
{
   int totalRequests = results().total;

    printf("Nombre de requetes POST : %.2f%%\n", (float)results().rq_post / totalRequests * 100);
    printf("Nombre de requetes GET : %.2f%%\n", (float)results().rq_get / totalRequests * 100);
    printf("Nombre de requetes HEAD : %.2f%%\n", (float)results().rq_header / totalRequests * 100);
    printf("Nombre de requetes inconnues : %.2f%%\n", (float)results().rq_unknown / totalRequests * 100);
    printf("Nombre de requetes en Decembre: %.2f%%\n", (float)results().dec / totalRequests * 100);
    printf("Nombre de requetes en Janvier: %.2f%%\n", (float)results().jan / totalRequests * 100);
    printf("Nombre de requetes en Fevrier: %.2f%%\n", (float)results().feb / totalRequests * 100);
    printf("Nombre de requetes en Mars: %.2f%%\n", (float)results().mar / totalRequests * 100);
    printf("Nombre de requetes en Avril: %.2f%%\n", (float)results().apr / totalRequests * 100);
    printf("Nombre de requetes en Mai: %.2f%%\n", (float)results().may / totalRequests * 100);
    printf("Nombre de requetes en Juin: %.2f%%\n", (float)results().jun / totalRequests * 100);
    printf("Nombre de requetes en Juillet: %.2f%%\n", (float)results().jul / totalRequests * 100);
    printf("Nombre de requetes en Aout: %.2f%%\n", (float)results().aug / totalRequests * 100);
    printf("Nombre de requetes en Septembre: %.2f%%\n", (float)results().sep / totalRequests * 100);
    printf("Nombre de requetes en Octobre: %.2f%%\n", (float)results().oct / totalRequests * 100);
    printf("Nombre de requetes en Novembre: %.2f%%\n", (float)results().nov / totalRequests * 100);
    printf("Nombre de requetes depuis HTTPS: %.2f%%\n", (float)results().secure_http_response / totalRequests * 100);

}

