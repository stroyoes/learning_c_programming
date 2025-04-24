#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <stdint.h>

typedef char timestamp_t[20]; //  NOTE:  Format is "YYYY-MM-DD HH:MM:SS" 
  //         (19 characters + null terminator)

typedef struct {
  uint32_t id;
  int16_t temperature;
  uint8_t status; // Status should be from 0 to 5
  timestamp_t tsmp; // Holds the readable time stamp string

} sensor_data_t;

int16_t get_temperature(uint32_t id);
uint8_t get_status(uint32_t id);
timestamp_t* get_timestamp(uint32_t id);

void put_sensor_data(sensor_data_t *data, uint32_t id);
void show_sensor_data(sensor_data_t data);
void print_arr(uint32_t *arr, uint16_t size_of_arr);

#endif 

