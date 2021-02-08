#ifndef API
#define API

uint8_t connectAPI (char *name, char *pwd) ;
uint8_t uploadExcel (char *fileName, uint8_t totalPkg) ;

void saveID (char *str, size_t size, size_t nmemb, void *stream) ;
void readPkgNumbers (char *str, size_t size, size_t nmemb, void *stream) ;

#endif
