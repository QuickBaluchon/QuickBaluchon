#include <stdio.h>
#include <string.h>
#include <xlsxwriter.h>

typedef struct data {
  char name[32];
  int price;

} data;

int main(int argc, char const *argv[]) {
    int r;
    int c = 0;


  struct data *test = malloc(sizeof(data) * 3);
  strcpy(test[0].name, "Case 1");
  strcpy(test[1].name, "Case 2");
  strcpy(test[2].name, "Case 3");

  lxw_workbook  *workbook  = workbook_new("test.xlsx");
  lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

  for (r = 0; r < 3; r++) {
    worksheet_write_string(worksheet, r,c, test[r].name, NULL);

  }

  workbook_close(workbook);
  return 0;
}
