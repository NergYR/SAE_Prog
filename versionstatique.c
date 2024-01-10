/*
 * versionstatique.c
 * 
 * © Copyright 2023 E. Huot <etienne.huot@uvsq.fr>
 * 
 * This program is can only be used for education purpose. 
 * It is part of a project, so-called MiniProjet, aiming to learn
 * programmation bases using the C language. 
 * It can only be used by the students of the RT departement, 
 * Technological Institute of Velizy - Université de Versailles - Saint-
 * Quentin-en-Yvelines - Université de Paris-Saclay. 
 * 
 * The aim of the project is to propose a tool to vizualize a bunch of 
 * statistics on a web server logs.
 * The following code propose a static version of the code that have to 
 * be developped by the students. 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libgraphique.h"

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

void versionweb()
{
  printf("Content-type: text/html\n\n"); 

  printf("<!doctype html>\n");
  printf("<html lang=\"fr\">\n"); 
  printf("<body>\n");

  lecture_style();
  
/* 
 * Notez que pour le web que les caractères accentués ont
 * été transformés en effet les chaînes de caractères C sont nativement
 * codées en ASCII et non en UTF-8. 
 * L'étudiant désireux de bien faire devrait normalement prétraiter 
 * tous les accents avant de les afficher en HTML.
 */
  printf("Depuis le 01/Jan/2018 on a enregistr&eacute; 998 connexions.<br>\n");
  
  printf("<div id = \"vertgraph\">\n");
  printf("    <ul>\n");
/* 
 * remarquez que chaque barre de l'histogramme est placée tous les 31 pixels,
 * et que le label correspond ici à la hauteur/10, on n'affiche pas le label pour des
 * hauteurs < 25 sinon ça fausse l'affichage.
 */
  printf("        <li style=\"left: 10px;  height: 79px;\">8</li>\n");
  printf("        <li style=\"left: 41px;  height: 81px;\">8</li>\n");
  printf("        <li style=\"left: 72px;  height: 99px;\">10</li>\n");
  printf("        <li style=\"left: 103px;  height: 23px;\"></li>\n");
  printf("        <li style=\"left: 134px;  height: 137px;\">14</li>\n");
  printf("        <li style=\"left: 165px;  height: 113px;\">11</li>\n");
  printf("        <li style=\"left: 196px;  height: 127px;\">13</li>\n");
  printf("        <li style=\"left: 227px;  height: 73px;\">7</li> \n");
  printf("        <li style=\"left: 258px;  height: 134px;\">13</li> \n");
  printf("        <li style=\"left: 289px;  height: 12px;\"></li> \n");
  printf("        <li style=\"left: 320px;  height: 115px;\">11</li>\n");
  printf("        <li style=\"left: 351px;  height: 5px;\"></li> \n");
  printf("    </ul>\n");
  printf("</div>\n");
  
  printf("</html>\n");
  printf("</body>\n\n"); 

}

void versiontexte()
{
  printf("Depuis le 01/Jan/2018 on a enregistre 998 connexions.\n");
  
  printf("   Janvier :  7.9%%\n");
  printf("   Fevrier :  8.1%%\n");
  printf("      Mars :  9.9%%\n");
  printf("     Avril :  2.3%%\n");
  printf("       Mai : 13.7%%\n");
  printf("      Juin : 11.3%%\n");
  printf("   Juillet : 12.7%%\n");
  printf("      Aout :  7.3%%\n");
  printf(" Septembre : 13.4%%\n");
  printf("   Octobre :  1.2%%\n");
  printf("  Novembre : 11.5%%\n");
  printf("  Decembre :  0.5%%\n");
}

void versiongraphique() {
  Point p = {30,50};
  ouvrir_fenetre(430,350);
  dessiner_rectangle((Point){0,0},430,350,blanc);

  afficher_texte("Depuis le 01/Jan/2018 on a enregistré 998 connexions.",12,p,noir);  

  p.y=300;
  afficher_texte(" Jan  Fev  Mar  Avr  Mai  Juin  Juil  Aou  Sep  Oct  Nov  Dec",14,p,vert);  
  
  dessiner_rectangle((Point){30,221},30,79,orange);
  dessiner_rectangle((Point){61,219},30,81,orange);
  dessiner_rectangle((Point){92,201},30,99,orange);
  dessiner_rectangle((Point){123,277},30,23,orange);
  dessiner_rectangle((Point){154,163},30,137,orange);
  dessiner_rectangle((Point){185,187},30,113,orange);
  dessiner_rectangle((Point){216,173},30,127,orange);
  dessiner_rectangle((Point){247,227},30,73,orange);
  dessiner_rectangle((Point){278,166},30,134,orange);
  dessiner_rectangle((Point){309,288},30,12,orange);
  dessiner_rectangle((Point){340,185},30,115,orange);
  dessiner_rectangle((Point){371,295},30,5,orange);

  afficher_texte("8",14,(Point){40,231},blanc);  
  afficher_texte("8",14,(Point){71,229},blanc);  
  afficher_texte("10",14,(Point){97,211},blanc);  

  afficher_texte("14",14,(Point){159,173},blanc);  
  afficher_texte("11",14,(Point){190,197},blanc);  
  afficher_texte("13",14,(Point){221,183},blanc);  
  afficher_texte("7",14,(Point){257,237},blanc);  
  afficher_texte("13",14,(Point){283,176},blanc); 
 
  afficher_texte("11",14,(Point){345,195},blanc);  

  actualiser();
  attendre_clic();
  fermer_fenetre();
}


int main(int argc, char* argv[])
{
    if (argc > 1) {
      if (strcmp(argv[1],"-txt")==0) {
        versiontexte();
      }
      if (strcmp(argv[1],"-gr")==0) {
        versiongraphique();
      }
      
    } else {
      versionweb();
    }

    return EXIT_SUCCESS;
}
