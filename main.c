#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main() {
    
    

    // Affichage des résultats
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



    return 0;
}
