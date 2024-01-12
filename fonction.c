#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include "lib/libgraphique.h"

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

typedef struct
{
    int jan;
    int feb;
    int mar;
    int apr;
    int may;
    int jun;
    int jul;
    int aug;
    int sep;
    int oct;
    int nov;
    int dec;
    int total;
} Results;
int max_mois(Results *resultats)
{
    int max = resultats->jan;

    int mois[12] = {resultats->feb, resultats->mar, resultats->apr, resultats->may, resultats->jun,
                    resultats->jul, resultats->aug, resultats->sep, resultats->oct, resultats->nov, resultats->dec};

    for (int i = 0; i < 12; i++)
    {
        if (mois[i] > max)
        {
            max = mois[i];
        }
    }

    return max;
}

void dessiner_rectangle_barre(Point point, int largeur, int hauteur, Couleur couleur)
{
    // Remplacez cette fonction par votre fonction de dessin de rectangle
}

void afficher_texte_barre(char *texte, int taille, Point point, Couleur couleur)
{
    // Remplacez cette fonction par votre fonction d'affichage de texte
}

void calculer_statistiques(Results *resultats)
{
    // Ajoutez ici votre logique de calcul des statistiques
}

void versiongraphique(Results *resultats)
{
    printf("Version graphique\n");
    Point p = {30, 50};
    ouvrir_fenetre(430, 350);
    dessiner_rectangle((Point){0, 0}, 430, 350, blanc);

    char mois[12][4] = {"Jan", "Fev", "Mar", "Avr", "Mai", "Juin", "Juil", "Aou", "Sep", "Oct", "Nov", "Dec"};

    afficher_texte("Depuis le 01/Jan/2018 on a enregistré 998 connexions.", 12, p, noir);

    p.y = 300;
    afficher_texte(" Jan  Fev  Mar  Avr  Mai  Juin  Juil  Aou  Sep  Oct  Nov  Dec", 14, p, vert);

    int i, x = 30, largeur = 30, decalage = 31;
    int max_value = max_mois(resultats);

    for (i = 0; i < 12; i++)
    {
        int hauteur = (resultats->jan * 300) / max_value; // Ajustez le facteur selon votre besoin
        dessiner_rectangle_barre((Point){x, 221 - hauteur}, largeur, hauteur, orange);
        afficher_texte_barre(mois[i], 14, (Point){x + 5, 235}, blanc);
        x += decalage;
    }

    actualiser();
    attendre_clic();
    fermer_fenetre();

    // Ajout du calcul et de l'affichage des statistiques
    calculer_statistiques(resultats);
    affichestatistiques(resultats);
}

void affichestatistiques(Results *resultats)
{
    char *nommois[12] = {"Jan", "Fev", "Mar", "Avr", "Mai", "Juin", "Juil", "Aou", "Sep", "Oct", "Nov", "Dec"};

    for (int local_c = 0; local_c < 12; local_c++)
    {
        printf("%10s : %4.1f%%\n", nommois[local_c], ((float)resultats->jan * 100.0) / (float)resultats->total);

    }
}


int versionweb(){
    printf("Version web\n");
    return EXIT_SUCCESS;

}
