#ifndef DARTS_H
#define DARTS_H 

#include <stdint.h>

typedef float coordinate_t[2]; //  NOTE: An alias for an array of two float values. 

uint8_t get_score(coordinate_t landing_position);

#endif
