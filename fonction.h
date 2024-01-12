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
struct Results
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
};
struct log_line scanLine();
struct Results results();
void versiontexte();
int versiongraphique();
int versionweb();