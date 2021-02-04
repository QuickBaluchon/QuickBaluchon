#ifndef GTK
#define GTK

void hello (GtkWidget *widget, void *ptr);
void printMessage (GtkWidget *widget, char *message) ;

GtkWidget * createWindow (char *windowTitle, uint16_t width, uint16_t height) ;
GtkWidget * createGrid (GtkWidget *window) ;
GtkWidget * createInput (char *placeholder, GtkWidget *grid, uint8_t lin, uint8_t col) ;
void addLabel (GtkWidget *grid, uint8_t lin, uint8_t col, char *str) ;
void backgroundColor (GtkWidget *widget, char *color) ;
void destroy (GtkWidget *widget, gpointer data) ;

void retrieveData(GtkWidget *widget, GtkWidget *input, char **str) ;
void retrieveComboBoxContent (GtkWidget *widget, GtkWidget *box, char **str) ;
uint8_t retrieveInteger (GtkWidget *widget, GtkWidget *input, int16_t *integer) ;

void initProg (int argc, char **argv) ;

void askNumberPkg (void) ;
void getNumberPkg(GtkWidget *widget, Window *w) ;
void setPkgInputs (GtkWidget *widget, Window *w) ;
PkgInputs * createPkgInputs (GtkWidget *grid) ;

void printPkgData (Window *w) ;
void modifyPkgData (GtkWidget *widget, uint8_t *i) ;
void getPkgValues(Window *w, uint8_t i) ;

void getDataPkg(GtkWidget *widget, Window *w);
void getDataPkgDoubles (GtkWidget *widget, PkgInputs *pkg, PkgData *pkgData) ;

uint8_t checkEmail (char *email) ;
uint8_t checkDouble (double d) ;

void printPkgs(GtkWidget *widget, Window *w) ;
#endif
