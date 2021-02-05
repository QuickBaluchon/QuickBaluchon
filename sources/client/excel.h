#ifndef EXCEL
#define EXCEL

void writeXLSX (GtkWidget *widget, Window *w) ;
uint8_t createXLSXfile (char *fileName) ;
uint8_t writeData (char *fileName, PkgData *pkgData, uint8_t totalPkg) ;
void writeLabels (SheetHandle worksheet) ;

void getDateTime (char *dt) ;

#endif
