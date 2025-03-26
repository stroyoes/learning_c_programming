#include "clock.h"
#include <stdio.h>

int main() {
    clock_t clock1 = clock_create(10, 30);
    printf("Initial time: %s\n", clock1.text);

    clock_t clock2 = clock_add(clock1, 45);
    printf("After adding 45 minutes: %s\n", clock2.text);

    clock_t clock3 = clock_subtract(clock2, 90);
    printf("After subtracting 90 minutes: %s\n", clock3.text);

    if (clock_is_equal(clock1, clock3)) {
        printf("\"clock1\" and \"clock3\" are equal.\n");
    } else {
        printf("\"clock1\" and \"clock3\" are not equal.\n");
    }

    return 0;
}

