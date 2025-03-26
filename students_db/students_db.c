#include <stdio.h>

#include "students_db.h"

void print_students_db(student_t *students_db, int total_students) {
  for (int i=0; i < total_students; i++) {
    printf("Details of student: %d : \n", (i+1));

    // Print the details of the student
    printf(" Student id: \"%d\"\n", students_db[i].id);
    printf(" Student name: \"%s\"\n", students_db[i].name);
    printf(" Student mark: \"%d\"\n", students_db[i].mark);

    printf("\n");
  }
}

void fill_students_db(student_t *students_db, int total_students) {
  for (int i=0; i < total_students; i++) {

    printf("Enter the details of student: %d : \n", (i+1));

    // Get the details of the student
    printf(" Enter the id of the student: ");
    if (scanf("%d", &students_db[i].id) != 1) {
      printf("\nERROR: Wrong 'id' . 'id' is an integer but got something else. \n");
      return;
    }

    while (getchar() != '\n');

    printf(" Enter the mark of the student: ");
    if (scanf("%d", &students_db[i].mark) != 1) {
      printf("\nERROR: Wrong 'mark' . 'mark' is an integer but got something else. \n");
      return;
    }

    while (getchar() != '\n');

    printf(" Enter the name of the student: ");
    if (scanf("%49[^\n]", students_db[i].name) != 1) { 
      printf("ERROR: Invalid input. Expected atleast one text value. \n");
      // Clear the input buffer
      while (getchar() != '\n');
      return;
    }

    while (getchar() != '\n');

    printf("\n");
  }
}
