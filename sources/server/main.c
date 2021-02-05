#include <stdio.h>
#include <stdlib.h>
#include "libxl.h"
#include <string.h>
#include <mysql/mysql.h>
#include <stdint.h>


typedef struct Data {
  double weight;
  double length;
  double height;
  double width ;
  char emailRecipient[30] ;
  char addressRecipient[100];
  uint8_t delay ;
} Data ;

void readData (char **argv);
uint8_t saveData (Data *datas, char **argv) ;


int main (int argc, char **argv) {
    if (argc < 4)
        return 1 ;

    readData(argv);
    return 0;
}


void readData (char **argv) {
    Data *datas = malloc(sizeof(Data) * atoi(argv[3]));
    BookHandle book = xlCreateBook();
    if(book)
    {
        if(xlBookLoad(book, argv[1]))
        printf("%s\n", argv[1]) ;
        {
            SheetHandle sheet = xlBookGetSheet(book, 0);
            printf("%p\n", sheet) ;
            if(sheet)
            {
                for (size_t lin = 1; lin <= atoi(argv[3]); lin++) {
                    datas[lin-1].weight = xlSheetReadNum(sheet, lin, 0, 0);
                    datas[lin-1].length = xlSheetReadNum(sheet, lin, 1, 0);
                    datas[lin-1].height = xlSheetReadNum(sheet, lin, 2, 0);
                    datas[lin-1].width = xlSheetReadNum(sheet, lin, 3, 0);
                    strcpy(datas[lin-1].emailRecipient, xlSheetReadStr(sheet, lin, 4, 0));
                    strcpy(datas[lin-1].addressRecipient, xlSheetReadStr(sheet, lin, 5, 0));
                    datas[lin-1].delay = xlSheetReadNum(sheet, lin, 6, 0);

                    printf("Datas %lf\n", datas[lin-1].weight) ;
                }
            }
        }

        printf("Read %lf\n", datas[0].weight) ;

        xlBookRelease(book);
    }
    saveData(datas, argv) ;
    free(datas);
}



uint8_t saveData (Data *datas, char **argv) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    char selectMax[30] = "SELECT MAX(id) FROM colis" ;
    char insert[300] = "";

    printf("Save %lf\n", datas[0].weight) ;

    if(mysql_real_connect(&mysql, "localhost", "root", "root", NULL, 3306, NULL, 0) == NULL){
        printf("Unable to connect to mysql\n");
        mysql_close(&mysql);
        return 1 ;
    }
    else {
        for (uint8_t i = 0; i < atoi(argv[3]); i++) {
            sprintf(insert, "INSERT INTO package (weight, volume, address, email, delay, client) VALUES (%lf, %lf, \"%s\", \"%s\", %d, %d)",
                datas[i].weight,
                datas[i].length * datas[i].height * datas[i].width,
                datas[i].emailRecipient,
                datas[i].addressRecipient,
                datas[i].delay,
                atoi(argv[2])
            );
            printf("%s\n", insert) ;

            mysql_query(&mysql, insert);
        }
    }
    return 0 ;
}
