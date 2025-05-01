#include "sep_odd_n_even.h"

#include <stdio.h>

int main() {

  // Write the num file
  write_nums_to_file();

  // Now read it 
  print_from_file("Nums", NUM_FILE);

  // Seperate the odd and even numbers 
  sep_odd_n_even();

  printf("\n");

  // Read even file 
  print_from_file("Evens", EVEN_FILE);
  
  printf("\n");

  print_from_file("Odds", ODD_FILE);
}
