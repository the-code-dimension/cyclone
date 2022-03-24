#ifndef MEMORY_H
#define MEMORY_H

#include "bus.h"
#include "device.h"
#include <malloc.h>

#define MEMORY_SEGMENTS 0xFD
#define MEMORY_SIZE 0xFD000000
#define MEMORY_START 0x00000000

uint8_t memory_read(void *to_read, uint32_t address);
void memory_write(void *to_write, uint32_t address, uint8_t byte);

typedef struct
{
    uint8_t *buffer;
    device *_device;
} memory;

void memory_free(memory *to_free)
{
    free(to_free->buffer);
    free(to_free->_device);
    free(to_free);
}

memory *memory_init()
{
    memory *new_memory = (memory*)malloc(sizeof(memory));

    new_memory->buffer = (uint8_t*)malloc(MEMORY_SIZE);

    new_memory->_device = (device*)malloc(sizeof(device));
    new_memory->_device->underlying = new_memory;
    new_memory->_device->read = &memory_read;
    new_memory->_device->write = &memory_write;

    return new_memory;
}

uint8_t memory_read(void *to_read, uint32_t address)
{
    return ((memory*)to_read)->buffer[address + MEMORY_START];
}

void memory_write(void *to_write, uint32_t address, uint8_t byte)
{
    ((memory*)to_write)->buffer[address + MEMORY_START] = byte;
}

#endif // MEMORY_H