#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdint.h>
#include <inttypes.h>

typedef enum { NOT_FILLED = -1, FILLED } fill_status_t;

void bubble_sort(int64_t *arr, uint32_t N);

#endif

