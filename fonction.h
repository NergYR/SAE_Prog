/// @brief struct log_line
/// @return char[16] ip, char[32] timestamp, char[256] request, char[256] user_agent
struct log_line
{
    char ip[16];
    char timestamp[32];
    char request[256];
    char user_agent[256];
};
///@brief struct results 
///@return int(jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec, rq_post, rq_get, rq_header, rq_unknown, sql_injection, total)
/// @brief Type de la Structure de donnée 
typedef struct Results
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
        int rq_post;
        int rq_get;
        int rq_header;
        int rq_unknown;
        int sql_injection;
        int secure_http_response;
        int total;
}Results;
/// @brief Fonction qui permet de lire la ligne et extraire l'ip, le timestamp, request et user_agent
/// @param file fichier log, log_line stucture
struct log_line scanLine();

/// @brief Fonction qui permet de lire le fichier log et de compter le nombre de requetes POST, GET, HEAD et inconnues
/// @return struct results 
/// @return jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec, rq_post, rq_get, rq_header, rq_unknown, sql_injection, total
struct Results results();
/// @brief Permet de determine le mois avec le plus de connexion
/// @param resultats 
/// @return le nombre de connexion du mois avec le plus de connexion
int max_mois(Results *resultats);
/// @brief Permet de determine le type de requete avec le plus de connexion
/// @param resultats
/// @return le nombre de connexion du type de requete avec le plus de connexion
int max_rq(Results *resultats);
/// @brief permet d'afficher les statisques de connexion sous formes de texte
void versiontexte();
/// @brief Version graphique choix pour choisir l'affichage, sois 1 = mois ou 2 = requêtes
/// @param choice 
/// @return 
int versiongraphique(int choice);
/// @brief Version graphique des statistics selon les mois
/// @param resultats 
void versiongraphique_m(Results *resultats);
/// @brief Version graphique des statistiques selon les requêtes
/// @param resultats 
void versiongraphique_rq(Results *resultats);
/// @brief Permet de faire des statisques de connexion pour les mois
/// @param resultats
void affichestatistiques(Results *resultats);
/// @brief permet d'ouvrir et charger le fichier "aecrire.html"
void lecture_style();
/// @brief permet d'afficher la version web des statisques de connexion
void versionweb();