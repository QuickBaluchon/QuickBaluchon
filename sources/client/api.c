#include "all.h"

int idUser = 0 ;

void saveID (char *str, size_t size, size_t nmemb, void *stream) {
    if (strlen(str) > 2)
        sscanf(strchr(str, '"'), "\"id\": \"%d\"", &idUser);
    else
        idUser = 0 ;
}

void readPkgNumbers (char *str, size_t size, size_t nmemb, void *stream) {
    if (strlen(str) > 2)
        sscanf(strchr(str, '"'), "\"id\": \"%d\"", &idUser);
    else
        idUser = 0 ;
}

uint8_t connectAPI (char *name, char *pwd) {
    CURL *curl;
    CURLcode res;

    curl_mime *form = NULL;
    curl_mimepart *field = NULL;
    struct curl_slist *headerlist = NULL;
    static const char buf[] = "Expect:";

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl) {
      /* Create the form */
      form = curl_mime_init(curl);

      /* Fill in the filename field */
      field = curl_mime_addpart(form);
      curl_mime_name(field, "name");
      curl_mime_data(field, name, CURL_ZERO_TERMINATED);

      field = curl_mime_addpart(form);
      curl_mime_name(field, "password");
      curl_mime_data(field, pwd, CURL_ZERO_TERMINATED);

      /* initialize custom header list (stating that Expect: 100-continue is not
         wanted */
      headerlist = curl_slist_append(headerlist, buf);
      /* what URL that receives this POST */
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8888/QuickBaluchon/api/client/login");
      curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

      /* Store the result of the query */
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, saveID);

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);
      /* Check for errors */
      if(res != CURLE_OK && res != CURLE_WRITE_ERROR)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

      /* always cleanup */
      curl_easy_cleanup(curl);

      /* then cleanup the form */
      curl_mime_free(form);
      /* free slist */
      curl_slist_free_all(headerlist);
    }
    return 0;
}

uint8_t uploadExcel (char *fileName, uint8_t totalPkg) {
  CURL *curl;
  CURLcode res;
  char url[100] = "" ;

  curl_mime *form = NULL;
  curl_mimepart *field = NULL;
  struct curl_slist *headerlist = NULL;
  static const char buf[] = "Expect:";

  curl_global_init(CURL_GLOBAL_ALL);

  curl = curl_easy_init();
  if(curl) {
    /* Create the form */
    form = curl_mime_init(curl);

    /* Fill in the file upload field */
    field = curl_mime_addpart(form);
    curl_mime_name(field, "excel");
    curl_mime_filedata(field, fileName);

    /* initialize custom header list (stating that Expect: 100-continue is not
       wanted */
    headerlist = curl_slist_append(headerlist, buf);
    /* what URL that receives this POST */
    sprintf(url, "http://localhost:8888/QuickBaluchon/api/client/excel/%d/%d", idUser, totalPkg) ;
    curl_easy_setopt(curl, CURLOPT_URL, url);

    /* Store the result of the query */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, saveID);

    curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);

    /* then cleanup the form */
    curl_mime_free(form);
    /* free slist */
    curl_slist_free_all(headerlist);
  }
  return 0;
}
