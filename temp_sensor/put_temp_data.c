#include "temp_sensor.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

void put_sensor_data(sensor_data_t *data, uint32_t id) {
  int16_t temperature = get_temperature(id);
  uint8_t status = get_status(id);
  timestamp_t* ts_ptr = get_timestamp(id);

  if (ts_ptr != NULL) {
    strncpy(data->tsmp, *ts_ptr, sizeof(timestamp_t));  // Dereference to get the string
    data->tsmp[sizeof(timestamp_t) - 1] = '\0';  // Ensure null termination

  } else {
    printf("\nERROR: Invalid ID\n");
  }

  data->temperature = temperature;
  data->status = status;

  data->id = id;

}

void show_sensor_data(sensor_data_t data) {
  printf("Sensor ID       : %" PRIu32 "\n", data.id);
  printf("Temperature     : %" PRIi16 "\n", data.temperature);
  printf("Status          : %" PRIu8 "\n", data.status);
  printf("Time Stamp      : %s\n", data.tsmp);
}


