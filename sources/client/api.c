#include "all.h"

int idUser = 0 ;

void saveID (char *str, size_t size, size_t nmemb, void *stream) {

  char *strId = malloc(sizeof(char)*16);
  if(strId == NULL) exit(1);

    if (strlen(str) > 1){
      int size = strchr(str, ',') - strstr(str, "\"id\": ");
      strncpy(strId, strstr(str, "\"id\": "), size);
      strId[ size - 1 ] = '\0';
      strId += 7;
      idUser = atoi(strId);
    }
    else
      idUser = 0 ;

}

void readPkgNumbers (char *str, size_t size, size_t nmemb, void *stream) {
    char qrURL[100] ;
    char *tok ;
    char tmp[10] ;
    uint16_t nb ;

    printf("\n%s\n", str);

    if (strlen(str) > 1) {
        tok = strtok(str, "\n") ;
        while (tok != NULL) {
            if (strstr(tok, " => ") != NULL) {
                strcpy(tmp, strstr(tok, " => ") + 4) ;
                nb = atoi(tmp) ;
                if (nb == 0)
                    continue ;
                sprintf(qrURL, "https://quick-baluchon.herokuapp.com/package?no=%d", nb) ;
                if(createQRcode(qrURL, nb)) {   // createQRcode returns 0 if success
                  printMessage(NULL, "Unable to create the QrCode") ;
                  return;
                }
            }
            tok = strtok(NULL, "\n") ;
        }

        printMessage(NULL, "The QR codes have been generated") ;
    } else {
        printMessage(NULL, "An error occured") ;
    }
}

uint8_t connectAPI (char *name, char *pwd) {

    CURL *curl;
    CURLcode res;
    char fmt[32] = "{\"name\": \"%s\",\"password\": \"%s\"}";
    char json[64];
    struct curl_slist *headerlist = NULL;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl) {

      /* initialize custom header list (stating that Expect: 100-continue is not
         wanted */
      headerlist = curl_slist_append(headerlist, "Expect:");
      headerlist = curl_slist_append(headerlist, "Content-Type: application/json");
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);

      /* set the json with data:  {"name": {name},"password": {pwd} } */
      sprintf(json, fmt, name, pwd);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);

      /* what URL that receives this POST */
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8888/QuickBaluchon/api/client/login");
      //curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

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
    headerlist = curl_slist_append(headerlist, "Expect:");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);

    /* what URL that receives this POST */
    sprintf(url, "http://localhost:8888/QuickBaluchon/api/client/excel/%d/%d", idUser, totalPkg) ;
    curl_easy_setopt(curl, CURLOPT_URL, url);

    /* Store the result of the query */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readPkgNumbers);

    curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK && res != CURLE_WRITE_ERROR)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);

    /* free slist */
    curl_slist_free_all(headerlist);
  }
  return 0;
}
