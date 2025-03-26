#ifndef BOOK_DB_H
#define BOOK_DB_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100 
#define MAX_AUTHOR_LEN 100

typedef struct {
  uint8_t day;
  uint8_t month;
  uint16_t year;
} date_t;

typedef struct {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LEN];
  float price;
  date_t publication_date;
} book_t;

typedef union {
    int8_t i8;
    int16_t i16;
    int32_t i32;
} intX_t;

typedef enum { NOT_FILLED = -1, FILLED } fill_status_t;

void print_book(book_t *books, uint32_t num_of_books); // Styled printing of the books
void sort_by_year(book_t *books, uint32_t num_of_books); // Sort using the inner struct 
fill_status_t fill_book(book_t *books, char *title, char *author, float price, uint8_t day, uint8_t month, uint16_t year);

#endif
