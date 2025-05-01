#include "sep_odd_n_even.h"

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

void write_nums_to_file() {
  FILE *num_file;

  char nums[MAX_INPUT_SIZE]; //  NOTE: Assuming data won't exceed 1 Kb

  num_file = fopen(NUM_FILE, "w");

  if (num_file == NULL) {
    printf("\nERROR: Failed opening file \n");
    return;
  }

  printf("Enter numbers line by line (enter '.' to stop):\n");

  do {

    if (fgets(nums, MAX_INPUT_SIZE, stdin) == NULL) {
      break; // If any error or EOF 
    }
    
    if (nums[0] == '.') {
      break; // If . is encountered end the loop 
    }

    fprintf(num_file, "%s",nums); // Write to file 
  } while (true);

  fclose(num_file);

  printf("\nNumbers written to file successfully !\n"); 
}

void print_from_file(char *name, char *file_name) {
  FILE *num_file;
  
  char num_lines[MAX_INPUT_SIZE];

  num_file = fopen(file_name, "r");

  if (num_file == NULL) {
    printf("\nERROR: Failed opening %s file\n", name);
    return;
  }

  printf(" %s: \n",name);

  while (fgets(num_lines, sizeof(num_lines), num_file)) {
    printf(" %s", num_lines);
  }

  fclose(num_file);
}

void sep_odd_n_even() {
  FILE *num_file, *even_file, *odd_file;


  char num_lines[MAX_INPUT_SIZE];

  num_file = fopen(NUM_FILE, "r");

  if (num_file == NULL) {
    printf("\nERROR: Failed opening file\n");
    return;
  }

  even_file = fopen(EVEN_FILE, "w");

  if (even_file == NULL) {
    printf("\nERROR: Failed opening even file\n");

    fclose(num_file);
    return;

  }

  odd_file = fopen(ODD_FILE, "w");

  if (odd_file == NULL) {
    printf("\nERROR: Failed opening odd file\n");

    fclose(even_file);
    fclose(num_file);

    return;
  }

  while (fgets(num_lines, sizeof(num_lines), num_file)) {

    int num = atoi(num_lines);

    if (num % 2 == 0) {
      fprintf(even_file, "%d is even \n", num);
    } else {
      fprintf(odd_file, "%d is odd \n", num);
    }
  }

  fclose(num_file);
  fclose(even_file);
  fclose(odd_file);

}
