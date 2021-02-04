#ifndef ALL
#define ALL

#include <stdio.h>
#include <string.h>
#include <xlsxwriter.h>
#include <stdint.h>
#include <gtk/gtk.h>
#include <time.h>

typedef struct UserData {
    uint8_t id ;
    char name[30] ;
    char password[30] ;
} UserData ;

typedef struct PkgInputs {
  GtkWidget *weight;
  GtkWidget *length;
  GtkWidget *height;
  GtkWidget *width ;
  GtkWidget *emailRecipient ;
  GtkWidget *addressRecipient;
  GtkWidget *delay ;
} PkgInputs ;

typedef struct PkgData {
  double weight;
  double length;
  double height;
  double width ;
  char emailRecipient[30] ;
  char addressRecipient[100];
  uint8_t delay ;
} PkgData ;


typedef struct Window {
    GtkWidget *window ;
    GtkWidget *grid ;
    char winName[30] ;
    void *data ;
    uint8_t currentPkg;
    uint8_t totalPkg ;
    PkgData *pkgData ;
} Window ;

typedef struct Modify {
    Window *w ;
    uint8_t select ;
} Modify ;

#include "api.h"
#include "excel.h"
#include "gtk.h"

#endif
