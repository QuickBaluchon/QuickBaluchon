#ifndef API
#define API

uint8_t connectAPI (char *name, char *pwd) ;
void saveID (char *str, size_t size, size_t nmemb, void *stream) ;
uint8_t uploadExcel (char *fileName, uint8_t totalPkg) ;

#endif
