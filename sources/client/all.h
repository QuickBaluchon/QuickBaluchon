#ifndef ALL
#define ALL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <gtk/gtk.h>
#include <time.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <stddef.h>
#include "libxl.h"
#include "../libraries/qrcodegen/qrcodegen.h"

typedef struct PkgInputs {
  GtkWidget *weight;
  GtkWidget *length;
  GtkWidget *height;
  GtkWidget *width ;
  GtkWidget *nameRecipient ;
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
  char nameRecipient[100] ;
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
    uint8_t modifPkg ;
    PkgData *pkgData ;
} Window ;

typedef struct Modify {
    Window *w ;
    uint8_t select ;
} Modify ;

#include "api.h"
#include "excel.h"
#include "gtk.h"
#include "qr.h"

#endif
