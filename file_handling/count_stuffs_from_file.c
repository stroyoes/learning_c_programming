#include <stdio.h>

#define ERR -1

int main() {
  int num_of_chars = 0, num_of_lines = 0, num_of_spaces = 0, num_of_tabs = 0;
  char file_name[50], ch;
  FILE *fp;

  printf("Enter file name: ");
  if (scanf("%s", file_name) != 1) {
    printf("\nERROR: Failed to read file name!\n");
    return ERR;
  }

  fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("\nERROR: File opening failed!\n");
    return ERR;
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

