#ifndef ALL
#define ALL

#include <stdio.h>
#include <string.h>
#include <xlsxwriter.h>
#include <stdint.h>
#include <gtk/gtk.h>
#include <regex.h>

typedef struct Window {
    GtkWidget *window ;
    GtkWidget *grid ;
    char winName[30] ;
    void (*prevWindow) (GtkWidget *widget, void *) ;
    void *data ;
    uint8_t currentPkg;
    uint8_t totalPkg ;
} Window ;

typedef struct UserData {
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
  GtkWidget *delai ;
} PkgInputs ;

typedef struct PkgData {
  double weight;
  double length;
  double height;
  double width ;
  char emailRecipient[30] ;
  char addressRecipient[100];
  uint8_t delai ;
} PkgData ;

#include "api.h"
#include "excel.h"
#include "gtk.h"

#endif
