#include "sensor.h"

HardwareSerial RS485(2);  // Dùng UART2

ModbusMaster nodeHumidity;
ModbusMaster nodeTemperature;

void Sensor_Init() {
    RS485.begin(9600, SERIAL_8N1, RS485_RXD, RS485_TXD);

    nodeHumidity.begin(1, RS485);  // Địa chỉ Modbus của cảm biến độ ẩm
    nodeTemperature.begin(2, RS485);  // Địa chỉ Modbus của cảm biến nhiệt độ
}

// Đọc độ ẩm từ RS485
float Sensor_ReadHumidity() {
    uint8_t result = nodeHumidity.readInputRegisters(0x0000, 1);
    if (result == nodeHumidity.ku8MBSuccess) {
        return nodeHumidity.getResponseBuffer(0) / 10.0;  // Chuyển đổi giá trị
    }
    return -1;  // Trả về -1 nếu lỗi
}

// Đọc nhiệt độ từ RS485
float Sensor_ReadTemperature() {
    uint8_t result = nodeTemperature.readInputRegisters(0x0000, 1);
    if (result == nodeTemperature.ku8MBSuccess) {
        return nodeTemperature.getResponseBuffer(0) / 10.0;  // Chuyển đổi giá trị
    }
    return -1;  // Trả về -1 nếu lỗi
}

// Task đọc dữ liệu từ cảm biến
void Sensor_Task(void *parameter) {
    while (1) {
        float humidity = Sensor_ReadHumidity();
        float temperature = Sensor_ReadTemperature();

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print("%, Temperature: ");
        Serial.print(temperature);
        Serial.println("°C");

        vTaskDelay(pdMS_TO_TICKS(2000));  // Đọc mỗi 2 giây
    }
}
