#ifndef BUS_H
#define BUS_H

#include "device.h"
#include <malloc.h>
#include <stdint.h>

#define BUS_NUM_SEGMENTS 0x100

typedef struct
{
    device *devices[BUS_NUM_SEGMENTS];
} bus;

void bus_free(bus *to_free)
{
    free(to_free);
}

bus *bus_init()
{
    bus *new_bus = (bus*)malloc(sizeof(bus));

    for(int n = 0; n < BUS_NUM_SEGMENTS; n++)
        new_bus->devices[n] = NULL;

    return new_bus;
}

uint8_t bus_read(bus *to_read, uint32_t address)
{
    uint8_t segment = address >> 24;

    return to_read->devices[segment]->read(
        to_read->devices[segment]->underlying,
        address
    );
}

void bus_register(bus *_bus, uint8_t segment, device *to_register)
{
    _bus->devices[segment] = to_register;
}

void bus_write(bus *to_write, uint32_t address, uint8_t byte)
{
    uint8_t segment = address >> 24;

    return to_write->devices[segment]->write(
        to_write->devices[segment]->underlying,
        address,
        byte
    );
}

#endif // BUS_H