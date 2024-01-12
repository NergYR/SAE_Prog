#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include "lib/libgraphique.h"

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