#include "all.h"



uint8_t createXLSXfile (char *fileName) {
    FILE *xlsx = fopen(fileName, "w") ;
    if (xlsx == NULL)
        return 1 ;

    fclose(xlsx) ;
    return 0 ;
}


uint8_t writeData (UserData *data, char *fileName) {
    uint16_t row ;
    uint16_t col = 0;

    lxw_workbook  *workbook  = workbook_new(fileName);
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    for (row = 0; row < 3; row++) {
        worksheet_write_string(worksheet, row,col, data[row].name, NULL);
    }

    workbook_close(workbook);
    return 0 ;
}
