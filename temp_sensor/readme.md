# **Sensor Data Logger**  

A simple C program that retrieves and displays sensor data based on a given sensor ID.  

## **Features**  
- Retrieves temperature, status, and timestamp for a sensor.  
- Allows user to input a sensor ID at runtime.  
- Displays the corresponding sensor details.  

## **How to Compile and Run**  
```sh
gcc main.c put_temp_data.c get_temp_data.c -o sensor_logger
./sensor_logger
```

## **Example Usage**  
```
Enter Sensor ID: 777
Sensor ID       : 777
Temperature     : 320
Status          : 2
Time Stamp      : 2025-04-02 14:55:10
```

## **Files**  
- `main.c` – Runs the program and handles user input.  
- `get_temp_data` – Functions to retrieve sensor data.
- `put_temp_data` - Functions to add the sensor data to the struct. 
- `temp_sensor.h` – Header file with function prototypes and struct definitions.

