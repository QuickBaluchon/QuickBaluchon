#include <stdio.h>

int main () {
    xls_error_t error = LIBXLS_OK;
    xlsWorkBook *wb = xls_open_file("/path/to/finances.xls", "UTF-8", &error);
    if (wb == NULL) {
        printf("Error reading file: %s\n", xls_getError(error));
        exit(1);
    }
    for (int i=0; i<wb->sheets.count; i++) { // sheets
        xlsWorkSheet *work_sheet = xls_getWorkSheet(work_book, i);
        error = xls_parseWorkSheet(work_sheet);
        for (int j=0; j<=work_sheet->rows.lastrow; j++) { // rows
            xlsRow *row = xls_row(work_sheet, j);
            for (int k=0; k<=work_sheet->rows.lastcol; k++) { // columns
                xlsCell *cell = &row->cells.cell[k];
                // do something with cell
                if (cell->id == XLS_RECORD_BLANK) {
                    // do something with a blank cell
                } else if (cell->id == XLS_RECORD_NUMBER) {
                   // use cell->d, a double-precision number
                } else if (cell->id == XLS_RECORD_FORMULA) {
                    if (strcmp(cell->str, "bool") == 0) {
                        // its boolean, and test cell->d > 0.0 for true
                    } else if (strcmp(cell->str, "error") == 0) {
                        // formula is in error
                    } else {
                        // cell->str is valid as the result of a string formula.
                    }
                } else if (cell->str != NULL) {
                    // cell->str contains a string value
                }
            }
        }
        xls_close_WS(work_sheet);
    }
    xls_close_WB(wb);
}
