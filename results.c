#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"



struct Results results(){
    FILE *file = fopen("/var/log/apache2/access.log", "r");

    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
    }

    struct log_line current_line;
    struct Results resultats;
    
    resultats.jan = 0;
    resultats.feb = 0;
    resultats.mar = 0;
    resultats.apr = 0;
    resultats.may = 0;
    resultats.jun = 0;
    resultats.jul = 0;
    resultats.aug = 0;
    resultats.sep = 0;
    resultats.oct = 0;
    resultats.nov = 0;
    resultats.dec = 0;
    resultats.rq_post = 0;
    resultats.rq_get = 0;
    resultats.rq_header = 0;
    resultats.rq_unknown = 0;
    resultats.sql_injection = 0;
    resultats.total = 0;
    resultats.secure_http_response = 0;

    while (1) {
        current_line = scanLine(file, &current_line);

        if (current_line.ip[0] == '\0') {
            break;
        }


        if (strstr(current_line.request, "POST") != NULL) {
            resultats.rq_post++;
        } else if (strstr(current_line.request, "GET") != NULL) {
            resultats.rq_get++;
        } else if (strstr(current_line.request, "HEAD") != NULL) {
            resultats.rq_header++;
        } else {
            resultats.rq_unknown++;
        }
        if (strstr(current_line.user_agent, "https" ) != NULL){
            resultats.secure_http_response++;
        }
        if (strstr(current_line.timestamp, "Dec") != NULL){
            resultats.dec++;
        } else if (strstr(current_line.timestamp, "Jan") != NULL){
            resultats.jan++;
        } else if (strstr(current_line.timestamp, "Feb") != NULL){
            resultats.feb++;
        } else if (strstr(current_line.timestamp, "Mar") != NULL){
            resultats.mar++;
        } else if (strstr(current_line.timestamp, "Apr") != NULL){
            resultats.apr++;
        } else if (strstr(current_line.timestamp, "May") != NULL){
            resultats.may++;
        } else if (strstr(current_line.timestamp, "Jun") != NULL){
            resultats.jun++;
        } else if (strstr(current_line.timestamp, "Jul") != NULL){
            resultats.jul++;
        } else if (strstr(current_line.timestamp, "Aug") != NULL){
            resultats.aug++;
        } else if (strstr(current_line.timestamp, "Sep") != NULL){
            resultats.sep++;
        } else if (strstr(current_line.timestamp, "Oct") != NULL){
            resultats.oct++;
        } else if (strstr(current_line.timestamp, "Nov") != NULL){
            resultats.nov++;
        }
        resultats.total++;
    }
    fclose(file);

return resultats;
}