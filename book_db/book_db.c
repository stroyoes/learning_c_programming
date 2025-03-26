#include "book_db.h"

#include <inttypes.h>
#include <stdio.h>
#include <string.h>

void print_book(book_t *books, uint32_t num_of_books) {

  printf(" %-30s %-20s %-7s %-10s \n", "Title", "Author", "Price", "Pub. Date");
  //  NOTE: Each column is left-aligned (- sign in %-Ns) and takes up a fixed width to 
  //        ensure proper alignment.

  for (uint32_t i = 0; i < num_of_books; i++) {
    printf(
      " %-30s %-20s %-7.2f %02" PRIu8 "-%02" PRIu8 "-%4" PRIu16 "\n" , 
      books[i].title, books[i].author, books[i].price, books[i].publication_date.day,
      books[i].publication_date.month, books[i].publication_date.year
    );
  }
  printf("\n");
}

// Do a bubble sort 
void sort_by_year(book_t *books, uint32_t num_of_books) {
  for (uint32_t i = 0; i < num_of_books; i++) {
    for (uint32_t j = 0; j < num_of_books - i - 1; j++) {
      if (books[j].publication_date.year < books[j+1].publication_date.year) {
        book_t temp_book = books[j];
        books[j] = books[j+1];
        books[j+1] = temp_book;
      }
    }
  }
}

fill_status_t fill_book(book_t *book, char *title, char *author, float price, uint8_t day, uint8_t month, uint16_t year) {
  if (
    strlen(title) >= MAX_TITLE_LENGTH || strlen(author) >= MAX_AUTHOR_LEN
  ) {
    printf("\nERROR: Title and Author strings exceeds the limit !\n");
    return NOT_FILLED;
  }

  strcpy(book->title, title);
  strcpy(book->author, author);

  book->price = price;
  
  book->publication_date.day = day;
  book->publication_date.year = year;
  book->publication_date.month = month;

  return FILLED;
}


