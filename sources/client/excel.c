#include "all.h"
extern int idUser ;

/*
Function : writeXLSX
--------------------------------------------------------------------------------
Handles the writing process in an excel file
Calls
    excel.c/(createXLSXfile) to create a file with a specific name
    excel.c/(writeData) to write the package data in the Excel file
    excel.c/(uploadExcel) to send the Excel file to the server
    gtk.c/(askNumberPkg) to prompt a new entry of packages

--------------------------------------------------------------------------------
GtkWidget *widget : widget sent by callback function
Window *w : pointer to the structure containing all the data of the window
--------------------------------------------------------------------------------

*/
void writeXLSX (GtkWidget *widget, Window *w) {
    char file[30] = "" ;

    //free the buttons
    if (w->data != NULL){
        free(w->data) ;
        w->data = NULL;
    }

    if (createXLSXfile(file) != 0) {
        printMessage(NULL, "Error in creating the XLSX file") ;
        return ;
    }

    if (writeData(file, w->pkgData, w->totalPkg)) {
        printMessage(NULL, "Error in writing the XLSX file") ;
        return ;
    }


    uploadExcel(file, w->totalPkg) ;

    if (w->pkgData != NULL) {
        free(w->pkgData) ;
        w->pkgData = NULL;
    }

    askNumberPkg(w) ;
}

/*
Function : createXLSXfile
--------------------------------------------------------------------------------
Creates a file with the user's id and the current datetime
Calls
    excel.c/(getDateTime) to get a string with the current datetime

--------------------------------------------------------------------------------
char *fileName : string to save the name of the file
--------------------------------------------------------------------------------

*/
uint8_t createXLSXfile (char *fileName) {
    FILE *xlsx ;
    char time[22] = "" ;

    getDateTime(time) ;
    sprintf(fileName, "../../Excel/%d-%s.xls", idUser, time) ;

    xlsx = fopen(fileName, "w+") ;
    if (xlsx == NULL)
        return 1 ;

    fclose(xlsx) ;
    return 0 ;
}

/*
Function : writeData
--------------------------------------------------------------------------------
Writes the data in the Excel file using the libxl library
Calls
    excel.c/(writeLabels) to write the labels

--------------------------------------------------------------------------------
GtkWidget *widget : widget sent by callback function
Window *w : pointer to the structure containing all the data of the window
--------------------------------------------------------------------------------

*/
uint8_t writeData (char *fileName, PkgData *pkgData, uint8_t totalPkg) {
    BookHandle book = xlCreateBook();
    uint8_t f, row;
    FormatHandle format;
    SheetHandle sheet;
    char str[100] ;

    if (book) {
        //setup numeric format
        f = xlBookAddCustomNumFormat(book, "0.00");
        format = xlBookAddFormat(book, 0);
        xlFormatSetNumFormat(format, f);

        sheet = xlBookAddSheet(book, "Custom formats", 0);
        if (sheet) {
            writeLabels(sheet) ;
            for (row = 1 ; row <= totalPkg ; row++) {
                xlSheetWriteNum(sheet, row, 0, pkgData[row-1].weight, 0);
                xlSheetWriteNum(sheet, row, 1, pkgData[row-1].length, 0);
                xlSheetWriteNum(sheet, row, 2, pkgData[row-1].height, 0);
                xlSheetWriteNum(sheet, row, 3, pkgData[row-1].width, 0);
                xlSheetWriteStr(sheet, row, 4, pkgData[row-1].emailRecipient, 0);
                xlSheetWriteStr(sheet, row, 5, pkgData[row-1].addressRecipient, 0);
                xlSheetWriteNum(sheet, row, 6, pkgData[row-1].delay, 0);
            }
        }
    }

    if (xlBookSave(book, fileName)) {
        sprintf(str, "File %s has been created", fileName) ;
        printMessage(NULL, str);
    }
    xlBookRelease(book);
    return 0 ;
}

/*
Function : writeLabels
--------------------------------------------------------------------------------
Writes the package data labels in a worksheet

--------------------------------------------------------------------------------
SheetHandle worksheet : worksheet in use
--------------------------------------------------------------------------------

*/
void writeLabels (SheetHandle worksheet) {
    char cols[7][30] = {"weight", "length", "height", "width", "Recipient's mail", "Recipient's address", "Delay"};
    for (int i = 0 ; i < 7 ; ++i)
        xlSheetWriteStr(worksheet, 0, i, cols[i], 0) ;
}

/*
Function : getDateTime
--------------------------------------------------------------------------------
Writes the current date and time (GMT) in a string

--------------------------------------------------------------------------------
char *dt : string to store the outcome
--------------------------------------------------------------------------------

*/
void getDateTime (char *dt) {
    int h, min, s, day, month, year;
    time_t now = time(NULL);

    struct tm *local = gmtime(&now);
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

    sprintf(dt, "%d-%02d-%02d-%02d-%02d-%02d", year, month, day, h, min, s) ;
}
