#include "arch/bus.h"
#include "arch/memory.h"
#include "arch/processor.h"

int main()
{
    memory *main_mem = memory_init();
    bus *main_bus = bus_init();

    for(int n = 0; n < MEMORY_SEGMENTS; n++)
        bus_register(main_bus, n, main_mem->_device);

    bus_write(main_bus, 0, 0x11);
    bus_write(main_bus, 1, 0x00);
    bus_write(main_bus, 2, 0xDD);
    bus_write(main_bus, 3, 0xCC);
    bus_write(main_bus, 4, 0xBB);
    bus_write(main_bus, 5, 0xAA);
    bus_write(main_bus, 6, 0x18);
    bus_write(main_bus, 7, 0x00);
    bus_write(main_bus, 8, 0x19);
    bus_write(main_bus, 9, 0x00);
    bus_write(main_bus, 10, 0x2a);
    bus_write(main_bus, 11, 0x00);
    bus_write(main_bus, 12, 0x3b);
    bus_write(main_bus, 13, 0x00);

    /*bus_write(main_bus, 0, 0xFF);
    bus_write(main_bus, 1, 0x00);
    bus_write(main_bus, 2, 0x3F);
    bus_write(main_bus, 3, 0xBF);
    bus_write(main_bus, 4, 0x97);
    bus_write(main_bus, 5, 0x24);
    bus_write(main_bus, 6, 0x74);
    bus_write(main_bus, 7, 0x53);
    bus_write(main_bus, 8, 0x8E);
    bus_write(main_bus, 9, 0xF3);
    bus_write(main_bus, 10, 0x34);*/

    //['f3', '8e', '53', '74', '24', '97', 'bf', '3f']

    processor *test = processor_init(main_bus);
    processor_run(test);
    processor_free(test);

    memory_free(main_mem);
    bus_free(main_bus);

    return 0;
}