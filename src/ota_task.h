#ifndef OTA_TASK_H
#define OTA_TASK_H

#include <stddef.h>
#include <stdint.h>
#include <string>

#if THINGSBOARD_ENABLE_OTA
#include <mbedtls/md.h>

void initOtaTask(const char* fwTitle, const char* fwVersion);
void startFirmwareUpdate(std::size_t fwSize, const std::string& fwAlgorithm,
                         const std::string& fwChecksum, mbedtls_md_type_t checksumType);
void handleFirmwareChunk(std::size_t chunkIndex, uint8_t* data, std::size_t size);

#endif // THINGSBOARD_ENABLE_OTA

#endif // OTA_TASK_H
