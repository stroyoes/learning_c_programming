#ifndef STUDENTS_DB_H
#define STUDENTS_DB_H

#define MAX_STR_LEN 50

typedef struct {
  int id;
  int mark;
  char name[MAX_STR_LEN];
} student_t;

void print_students_db(student_t *students_db, int total_students);
void fill_students_db(student_t *students_db, int total_students);

#endif
