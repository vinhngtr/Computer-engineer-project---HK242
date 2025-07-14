#include "ota_task.h"

#if THINGSBOARD_ENABLE_OTA

#include <Arduino_ESP32_Updater.h>
#include <mbedtls/md.h>
#include "OTA_Update_Callback.h"
#include "OTA_Handler.h"

// ---------------------- Logger ----------------------
struct OtaLogger {
  static void log(const char* msg) {
    if (msg != nullptr) {
      Serial.println(msg);
    }
  }
};

// ---------------------- Biến OTA toàn cục ----------------------
static Arduino_ESP32_Updater otaUpdater;
static OTA_Update_Callback* otaCallback = nullptr;
static OTA_Handler<OtaLogger>* otaHandler = nullptr;
static bool isOtaInitialized = false;

// ---------------------- Callbacks ----------------------

// Gửi yêu cầu lên ThingsBoard để nhận chunk mới
static bool publishFirmwareChunk(const size_t& index) {
  Serial.printf("Requesting chunk: %u\n", (unsigned)index);
  
  // TODO: Thực hiện việc gửi request thực sự lên ThingsBoard
  // Ví dụ: thingsBoardClient.sendRPC("requestFirmwareChunk", index);
  
  // Tạm thời trả về true, cần implement thực tế
  return true;
}

// Gửi trạng thái OTA lên server
static bool sendFirmwareState(const char* state, const char* message) {
  if (state == nullptr) {
    Serial.println("Error: OTA state is null");
    return false;
  }
  
  Serial.printf("OTA State: %s | Message: %s\n", state, message ? message : "none");
  
  // TODO: Gửi state thực sự lên ThingsBoard
  // Ví dụ: thingsBoardClient.sendTelemetry("fw_state", state);
  
  return true;
}

// Gọi khi quá trình OTA kết thúc (thành công hoặc thất bại)
static void finishFirmwareUpdate(const bool& success) {
  Serial.printf("OTA update %s.\n", success ? "successful" : "failed");
  
  if (success) {
    Serial.println("Device will restart in 3 seconds...");
    delay(3000);
    ESP.restart();
  } else {
    Serial.println("OTA update failed. Device continues normal operation.");
  }
}

// Gọi mỗi khi tiến trình cập nhật có tiến độ mới
static void reportProgress(const size_t& current, const size_t& total) {
  if (total > 0) {
    float percentage = (float)current / total * 100.0f;
    Serial.printf("OTA Progress: %u / %u (%.1f%%)\n", 
                  (unsigned)current, (unsigned)total, percentage);
  }
}

// ---------------------- Public API ----------------------

void initOtaTask(const char* fwTitle, const char* fwVersion) {
  // Kiểm tra input parameters
  if (fwTitle == nullptr || fwVersion == nullptr) {
    Serial.println("Error: Invalid firmware title or version");
    return;
  }
  
  // Tránh khởi tạo lại nếu đã được khởi tạo
  if (isOtaInitialized) {
    Serial.println("OTA already initialized");
    return;
  }
  
  try {
    // Khởi tạo callback - sử dụng new thay vì static
    otaCallback = new OTA_Update_Callback(
      reportProgress,
      finishFirmwareUpdate,
      fwTitle,
      fwVersion,
      &otaUpdater
    );
    
    if (otaCallback == nullptr) {
      Serial.println("Error: Failed to create OTA callback");
      return;
    }

    // Khởi tạo handler
    otaHandler = new OTA_Handler<OtaLogger>(
      publishFirmwareChunk,
      sendFirmwareState,
      []() -> bool {
        Serial.println("OTA handler finish called");
        return true;
      }
    );
    
    if (otaHandler == nullptr) {
      Serial.println("Error: Failed to create OTA handler");
      delete otaCallback;
      otaCallback = nullptr;
      return;
    }

    isOtaInitialized = true;
    Serial.println("OTA initialized successfully");
    
  } catch (const std::exception& e) {
    Serial.printf("Error initializing OTA: %s\n", e.what());
  }
}

void startFirmwareUpdate(std::size_t fwSize, const std::string& fwAlgorithm,
                         const std::string& fwChecksum, mbedtls_md_type_t checksumType) {
  if (!isOtaInitialized) {
    Serial.println("Error: OTA not initialized!");
    return;
  }
  
  if (otaHandler == nullptr || otaCallback == nullptr) {
    Serial.println("Error: OTA components not available!");
    return;
  }
  
  if (fwSize == 0) {
    Serial.println("Error: Invalid firmware size");
    return;
  }
  
  if (fwChecksum.empty()) {
    Serial.println("Error: Invalid firmware checksum");
    return;
  }
  
  Serial.printf("Starting firmware update - Size: %u, Algorithm: %s\n", 
                (unsigned)fwSize, fwAlgorithm.c_str());
  
  try {
    otaHandler->Start_Firmware_Update(otaCallback, fwSize, fwAlgorithm, fwChecksum, checksumType);
  } catch (const std::exception& e) {
    Serial.printf("Error starting firmware update: %s\n", e.what());
  }
}

void handleFirmwareChunk(std::size_t chunkIndex, uint8_t* data, std::size_t size) {
  if (!isOtaInitialized) {
    Serial.println("Error: OTA not initialized!");
    return;
  }
  
  if (otaHandler == nullptr) {
    Serial.println("Error: OTA handler not available!");
    return;
  }
  
  if (data == nullptr || size == 0) {
    Serial.println("Error: Invalid chunk data");
    return;
  }
  
  try {
    otaHandler->Process_Firmware_Packet(chunkIndex, data, size);
  } catch (const std::exception& e) {
    Serial.printf("Error processing firmware chunk: %s\n", e.what());
  }
}

void cleanupOtaTask() {
  if (otaHandler) {
    delete otaHandler;
    otaHandler = nullptr;
  }
  
  if (otaCallback) {
    delete otaCallback;
    otaCallback = nullptr;
  }
  
  isOtaInitialized = false;
  Serial.println("OTA cleanup completed");
}

bool isOtaReady() {
  return isOtaInitialized && (otaHandler != nullptr) && (otaCallback != nullptr);
}

#endif // THINGSBOARD_ENABLE_OTA