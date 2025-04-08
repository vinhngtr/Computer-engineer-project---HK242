#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <ModbusMaster.h>
//#include <main.cpp>
// Khai báo chân UART cho RS485
#define RS485_RXD 16
#define RS485_TXD 15

// Khai báo đối tượng Modbus
extern ModbusMaster nodeHumidity;
extern ModbusMaster nodeTemperature;

// Khởi tạo cảm biến
void Sensor_Init();

// Hàm đọc dữ liệu từ cảm biến
float Sensor_ReadHumidity();
float Sensor_ReadTemperature();

// Task đọc dữ liệu cảm biến
void Sensor_Task(void *parameter);

#endif
