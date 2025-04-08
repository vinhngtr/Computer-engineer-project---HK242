#ifndef COREIOT_TASK_H
#define COREIOT_TASK_H

#include "config.h"

// CoreIOT task function declaration
void coreiotTask(void *pvParameters);

// Initialize CoreIOT task
void initCoreIOTTask();

// Array of RPC callbacks
extern const std::array<RPC_Callback, 1U> callbacks;

// Attribute callbacks
extern const Shared_Attribute_Callback attributes_callback;
extern const Attribute_Request_Callback attribute_shared_request_callback;

#endif // COREIOT_TASK_H