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
        if(strcmp(argv[2],"m")==0){
          versiongraphique(1);
        }else if (strcmp(argv[2],"rq")==0)
        {
          versiongraphique(2);
        }else if (strcmp(argv[2]," ")==0){
          printf("Invalid argument\n");
          printf("Please use -gr m or -gr rq\n");
        }
      }
      
    } else {
      versionweb();
    }

    return EXIT_SUCCESS;



}
