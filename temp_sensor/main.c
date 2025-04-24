#include "temp_sensor.h"

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int main() {
  sensor_data_t sensor;
  uint32_t id;

  printf("( ");
  
  uint32_t ids[6] = {676, 677, 777, 767, 666, 766};
  
  printf("\nThe available ids are : \n");
  print_arr(ids, sizeof(ids) / sizeof(ids[0]));

  printf(" )\n");

  printf("Enter the sensor id: ");

  if (scanf("%" SCNu32, &id) != 1) {
    printf("\nERROR: Invalid input. Exiting...\n");
    return -1;
  }

  printf("\n");

  put_sensor_data(&sensor, id);
  show_sensor_data(sensor);

  return 0;
}

