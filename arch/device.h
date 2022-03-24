#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

typedef struct
{
    void *underlying;

    uint8_t (*read)(void *underlying, uint32_t address);
    void (*write)(void *underlying, uint32_t address, uint8_t byte);
} device;

#endif // DEVICE_H