#ifndef RS485_SENSOR_H
#define RS485_SENSOR_H

#include <Arduino.h>
#include <ModbusRTU.h>

// RS485 UART pins
#define RS485_RX 18  // GP18
#define RS485_TX 17  // GP17

// Cảm biến Modbus ID
#define SENSOR_ID 0x01

// Khởi tạo RS485
void initRS485();

// Đọc nhiệt độ và độ ẩm
float readRS485Temperature();
float readRS485Humidity();

// Gọi mỗi vòng lặp
void handleModbusTask();

#endif // RS485_SENSOR_H
