#include "all.h"

extern int idUser ;

void writeXLSX (GtkWidget *widget, Window *w) {
    char file[30] = "" ;

    //free the buttons
    if (w->data != NULL)
        free(w->data) ;

    printf("%p\n", w) ;
    printf("%lf\n", w->pkgData[0].width) ;

    if (createXLSXfile(file) != 0) {
        printMessage(NULL, "Error in creating the XLSX file") ;
        return ;
    }

    if (writeData(file, w->pkgData, w->totalPkg)) {
        printMessage(NULL, "Error in writing the XLSX file") ;
        return ;
    }
}

uint8_t createXLSXfile (char *fileName) {
    FILE *xlsx ;
    char time[22] = "" ;

    getDateTime(time) ;
    sprintf(fileName, "%d-%s.xlsx", idUser, time) ;

    xlsx = fopen(fileName, "w+") ;
    if (xlsx == NULL)
        return 1 ;

    fclose(xlsx) ;
    return 0 ;
}


uint8_t writeData (char *fileName, PkgData *pkgData, uint8_t totalPkg) {
    uint16_t row ;

    lxw_workbook  *workbook  = workbook_new(fileName);
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    lxw_format    *format   = workbook_add_format(workbook);

    format_set_num_format(format, "0.000");
    writeLabels(worksheet) ;

    for (row = 1 ; row <= totalPkg ; row++) {
        worksheet_write_number(worksheet, row, 0, (float)pkgData[row-1].weight, format);
        worksheet_write_number(worksheet, row, 1, pkgData[row-1].length, NULL);
        worksheet_write_number(worksheet, row, 2, pkgData[row-1].height, NULL);
        worksheet_write_number(worksheet, row, 3, pkgData[row-1].width, NULL);
        worksheet_write_string(worksheet, row, 4, pkgData[row-1].emailRecipient, NULL);
        worksheet_write_string(worksheet, row, 5, pkgData[row-1].addressRecipient, NULL);
        worksheet_write_number(worksheet, row, 6, pkgData[row-1].delay, NULL);
    }

    free(pkgData) ;
    workbook_close(workbook);
    return 0 ;
}

void writeLabels (lxw_worksheet *worksheet) {
    char cols[7][30] = {"weight", "length", "height", "width", "Recipient's mail", "Recipient's address", "Delay"};
    for (int i = 0 ; i < 7 ; ++i)
        worksheet_write_string(worksheet, 0, i, cols[i], NULL) ;
}


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
