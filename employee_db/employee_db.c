/**
 * Write a program to store and print information about multiple employees (name, ID, salary) 
 * using structures.
 */ 

#include <stdio.h>
#include "employee_db.h"

int main() {
  int N;

  printf("Enter the number of employees: ");
  if (scanf("%d", &N) != 1) {
    printf("ERROR: Invalid input. Expected atleast one integer value. \n");
    return -1;
  }

  struct Employee employees[N]; //  NOTE: Here, employees is declared as an array of n elements of type struct Employee.
                                //        Each element of the array represents a separate Employee object.

  // Input the data for the employees 
  for (int i = 0; i < N; i++) {
    printf("\nEnter details for the employee %d : \n", (i + 1));
    
    printf("ID: ");
    if (scanf("%d", &employees[i].id) != 1) { 
      printf("ERROR: Invalid input. Expected atleast one integer value. \n");
      return -1;
    }

    while (getchar() != '\n'); // Clear the input buffer after reading ID

    printf("Name: ");
    if (scanf("%49[^\n]", employees[i].name) != 1) { //  NOTE: Limiting input to 49 characters to prevent buffer overflow and
                                                      //        1 character space for the null terminator.
      printf("ERROR: Invalid input. Expected atleast one text value. \n");
      
      // Clear the input buffer
      while (getchar() != '\n');

      return -1;
    }

    while (getchar() != '\n'); // Clear the input buffer after name input 

    printf("Salary: ");
    if (scanf("%f", &employees[i].salary) != 1) {
      printf("ERROR: Invalid input. Expected atleast one decimal value. \n");
      return -1;
    }

    while (getchar() != '\n'); // Clear the input buffer after salary input 
  }

  // Display the employee data
  for (int i = 0; i < N; i++) {
    printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
  }

  return 0;
}
