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
    int presultsjan=results().jan*100;
    int presultsfeb=results().feb*100;
    int presultsmar=results().mar*100;
    int presultsapr=results().apr*100;
    int presultsmay=results().may*100;
    int presultsjun=results().jun*100;
    int presultsjul=results().jul*100;
    int presultsaug=results().aug*100;
    int presultssep=results().sep*100;
    int presultsoct=results().oct*100;
    int presultsnov=results().nov*100;
    int presultsdec=results().dec*100;

    printf("Content-type: text/html\n\n");

    printf("<!doctype html>\n");
    printf("<html lang =\"fr\">\n");
    printf("<body>\n");

    lecture_style();

    printf("Depuis le 01/jan/2018 on a enregistre : %d\n", results().total);

    printf("<div id = \"vertgraph\">\n");
    printf("    <ul>\n");

    printf("        <li style=\"left: 10px; height : %d", results().jan/100);
    printf("px;\">%d", presultsjan/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 41px; height : %d", results().feb/100);
    printf("px;\">%d", presultsfeb/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 72px; height : %d", results().mar/100);
    printf("px;\">%d", presultsmar/results().total);
    printf("</li>\n");
    printf("        <li style=\"left: 103px; height : %d", results().apr/100);
    printf("px;\">%d", presultsapr/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 134px; height : %d", results().may/100);
    printf("px;\">%d", presultsmay/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 165px; height : %d", results().jun/100);
    printf("px;\">%d", presultsjun/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 196px; height : %d", results().jul/100);
    printf("px;\">%d", presultsjul/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 227px; height : %d", results().aug/100);
    printf("px;\">%d", presultsaug/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 258px; height : %d", results().sep/100);
    printf("px;\">%d", presultssep/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 289px; height : %d", results().oct/100);
    printf("px;\">%d", presultsoct/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 320px; height : %d", results().nov/100);
    printf("px;\">%d", presultsnov/results().total);
    printf("</li>\n");

    printf("        <li style=\"left: 351px; height : %d", results().dec/100);
    printf("px;\">%d", presultsdec/results().total);
    printf("</li>\n");

    printf("    </ul>\n");

    printf("</html>\n");
    printf("</body>\n");
}