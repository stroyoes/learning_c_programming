#include <stdio.h>

typedef struct {
  float coff;
  int expo;
} term_t;

// Some helper functions 
void display_polyn(term_t *polyn, int num_of_terms) {
  for (int i = 0; i < num_of_terms; i++) {
    printf("%fx^%d", polyn[i].coff, polyn[i].expo);

    if (i != num_of_terms - 1) {
      printf(" + ");
    }
  }
  printf("\n");
}

void read_polyn(term_t *polyn, int num_of_terms) {
  printf("Enter each term of the polynomial (in this format '<coef>x^<exponent>'): \n");

  for (int i = 0; i < num_of_terms; i++) {
    printf(" Term %d: ", i + 1);
    scanf("%fx^%d", &polyn[i].coff, &polyn[i].expo);

  }
}

void padd(term_t *polyn_1, int N1, term_t *polyn_2, int N2, term_t *polyn_result, int *N_result) {
  int i = 0, j = 0, k = 0;

  while (i < N1 && j < N2) {
    if (polyn_1[i].expo == polyn_2[j].expo) {
      polyn_result[k].expo = polyn_1[i].expo;

      polyn_result[k].coff = (polyn_1[i].coff + polyn_2[j].coff);

      i++;j++;k++;
    } else if (polyn_1[i].expo > polyn_2[j].expo) {
      polyn_result[k].expo = polyn_1[i].expo;
      polyn_result[k].coff = polyn_1[i].coff;

      i++;k++;
    } else {
      polyn_result[k].expo = polyn_2[j].expo;
      polyn_result[k].coff = polyn_2[j].coff;

      j++;k++;

    }
  }

  while (i < N1) {
    polyn_result[k].expo = polyn_1[i].expo;
    polyn_result[k].coff = polyn_1[i].coff;

    i++;k++;

  }
  while (j < N2) {
    polyn_result[k].expo = polyn_2[j].expo;
    polyn_result[k].coff = polyn_2[j].coff;

    j++;k++;

  }

  *N_result = k; // The length of the resultant polynomial 

}

int main() {
  int terms_1, terms_2, N_terms;
  
  // Get number of terms
  printf("Enter the number of terms in polynomial 1: ");
  scanf("%d", &terms_1);

  printf("Enter the number of terms in polynomial 1: ");
  scanf("%d", &terms_2);

  term_t polyn_1[terms_1], polyn_2[terms_2], polyn_result[terms_1 + terms_2];

  // Get the polynomials 
  printf("Get polynomial 1: \n");
  read_polyn(polyn_1, terms_1);

  printf("Get polynomial 2: \n");
  read_polyn(polyn_2, terms_2);

  // Display the polynomials 
  printf("First polynomial: \n");
  display_polyn(polyn_1, terms_1);

  printf("Second polynomial: \n");
  display_polyn(polyn_2, terms_2);

  // Add the polynomials 
  padd(polyn_1, terms_1, polyn_2,terms_2, polyn_result, &N_terms);

  // Display the added polynomial 
  printf("Sum: \n");
  display_polyn(polyn_result, N_terms);

  return 0;
}

/*
Output
------
Enter the number of terms in polynomial 1: 3
Enter the number of terms in polynomial 1: 3
Get polynomial 1:
Enter each term of the polynomial (in this format '<coef>x^<exponent>'):
 Term 1: 5x^3
 Term 2: 3x^1
 Term 3: 7x^0
Get polynomial 2:
Enter each term of the polynomial (in this format '<coef>x^<exponent>'):
 Term 1: 3x^3
 Term 2: 1x^2
 Term 3: 3x^0
First polynomial:
5.000000x^3 + 3.000000x^1 + 7.000000x^0
Second polynomial:
3.000000x^3 + 1.000000x^2 + 3.000000x^0
Sum:
8.000000x^3 + 1.000000x^2 + 3.000000x^1 + 10.000000x^0
*/
