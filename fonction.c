#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include "lib/libgraphique.h"

/// @brief Fonction qui permet de lire la ligne et extraire l'ip, le timestamp, request et user_agent
/// @param file fichier log, log_line stucture
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
int max_rq(Results *resultats){
    int max = resultats->rq_post;

    int rq[5] = {resultats->rq_get, resultats->rq_post, resultats->rq_header, resultats->rq_unknown, resultats->secure_http_response};

    for (int i = 0; i < 5; i++)
    {
        if (rq[i] > max)
        {
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

    //afficher_texte("Depuis le 01/Jan/2018 on a enregistré 998 connexions.", 12, p, noir);

    p.y = 300;
    afficher_texte(" Jan  Fev  Mar  Avr  Mai  Juin  Juil  Aou  Sep  Oct  Nov  Dec", 14, p, vert);

    int x = 30, largeur = 30, decalage = 31;
    int max_value = max_mois(resultats);

    for (int i = 0; i < 12; i++)
    {
        int hauteur;

        // Utiliser le tableau de mois pour accéder aux valeurs correspondantes
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

        // Utiliser hauteur pour dessiner la barre pour le mois actuel
        dessiner_rectangle((Point){x, 221 - hauteur}, largeur, hauteur, orange);
        afficher_texte(mois[i], 14, (Point){x + 5, 235}, blanc);
        x += decalage;
    }

    actualiser();
    attendre_clic();
    fermer_fenetre();

    // Ajout du calcul et de l'affichage des statistiques
    //calculer_statistiques(resultats);
    //affichestatistiques(resultats);
}
void versiongraphique_rq(Results *resultats)
{
    printf("Version graphique - Statistiques sur les types de requêtes\n");
    Point p = {30, 50};
    ouvrir_fenetre(430, 350);
    dessiner_rectangle((Point){0, 0}, 430, 350, blanc);

    char types_requetes[5][20] = {"rq_post", "rq_get", "rq_header", "rq_unknown", "secure_http_response"};

    p.y = 300;
    afficher_texte(" Post  Get  Header  Inconnu  HTTPS", 14, p, vert);

    int x = 30, largeur = 30, decalage = 31;
    int max_value = max_rq(resultats);

    for (int i = 0; i < 6; i++)
    {
        float hauteur;

        // Utiliser l'index de la boucle pour accéder aux différentes statistiques de requêtes
        switch (i)
        {
        case 0:
            hauteur = (resultats->rq_post * 100) / max_value;
            while (hauteur == 1)
            {
                hauteur*=10;
            }
            break;
        case 1:
            hauteur = (resultats->rq_get * 100) / max_value;
            while (hauteur == 1)
            {
                hauteur*=10;
            }
            break;
        case 2:
            hauteur = (resultats->rq_header * 100) / max_value;
            while (hauteur == 1)
            {
                hauteur*=10;
            }
            break;
        case 3:
            hauteur = (resultats->rq_unknown * 100)/ max_value;
            while (hauteur == 1)
            {
                hauteur*=10;
            }
            break;
        case 4:
            hauteur = (resultats->secure_http_response * 100) / max_value;
            float hauteur_m = hauteur;
            while (hauteur_m <= 1)
            {
                hauteur_m *= 10;
                if (hauteur_m > 1) {
                    break; 
                }
            }
            printf("hauteur : %f\n", hauteur_m);
            printf("value : %d\n", resultats->secure_http_response);
            printf("Maximum : %d\n", max_value);
            break;
        default:
            break;
        }        


        // Utiliser hauteur pour dessiner la barre pour le type de requête actuel
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
int versiongraphique()
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
    //versiongraphique_m(&resultats);
    versiongraphique_rq(&resultats);
    return EXIT_SUCCESS;
}
void lecture_style()
{
  /* On aurait pu utiliser un fichier css mais il est     */
  /* parfois plus pratique de définir le style dans le    */
  /* code HTML généré par ce CGI-BIN.                     */
  /* On le lit ce style depuis fichier "aecrire.html"     */
  /* puis on l'affiche.                                   */
  /* L'étudiant attentif pourra s'apercevoir aisément que */
  /* cette fonction n'est pas inutile pour ses propres    */
  /* besoins...                                           */

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