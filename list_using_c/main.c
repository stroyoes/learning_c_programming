#include "clist.h"
#include "clist_err.h"

#include <stdio.h>
#include <stdlib.h>

int double_value(int x) {
    return x * 2;
}

int is_even(int x) {
    return x % 2 == 0;
}

void print_clist(clist_t *clist) {
    printf("[");
    for (int i = 0; i < clist->size; i++) {
        printf("%d", clist->buffer[i]);
        if (i < clist->size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    printf("Creating clist...\n");
    clist_t *list = create_clist();
    if (list == NULL) {
        printf("Error: %s\n", clist_err_msg(clist_error));
        return 1;
    }

    printf("\nAppending elements...\n");
    for (int i = 1; i <= 10; i++) {
        append(list, i);
    }
    printf("List after appending 1 to 10: ");
    print_clist(list);

    printf("\nGetting element at index 3: %d\n", get(list, 3));
    printf("Getting element at index -1 (last element): %d\n", get(list, -1));

    printf("\nChecking if list contains 5: %s\n", contains(list, 5) ? "Yes" : "No");
    printf("Counting occurrences of 5: %d\n", count(list, 5));

    printf("\nRemoving element 5...\n");
    remove_elem(list, 5);
    printf("List after removing 5: ");
    print_clist(list);

    printf("\nSlicing list from index 2 to 6...\n");
    clist_t *sliced = slice(list, 2, 6);
    if (sliced == NULL) {
        printf("Error: %s\n", clist_err_msg(clist_error));
    } else {
        printf("Sliced list: ");
        print_clist(sliced);
    }

    printf("\nReversing original list...\n");
    clist_t *reversed_list = reversed(list);
    printf("Reversed list: ");
    print_clist(reversed_list);

    printf("\nConcatenating list + sliced list...\n");
    clist_t *clists_to_concat[] = { list, sliced };
    clist_t *concatenated = concat(2, clists_to_concat);
    if (concatenated == NULL) {
        printf("Error: %s\n", clist_err_msg(clist_error));
    } else {
        printf("Concatenated list: ");
        print_clist(concatenated);
    }

    printf("\nMapping (doubling values) on original list...\n");
    clist_t *mapped = map(list, double_value);
    if (mapped == NULL) {
        printf("Error: %s\n", clist_err_msg(clist_error));
    } else {
        printf("Mapped list (x2): ");
        print_clist(mapped);
    }

    printf("\nFiltering (keeping even numbers) on original list...\n");
    clist_t *filtered = filter(list, is_even);
    if (filtered == NULL) {
        printf("Error: %s\n", clist_err_msg(clist_error));
    } else {
        printf("Filtered list (evens): ");
        print_clist(filtered);
    }

    printf("\nLengths:\n");
    printf("Original list length: %d\n", length(list));
    printf("Filtered list length: %d\n", length(filtered));

    // Clean up
    destroy_list(list);
    destroy_list(sliced);
    destroy_list(reversed_list);
    destroy_list(concatenated);
    destroy_list(mapped);
    destroy_list(filtered);

    printf("\nAll lists destroyed. Program complete!\n");

    return 0;
}

