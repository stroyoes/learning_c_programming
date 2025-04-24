#include "temp_sensor.h"

#include <stdio.h>

void print_arr(uint32_t *arr, uint16_t size_of_arr) {
  printf("[");
  for (uint16_t i = 0; i < size_of_arr; i++) {
    printf("%d", arr[i]);
    (i < (size_of_arr - 1)) ? printf(", ") : printf(" ");;

  }
  printf("]\n");
}

static inline int get_index_from_id(uint32_t id) {
  uint32_t ids[6] = {676, 677, 777, 767, 666, 766};

  // Check if the element is in the array
  for (int i = 0; i < sizeof(ids) / sizeof(ids[0]); i++) {
    if (ids[i] == id) {
      return i;
    }
  }
  return -1;
}

int16_t get_temperature(uint32_t id) {
  int16_t all_temps[6] = {250, -180, 320, 150, -75, 400};

  int posn = get_index_from_id(id);

  if (posn < 0) {
    printf("\nERROR: Invalid index was given \n");
    return -1;
  }

  return all_temps[posn];
}

uint8_t get_status(uint32_t id) {
  int8_t all_statuses[6] = {0, 1, 2, 3, 4, 5};

  int posn = get_index_from_id(id);

  if (posn < 0) {
    printf("\nERROR: Invalid index was given \n");
    return -1;
  }

  return all_statuses[posn];
}

timestamp_t* get_timestamp(uint32_t id) {
  
  static timestamp_t all_timestamps[6] = {
    "2025-04-02 12:30:45",
    "2025-04-02 13:45:20",
    "2025-04-02 14:55:10",
    "2025-04-02 15:05:50",
    "2025-04-02 16:20:30",
    "2025-04-02 17:40:15"
  };

  int posn = get_index_from_id(id);

  if (posn < 0) {
    printf("\nERROR: Invalid index was given \n");
    return NULL;
  }

  return &all_timestamps[posn]; //  TODO: Remeber to dereference int the main function
}


