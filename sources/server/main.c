#include <stdio.h>
#include <stdlib.h>
#include "libxl.h"
#include <string.h>
#include <mysql/mysql.h>
#include <stdint.h>

uint16_t port = 3306 ;
char *host = "localhost" ;
char *usrn = "root" ;
char *pwd = "root" ;
char *dbname = "hedwige" ;


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
int16_t getPkgNumber (void) ;


int main (int argc, char **argv) {
    if (argc < 4)
        return 1 ;

    readData(argv);
    return 0;
}


void readData (char **argv) {
    Data *datas = malloc(sizeof(Data) * atoi(argv[3]));
    BookHandle book = xlCreateBook();
    if (book) {
        if (xlBookLoad(book, argv[1])) {
            SheetHandle sheet = xlBookGetSheet(book, 0);
            if (sheet) {
                for (size_t lin = 1; lin <= atoi(argv[3]); lin++) {
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
    saveData(datas, argv) ;
    free(datas);
}



uint8_t saveData (Data *datas, char **argv) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    char insert[300] = "";

    if (mysql_real_connect(&mysql, host, usrn, pwd, dbname, port, NULL, 0) == NULL) {
        printf("Unable to connect to mysql\n");
        mysql_close(&mysql);
        return 1 ;
    }
    for (uint8_t i = 0; i < atoi(argv[3]); i++) {
        strcpy(insert, "") ;
        sprintf(insert, "INSERT INTO package (weight, volume, address, email, delay, client) VALUES (%lf, %lf, '%s', '%s', %d, %d)",
            datas[i].weight,
            datas[i].length * datas[i].height * datas[i].width,
            datas[i].emailRecipient,
            datas[i].addressRecipient,
            datas[i].delay,
            atoi(argv[2])
        );

        mysql_query(&mysql, insert);
        printf("%d\n", getPkgNumber()) ;
    }
    mysql_close(&mysql);

    return 0 ;
}

int16_t getPkgNumber (void) {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    char *selectMax = "SELECT MAX(id) FROM PACKAGE" ;
    MYSQL_ROW row ;
    MYSQL_RES *results ;
    uint16_t nb = 0 ;

    if(mysql_real_connect(&mysql, host, usrn, pwd, dbname, port, NULL, 0) == NULL){
        printf("Unable to connect to mysql\n");
        mysql_close(&mysql);
        return -1 ;
    } else {
        mysql_query(&mysql, selectMax);
        results = mysql_use_result(&mysql) ;
        if (results == NULL)
            return 0 ;
        row = mysql_fetch_row(results) ;
        nb = atoi(row[0]) ;
        mysql_close(&mysql);
    }
    return nb ;
}
