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
int max_rq(Results *resultats) {
    int max = resultats->rq_post;

    int rq[5] = {resultats->rq_get, resultats->rq_post, resultats->rq_header, resultats->rq_unknown, resultats->secure_http_response};

    for (int i = 0; i < 5; i++) {
        if (rq[i] > max) {
            max = rq[i];
        }
    }

    return max;
}




void versiongraphique_m(Results *resultats)
{
    printf("Version graphique\n");
    Point p = {30, 50};
    ouvrir_fenetre(430, 350);
    dessiner_rectangle((Point){0, 0}, 430, 350, blanc);

    char mois[12][4] = {"Jan", "Fev", "Mar", "Avr", "Mai", "Juin", "Juil", "Aou", "Sep", "Oct", "Nov", "Dec"};

    afficher_texte("Stats Selon les mois", 12, p, noir);

    p.y = 300;
    afficher_texte(" Jan  Fev  Mar  Avr  Mai  Juin  Juil  Aou  Sep  Oct  Nov  Dec", 14, p, vert);

    int x = 30, largeur = 30, decalage = 31;
    int max_value = max_mois(resultats);

    for (int i = 0; i < 12; i++)
    {
        int hauteur;

        switch (i)
        {
        case 0:
            hauteur = (resultats->jan * 100) / max_value;
            break;
        case 1:
            hauteur = (resultats->feb * 100) / max_value;
            break;
        case 2:
            hauteur = (resultats->mar * 100) / max_value;
            break;
        case 3:
            hauteur = (resultats->apr * 100) / max_value;
            break;
        case 4:
            hauteur = (resultats->may * 100) / max_value;
            break;
        case 5:
            hauteur = (resultats->jun * 100) / max_value;
            break;
        case 6:
            hauteur = (resultats->jul * 100) / max_value;
            break;
        case 7:
            hauteur = (resultats->aug * 100) / max_value;
            break;
        case 8:
            hauteur = (resultats->sep * 100) / max_value;
            break;
        case 9:
            hauteur = (resultats->oct * 100) / max_value;
            break;
        case 10:
            hauteur = (resultats->nov * 100) / max_value;
            break;
        case 11:
            hauteur = (resultats->dec * 100) / max_value;
            break;
        default:
            break;
        }

        dessiner_rectangle((Point){x, 221 - hauteur}, largeur, hauteur, orange);
        afficher_texte(mois[i], 14, (Point){x + 5, 235}, blanc);
        x += decalage;
    }

    actualiser();
    attendre_clic();
    fermer_fenetre();

}

void versiongraphique_rq(Results *resultats)
{
    printf("Version graphique - Statistiques sur les types de requêtes\n");
    Point p = {30, 50};
    ouvrir_fenetre(430, 350);
    dessiner_rectangle((Point){0, 0}, 430, 350, blanc);

    char types_requetes[5][20] = {"rq_post", "rq_get", "rq_header", "rq_unknown", "secure_http_response"};
    afficher_texte("Stats Selon les Requetes", 12, p, noir);


    p.y = 300;
    afficher_texte(" Post  Get  Header  Inconnu  HTTPS", 14, p, vert);

    int x = 30, largeur = 30, decalage = 31;
    int max_value = max_rq(resultats);

    for (int i = 0; i < 6; i++)
    {
        float hauteur;

        switch (i)
        {
        case 0:
            hauteur = (resultats->rq_post * 100) / max_value;
            if (hauteur == 0){
                hauteur = (resultats->rq_post * 100) % max_value;
                hauteur = hauteur / 100;
            }
            printf("hauteur : %f\n", hauteur);
            break;
        case 1:
            hauteur = (resultats->rq_get * 100) / max_value;
            break;
        case 2:
            hauteur = (resultats->rq_header * 100) / max_value;
            if (hauteur == 0){
                hauteur = (resultats->rq_header * 100) % max_value;
                hauteur = hauteur / 10000;
            }
            break;
        case 3:
            hauteur = (resultats->rq_unknown * 100)/ max_value;
            if(hauteur == 0){
                hauteur = (resultats->rq_unknown * 100) % max_value;
                hauteur = hauteur / 10000;
            }
            break;
        case 4:
            hauteur = (resultats->secure_http_response * 100) / max_value;
            if(hauteur == 0){
                hauteur = (resultats->secure_http_response * 100) % max_value;
                hauteur = hauteur / 10000;
            }
            break;
        default:
            break;
        }        


        dessiner_rectangle((Point){x, 221 - hauteur}, largeur, hauteur, orange);
        afficher_texte(types_requetes[i], 14, (Point){x + 5, 235}, blanc);
        x += decalage;
    }

    actualiser();
    attendre_clic();
    fermer_fenetre();
}


void affichestatistiques(Results *resultats)
{
    char *nommois[12] = {"Jan", "Fev", "Mar", "Avr", "Mai", "Juin", "Juil", "Aou", "Sep", "Oct", "Nov", "Dec"};

    for (int local_c = 0; local_c < 12; local_c++)
    {
        printf("%10s : %4.1f%%\n", nommois[local_c], ((float)resultats->jan * 100.0) / (float)resultats->total);
    }
}


int versiongraphique(int choice)
{
    Results resultats;
    resultats.jan = results().jan;
    resultats.feb = results().feb;
    resultats.mar = results().mar;
    resultats.apr = results().apr;
    resultats.may = results().may;
    resultats.jun = results().jun;
    resultats.jul = results().jul;
    resultats.aug = results().aug;
    resultats.sep = results().sep;
    resultats.oct = results().oct;
    resultats.nov = results().nov;
    resultats.dec = results().dec;
    resultats.rq_get = results().rq_get;
    resultats.rq_post = results().rq_post;
    resultats.rq_header = results().rq_header;
    resultats.rq_unknown = results().rq_unknown;
    resultats.secure_http_response = results().secure_http_response;
    resultats.total = results().total;

    if (choice == 1){
        versiongraphique_m(&resultats);
    } else if (choice == 2){
        versiongraphique_rq(&resultats);
    } else {
        printf("Erreur de choix\n");
    }
    return EXIT_SUCCESS;
}
void lecture_style()
{
  FILE *fd;
  char str[1024];
  if ((fd = fopen("aecrire.html","r")) == NULL)
    fprintf(stderr,"ERREUR DE CHARGEMENT DE FICHIER\n");
  else {
    while (!feof(fd)){
      fgets(str,1024,fd);
      printf("%s",str);

    }
    fclose(fd);
  }
}
void versionweb() {

    printf("Content-type: text/html\n\n");

    printf("<!doctype html>\n");
    printf("<html lang =\"fr\">\n");
    printf("<body>\n");

    lecture_style();

    printf("Depuis le 01/jan/2018 on a enregistre : %d\n", results().total);

    printf("<div id = \"vertgraph\">\n");
    printf("    <ul>\n");

    printf("        <li style=\"left: 10px; height : %d", results().jan/100);
    printf("px;\">%d", results().jan/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 41px; height : %d", results().feb/100);
    printf("px;\">%d", results().feb/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 72px; height : %d", results().mar/100);
    printf("px;\">%d", results().mar/1000);
    printf("</li>\n");
    printf("        <li style=\"left: 103px; height : %d", results().apr/100);
    printf("px;\">%d", results().apr/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 134px; height : %d", results().may/100);
    printf("px;\">%d", results().may/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 165px; height : %d", results().jun/100);
    printf("px;\">%d", results().jun/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 196px; height : %d", results().jul/100);
    printf("px;\">%d", results().jul/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 227px; height : %d", results().aug/100);
    printf("px;\">%d", results().aug/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 258px; height : %d", results().sep/100);
    printf("px;\">%d", results().sep/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 289px; height : %d", results().oct/100);
    printf("px;\">%d", results().oct/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 320px; height : %d", results().nov/100);
    printf("px;\">%d", results().nov/1000);
    printf("</li>\n");

    printf("        <li style=\"left: 351px; height : %d", results().dec/100);
    printf("px;\">%d", results().dec/100);
    printf("</li>\n");

    printf("    </ul>\n");

    printf("</html>\n");
    printf("</body>\n");
}