#include "students_db.h"

#include <stdio.h>

int main() {
  int total_students;

  printf("Enter the number of students: ");
  if (scanf("%d", &total_students) != 1) {
    printf("\nERROR: Expected an int value. Got something else .\n");
    return -1;
  }

  student_t students_db[total_students];

  fill_students_db(students_db, total_students);

  print_students_db(students_db, total_students);

  return 0; 
}

