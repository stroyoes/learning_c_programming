#include "clock.h"

#include <stdio.h>
#include <string.h>

static inline int calculate_hour(int hour, int minute) {
  
  int total_minutes = hour * 60 + minute; // Convert everything to total total_minutes 
  total_minutes = (total_minutes % (24 * 60) + (24 * 60)) % (24 * 60); // Ensure positive wrap
  return total_minutes / 60;

}

static inline int calculate_minute(int minute) {
  return (minute % 60 + 60) % 60; // Always ensure 0-59 range

}

clock_t clock_create(int hour, int minute) {
  clock_t clock;

  sprintf(clock.text, "%02d:%02d", calculate_hour(hour, minute), calculate_minute(minute));
  return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
  int hour, minute;

  sscanf(clock.text, "%2d:%2d", &hour, &minute);
  minute += minute_add;

  sprintf(clock.text, "%02d:%02d", calculate_hour(hour, minute), calculate_minute(minute));
  return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
  int hour, minute;

  sscanf(clock.text, "%2d:%2d", &hour, &minute);
  minute -= minute_subtract;

  sprintf(clock.text, "%02d:%02d", calculate_hour(hour, minute), calculate_minute(minute));
  return clock;
}

bool clock_is_equal(clock_t a, clock_t b) {
  return strcmp(a.text, b.text) == 0;
}
