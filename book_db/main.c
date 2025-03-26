#include "book_db.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>

#include <string.h>

static inline intX_t str_to_intX(const char *str, int bits, int8_t *success) {
  errno = 0; // Global flag set by strtol function 

  char *endptr; //  NOTE: Should be null character if there arent any errors
  long num = strtol(str, &endptr, 10); //  NOTE: Converts string to long int safely. 
                                       //        The endptr points to any invalid part (if any).
                                       //        The '10' represents the numerical base.

  intX_t result = {0};
  *success = -1; // Initialize as unsuccessful 

  // Handling errors
  if (*endptr != '\0' || errno == ERANGE) return result;
  //  NOTE: ERANGE means the number is too big or too small to fit in a long.
  //        This protects against overflow/underflow.

  // Assign based on bit size and check range
  if (bits == 8) {
    if (num < INT8_MIN || num > INT8_MAX) return result;
    result.i8 = (int8_t)num;
  } else if (bits == 16) {
    if (num < INT16_MIN || num > INT16_MAX) return result;
    result.i16 = (int16_t)num;
  } else if (bits == 32) {
    if (num < INT32_MIN || num > INT32_MAX) return result;
    result.i32 = (int32_t)num;
  } else {
    return result; // Invalid bit size 
  } 

  *success = 0; // Mark successful conversion 
  return result;
}

int main(int argc, char **argv) {
  book_t books[MAX_BOOKS];
  uint32_t num_of_books = 0;

  int8_t success;

  if (argc < 3) {
    printf("Usage: %s -n <total_books> [-add <Title> <Author> <Price> <Day> <Month> <Year>]...\nThe '-add' option can be repeated a max of 'n' times. \n", argv[0]);
    return -1;
  }

  if (strcmp(argv[1], "-n") != 0) {
    printf("\nERROR: First argument to be passed is the number of books !\n");
    return -1;
  }

  intX_t temp_str_to_int32 = str_to_intX(argv[2], 32, &success);
  if (success == 0) {
    num_of_books = temp_str_to_int32.i32;
  } //  NOTE: We are assuminng the integers never become -ves 

  if (num_of_books <= 0) {
    printf("\nERROR: Invalid number of books !\n");
    return -1;
  }

  uint32_t a_count = 0; // Track occurence of -add 

  for (int i = 3; i < argc; i++) {
    if (strcmp(argv[i], "-add") == 0) {
      if (++a_count > num_of_books) {
        printf("\nERROR: Number of '-add' options cannot exceed the number of books !\n");
        return -1;
      }
      
      // Check if there are exactly 6 arguments after -a 
      if (i + 6 >= argc || (i+7 < argc && strcmp(argv[i+7], "-add") != 0)) {
        printf("\nERROR: '-add' must be followed by 6 values !\n");
        return -1;
      }

      for (int b = 0; b < 6; b++) {
        int8_t flag_1, flag_2, flag_3;

        intX_t temp_day, temp_month, temp_year;
        
        temp_day = str_to_intX(argv[i+4], 8, &flag_1);
        temp_month = str_to_intX(argv[i+5], 8, &flag_2);
        temp_year = str_to_intX(argv[i+6], 16, &flag_3);

        if (
          flag_1 == 0 && flag_2 == 0 && flag_3 == 0
        ) {
          if (fill_book(&books[a_count - 1], argv[i+1], argv[i+2], atof(argv[i+3]), temp_day.i8, temp_month.i8, temp_year.i16) == NOT_FILLED) {
            printf("\nERROR: Book db wasn't filled !\n");
            return -1;
          }
        }
      }

    i += 6; // Skip the 6 arguments processed


    }
  }

  printf("\nINFO: Book%s Filled! \n", (num_of_books > 1 ? "s" : ""));

  print_book(books, num_of_books);

  printf("\nINFO: Sorting the books db by year ... \n");

  sort_by_year(books, num_of_books);

  printf("\nBooks sorted: \n");

  print_book(books, num_of_books);

  
}
