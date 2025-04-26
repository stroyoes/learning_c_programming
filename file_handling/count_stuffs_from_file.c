#include <stdio.h>

int main() {
  int num_of_chars = 0, num_of_lines = 0, num_of_spaces = 0, num_of_tabs = 0;
  char file_name[50], ch;
  FILE *fp;

  printf("Enter file name: ");
  scanf("%s", file_name);

  fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("File opening failed!\n");
    return 1;
  }

  while ((ch = fgetc(fp)) != EOF) {
    num_of_chars++;
    if (ch == '\n') {
      num_of_lines++;
    } else if (ch == '\t') {
      num_of_tabs++;
    } else if (ch == ' ') {
      num_of_spaces++;
    }
  }
  fclose(fp);

  printf("Number of characters: %d\n", num_of_chars);
  printf("Number of lines     : %d\n", num_of_lines);
  printf("Number of tabs      : %d\n", num_of_tabs);
  printf("Number of spaces    : %d\n", num_of_spaces);

  return 0;
}

