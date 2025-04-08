#include "rs485_sensor.h"

// Modbus đối tượng toàn cục
ModbusRTU mb;

// Biến tạm lưu raw data
uint16_t temperatureRaw = 0;
uint16_t humidityRaw = 0;

void initRS485() {
  Serial2.begin(9600, SERIAL_8N1, RS485_RX, RS485_TX);
  mb.begin(&Serial2);  // Không có DE/RE
  mb.master();
}

float readRS485Temperature() {
  if (mb.readHreg(SENSOR_ID, 0x0001, &temperatureRaw, 1)) {
    return temperatureRaw / 10.0;  // ví dụ: 253 → 25.3°C
  }
  return NAN;
}

float readRS485Humidity() {
  if (mb.readHreg(SENSOR_ID, 0x0002, &humidityRaw, 1)) {
    return humidityRaw / 10.0;
  }
  return NAN;
}

void handleModbusTask() {
  mb.task();  // cần gọi trong loop()
}
