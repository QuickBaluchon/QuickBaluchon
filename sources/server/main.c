#include <stdio.h>
#include <stdlib.h>
#include "libxl.h"
#include <string.h>
void readData();

typedef struct Data {
  double weight;
  double length;
  double height;
  double width ;
  char emailRecipient[30] ;
  char addressRecipient[100];
  uint8_t delay ;

} Data ;

int main(void)
{
    readData();
    return 0;
}


void readData(){
    Data *datas = malloc(sizeof(Data) * 2);
    BookHandle book = xlCreateBook();
    if(book)
    {
        if(xlBookLoad(book, "example.xls"))
        {
            SheetHandle sheet = xlBookGetSheet(book, 0);
            if(sheet)
            {
                for (size_t lin = 1; lin <= 2; lin++) {
                    datas[lin-1].weight = xlSheetReadNum(sheet, lin, 0, 0);
                    datas[lin-1].length = xlSheetReadNum(sheet, lin, 1, 0);
                    datas[lin-1].height = xlSheetReadNum(sheet, lin, 2, 0);
                    datas[lin-1].width = xlSheetReadNum(sheet, lin, 3, 0);
                    strcpy(datas[lin-1].emailRecipient, xlSheetReadStr(sheet, lin, 4, 0));
                    strcpy(datas[lin-1].addressRecipient, xlSheetReadStr(sheet, lin, 5, 0));
                    datas[lin-1].delay = xlSheetReadNum(sheet, lin, 6, 0);
                }
            }
        }

        xlBookRelease(book);
    }
    printf("%s\n", datas[1].emailRecipient);
    free(datas);
}
