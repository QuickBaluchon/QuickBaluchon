#include "all.h"

int idUser = 0 ;

/*
Function : saveID
--------------------------------------------------------------------------------
Sets the user's ID from the cURL connection request response (0 if none found)

--------------------------------------------------------------------------------
char *str : data delivered by curl
size_t size : always 1
size_t nmemb : length of the curl output
void *stream : stream to write the data into (stdout if none specified)
--------------------------------------------------------------------------------

*/
void saveID (char *str, size_t size, size_t nmemb, void *stream) {
  char *strId = malloc(sizeof(char)*16);
  int length ;
  if(strId == NULL) exit(1);
  printf("%s\n",str) ;

    if (nmemb > 1){
      length = strchr(str, ',') - strstr(str, "\"id\": ");
      strncpy(strId, strstr(str, "\"id\": "), length);
      strId[ length - 1 ] = '\0';
      strId += 7;
      idUser = atoi(strId);
    }
    else
      idUser = 0 ;
}

/*
Function : readPkgNumbers
--------------------------------------------------------------------------------
Reads the IDs of the packages just inserted in the database
Calls
    qr.c/(createQRcode) to generate a QRcode for each of the packages

--------------------------------------------------------------------------------
char *str : data delivered by curl
size_t size : always 1
size_t nmemb : length of the curl output
void *stream : stream to write the data into (stdout if none specified)
--------------------------------------------------------------------------------

*/
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
                sprintf(qrURL, "http://quick-baluchon.herokuapp.com/package/%d", nb) ;
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

/*
Function : connectAPI
--------------------------------------------------------------------------------
Connects to the API on the server with cURL to check the user's credentials

--------------------------------------------------------------------------------
char *name : user's username
char *pwd : user's password
--------------------------------------------------------------------------------
Return values
    0 if all went well
    the curl error code if an error occured
*/
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
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8888/api/client/login");
      //curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

      /* Store the result of the query */
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, saveID);

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);
      /* Check for errors */
      if(res != CURLE_OK && res != CURLE_WRITE_ERROR)
        return res ;

      /* always cleanup */
      curl_easy_cleanup(curl);

      /* free slist */
      curl_slist_free_all(headerlist);
    }
    return 0;
}

/*
Function : connectAPI
--------------------------------------------------------------------------------
Sends the file to the API with cURL

--------------------------------------------------------------------------------
char *fileName : path to the file to be sent
uint8_t totalPkg : total number of packages being sent
--------------------------------------------------------------------------------
Return values
    0 if all went well
    the curl error code if an error occured
*/
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
    sprintf(url, "http://localhost:8888/api/client/excel/%d/%d", idUser, totalPkg) ;
    curl_easy_setopt(curl, CURLOPT_URL, url);

    /* Store the result of the query */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readPkgNumbers);

    curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK && res != CURLE_WRITE_ERROR)
      return res ;

    /* always cleanup */
    curl_easy_cleanup(curl);

    /* free slist */
    curl_slist_free_all(headerlist);
  }
  return 0;
}
