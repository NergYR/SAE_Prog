#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

/// @brief Fonction qui permet de lire la ligne et extraire l'ip, le timestamp, request et user_agent
/// @param file fichier log, log_line stucture
struct log_line scanLine(FILE *file, struct log_line *log_line) {
    char line[512];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%15s - - [%31[^]]] \"%255[^\"]\" %*d %*d \"%255[^\"]\"\n",
                   log_line->ip, log_line->timestamp, log_line->request, log_line->user_agent) == 4) {
            return *log_line;
        }
    }

    memset(log_line, 0, sizeof(struct log_line));
    return *log_line;
};
void versiontexte(){
    printf("Nombre de requetes POST : %d\n", results().rq_get);
    printf("Nombre de requetes GET : %d\n", results().rq_get);
    printf("Nombre de requetes HEAD : %d\n", results().rq_header);
    printf("Nombre de requetes inconnues : %d\n", results().rq_unknown);
    printf("Nombre de requetes en Decembre: %d\n", results().dec);
    printf("Nombre de requetes en Janvier: %d\n", results().jan);
    printf("Nombre de requetes en Fevrier: %d\n", results().feb);
    printf("Nombre de requetes en Mars: %d\n", results().mar);
    printf("Nombre de requetes en Avril: %d\n", results().apr);
    printf("Nombre de requetes en Mai: %d\n", results().may);
    printf("Nombre de requetes en Juin: %d\n", results().jun);
    printf("Nombre de requetes en Juillet: %d\n", results().jul);
    printf("Nombre de requetes en Aout: %d\n", results().aug);
    printf("Nombre de requetes en Septembre: %d\n", results().sep);
    printf("Nombre de requetes en Octobre: %d\n", results().oct);
    printf("Nombre de requetes en Novembre: %d\n", results().nov);
    printf("Nombre de requetes depuis HTTPS: %d\n", results().secure_http_response);
}

int versiongraphique(){
    printf("Version graphique\n");
    return EXIT_SUCCESS;

}
int versionweb(){
    printf("Version web\n");
    return EXIT_SUCCESS;

}
