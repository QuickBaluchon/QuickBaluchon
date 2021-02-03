#ifndef EXCEL
#define EXCEL

void writeXLSX (PkgData *pkg, uint8_t totalPkg) ;
uint8_t createXLSXfile (uint8_t idUser, char *fileName) ;
uint8_t writeData (char *fileName, PkgData *pkgData, uint8_t totalPkg) ;
void writeLabels (lxw_worksheet *worksheet) ;

void getDateTime (char *dt) ;

#endif
