#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main(int argc, char const *argv[]) {
    
    
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
