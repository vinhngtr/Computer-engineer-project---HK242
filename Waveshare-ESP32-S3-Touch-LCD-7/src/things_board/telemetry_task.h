#ifndef TELEMETRY_TASK_H
#define TELEMETRY_TASK_H

#include "config.h"
#include "rs485_sensor.h"

// Telemetry task function declaration
void telemetryTask(void *pvParameters);

// Initialize Telemetry task
void initTelemetryTask();

#endif // TELEMETRY_TASK_H