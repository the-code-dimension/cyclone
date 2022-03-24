#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "bus.h"
#include "opcodes.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define PROC_NUM_REGS 16
#define PROC_NUM_FLOAT 4

typedef struct
{
    // general-purpose and float registers
    uint32_t reg[PROC_NUM_REGS];
    double float_reg[PROC_NUM_FLOAT];

    // special purpose pointer registers
    uint32_t stack_ptr;
    uint32_t base_ptr;

    uint32_t ins_counter;
    uint32_t flags;
    bool halted;

    bus *proc_bus;
} processor;

void processor_step(processor *to_step);

void processor_copy_reg(processor *to_copy, uint16_t instruction)
{
    to_copy->reg[(instruction & 0xF)] = to_copy->reg[(instruction & 0xFF) >> 4];
}

void processor_copy_float_reg(processor *to_copy, uint16_t instruction)
{
    to_copy->float_reg[(instruction & 0xF) - 4] = to_copy->float_reg[(instruction & 0xFF) >> 4];
}

void processor_dump(processor *to_dump)
{
    // output the program counter and the flags
    printf("PC =    0x%08X\n", to_dump->ins_counter);
    printf("flags = 0x%08X\n\n", to_dump->flags);
    printf("SP =    0x%08X\n", to_dump->stack_ptr);
    printf("BP =    0x%08X\n", to_dump->base_ptr);
    printf("\n");

    // output general purpose registers
    for(int n = 0; n < PROC_NUM_REGS; n++)
        printf("r%d = 0x%08X\n", n, to_dump->reg[n]);
    
    // output floating point registers
    for(int n = 0; n < PROC_NUM_FLOAT; n++)
        printf("rf%d = %f\n", n, to_dump->float_reg[n]);
}

void processor_free(processor *to_free)
{
    free(to_free);
}

processor *processor_init(bus *bus_ptr)
{
    processor *new_proc = (processor*)malloc(sizeof(processor));

    // zero out all of the general purpose registers
    for(int n = 0; n < PROC_NUM_REGS; n++)
        new_proc->reg[n] = 0;
    
    // zero out all of the float registers
    for(int n = 0; n < PROC_NUM_FLOAT; n++)
        new_proc->float_reg[n] = 0.0;

    new_proc->ins_counter = 0;
    new_proc->flags = 0;
    new_proc->halted = false;
    new_proc->proc_bus = bus_ptr;

    return new_proc;
}

double processor_read_double(processor *to_read)
{
    // buffer the contain the byte representation of the double
    unsigned char to_return[8];

    // retrieve the double into the buffer
    for(int n = 0; n < 8; n++)
    {
        to_return[7 - n] = bus_read(to_read->proc_bus, to_read->ins_counter++);
    }

    // very cool and radical bit hack
    return *(double*)to_return;
}

uint8_t processor_read_uint8(processor *to_read)
{
    return bus_read(to_read->proc_bus, to_read->ins_counter++);
}

uint16_t processor_read_uint16(processor *to_read)
{
    uint16_t to_return = 0;

    to_return += bus_read(to_read->proc_bus, to_read->ins_counter++);
    to_return += bus_read(to_read->proc_bus, to_read->ins_counter++) << 8;

    return to_return;
}

uint32_t processor_read_uint32(processor *to_read)
{
    uint32_t to_return = 0;

    to_return += bus_read(to_read->proc_bus, to_read->ins_counter++);
    to_return += bus_read(to_read->proc_bus, to_read->ins_counter++) << 8;
    to_return += bus_read(to_read->proc_bus, to_read->ins_counter++) << 16;
    to_return += bus_read(to_read->proc_bus, to_read->ins_counter++) << 24;

    return to_return;
}

void processor_run(processor *to_run)
{
    while(!to_run->halted)
    {
        processor_step(to_run);
    }

    printf("*** HALTED ***\n");
}

void processor_step(processor *to_step)
{
    // read a 16-bit instruction from the bus
    uint16_t instruction = processor_read_uint16(to_step);

    // decode the instruction
    switch(instruction)
    {
        case OP_HALT:
            to_step->halted = true;
            processor_dump(to_step);
            break;

        case OP_MOV_R0_IMM32:
            to_step->reg[0] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R1_IMM32:
            to_step->reg[1] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R2_IMM32:
            to_step->reg[2] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R3_IMM32:
            to_step->reg[3] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R4_IMM32:
            to_step->reg[4] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R5_IMM32:
            to_step->reg[5] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R6_IMM32:
            to_step->reg[6] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R7_IMM32:
            to_step->reg[7] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R8_IMM32:
            to_step->reg[8] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R9_IMM32:
            to_step->reg[9] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R10_IMM32:
            to_step->reg[10] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R11_IMM32:
            to_step->reg[11] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R12_IMM32:
            to_step->reg[12] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R13_IMM32:
            to_step->reg[13] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R14_IMM32:
            to_step->reg[14] = processor_read_uint32(to_step);
            break;
        case OP_MOV_R15_IMM32:
            to_step->reg[15] = processor_read_uint32(to_step);
            break;

        case OP_MOV_R0_IMM16:
            to_step->reg[0] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R1_IMM16:
            to_step->reg[1] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R2_IMM16:
            to_step->reg[2] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R3_IMM16:
            to_step->reg[3] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R4_IMM16:
            to_step->reg[4] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R5_IMM16:
            to_step->reg[5] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R6_IMM16:
            to_step->reg[6] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R7_IMM16:
            to_step->reg[7] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R8_IMM16:
            to_step->reg[8] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R9_IMM16:
            to_step->reg[9] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R10_IMM16:
            to_step->reg[10] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R11_IMM16:
            to_step->reg[11] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R12_IMM16:
            to_step->reg[12] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R13_IMM16:
            to_step->reg[13] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R14_IMM16:
            to_step->reg[14] |= processor_read_uint16(to_step);
            break;
        case OP_MOV_R15_IMM16:
            to_step->reg[15] |= processor_read_uint16(to_step);
            break;

        case OP_MOV_R0_IMM8:
            to_step->reg[0] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R1_IMM8:
            to_step->reg[1] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R2_IMM8:
            to_step->reg[2] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R3_IMM8:
            to_step->reg[3] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R4_IMM8:
            to_step->reg[4] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R5_IMM8:
            to_step->reg[5] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R6_IMM8:
            to_step->reg[6] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R7_IMM8:
            to_step->reg[7] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R8_IMM8:
            to_step->reg[8] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R9_IMM8:
            to_step->reg[9] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R10_IMM8:
            to_step->reg[10] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R11_IMM8:
            to_step->reg[11] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R12_IMM8:
            to_step->reg[12] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R13_IMM8:
            to_step->reg[13] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R14_IMM8:
            to_step->reg[14] |= processor_read_uint8(to_step);
            break;
        case OP_MOV_R15_IMM8:
            to_step->reg[15] |= processor_read_uint8(to_step);
            break;

        case OP_MOV_RF0_IMM:
            to_step->float_reg[0] = processor_read_double(to_step);
            break;
        case OP_MOV_RF1_IMM:
            to_step->float_reg[1] = processor_read_double(to_step);
            break;
        case OP_MOV_RF2_IMM:
            to_step->float_reg[2] = processor_read_double(to_step);
            break;
        case OP_MOV_RF3_IMM:
            to_step->float_reg[3] = processor_read_double(to_step);
            break;
        
        case OP_MOV_R0_R1:
        case OP_MOV_R0_R2:
        case OP_MOV_R0_R3:
        case OP_MOV_R0_R4:
        case OP_MOV_R0_R5:
        case OP_MOV_R0_R6:
        case OP_MOV_R0_R7:
        case OP_MOV_R0_R8:
        case OP_MOV_R0_R9:
        case OP_MOV_R0_R10:
        case OP_MOV_R0_R11:
        case OP_MOV_R0_R12:
        case OP_MOV_R0_R13:
        case OP_MOV_R0_R14:
        case OP_MOV_R0_R15:
        case OP_MOV_R1_R0:
        case OP_MOV_R1_R2:
        case OP_MOV_R1_R3:
        case OP_MOV_R1_R4:
        case OP_MOV_R1_R5:
        case OP_MOV_R1_R6:
        case OP_MOV_R1_R7:
        case OP_MOV_R1_R8:
        case OP_MOV_R1_R9:
        case OP_MOV_R1_R10:
        case OP_MOV_R1_R11:
        case OP_MOV_R1_R12:
        case OP_MOV_R1_R13:
        case OP_MOV_R1_R14:
        case OP_MOV_R1_R15:
        case OP_MOV_R2_R0:
        case OP_MOV_R2_R1:
        case OP_MOV_R2_R3:
        case OP_MOV_R2_R4:
        case OP_MOV_R2_R5:
        case OP_MOV_R2_R6:
        case OP_MOV_R2_R7:
        case OP_MOV_R2_R8:
        case OP_MOV_R2_R9:
        case OP_MOV_R2_R10:
        case OP_MOV_R2_R11:
        case OP_MOV_R2_R12:
        case OP_MOV_R2_R13:
        case OP_MOV_R2_R14:
        case OP_MOV_R2_R15:
        case OP_MOV_R3_R0:
        case OP_MOV_R3_R1:
        case OP_MOV_R3_R2:
        case OP_MOV_R3_R4:
        case OP_MOV_R3_R5:
        case OP_MOV_R3_R6:
        case OP_MOV_R3_R7:
        case OP_MOV_R3_R8:
        case OP_MOV_R3_R9:
        case OP_MOV_R3_R10:
        case OP_MOV_R3_R11:
        case OP_MOV_R3_R12:
        case OP_MOV_R3_R13:
        case OP_MOV_R3_R14:
        case OP_MOV_R3_R15:
        case OP_MOV_R4_R0:
        case OP_MOV_R4_R1:
        case OP_MOV_R4_R2:
        case OP_MOV_R4_R3:
        case OP_MOV_R4_R5:
        case OP_MOV_R4_R6:
        case OP_MOV_R4_R7:
        case OP_MOV_R4_R8:
        case OP_MOV_R4_R9:
        case OP_MOV_R4_R10:
        case OP_MOV_R4_R11:
        case OP_MOV_R4_R12:
        case OP_MOV_R4_R13:
        case OP_MOV_R4_R14:
        case OP_MOV_R4_R15:
        case OP_MOV_R5_R0:
        case OP_MOV_R5_R1:
        case OP_MOV_R5_R2:
        case OP_MOV_R5_R3:
        case OP_MOV_R5_R4:
        case OP_MOV_R5_R6:
        case OP_MOV_R5_R7:
        case OP_MOV_R5_R8:
        case OP_MOV_R5_R9:
        case OP_MOV_R5_R10:
        case OP_MOV_R5_R11:
        case OP_MOV_R5_R12:
        case OP_MOV_R5_R13:
        case OP_MOV_R5_R14:
        case OP_MOV_R5_R15:
        case OP_MOV_R6_R0:
        case OP_MOV_R6_R1:
        case OP_MOV_R6_R2:
        case OP_MOV_R6_R3:
        case OP_MOV_R6_R4:
        case OP_MOV_R6_R5:
        case OP_MOV_R6_R7:
        case OP_MOV_R6_R8:
        case OP_MOV_R6_R9:
        case OP_MOV_R6_R10:
        case OP_MOV_R6_R11:
        case OP_MOV_R6_R12:
        case OP_MOV_R6_R13:
        case OP_MOV_R6_R14:
        case OP_MOV_R6_R15:
        case OP_MOV_R7_R0:
        case OP_MOV_R7_R1:
        case OP_MOV_R7_R2:
        case OP_MOV_R7_R3:
        case OP_MOV_R7_R4:
        case OP_MOV_R7_R5:
        case OP_MOV_R7_R6:
        case OP_MOV_R7_R8:
        case OP_MOV_R7_R9:
        case OP_MOV_R7_R10:
        case OP_MOV_R7_R11:
        case OP_MOV_R7_R12:
        case OP_MOV_R7_R13:
        case OP_MOV_R7_R14:
        case OP_MOV_R7_R15:
        case OP_MOV_R8_R0:
        case OP_MOV_R8_R1:
        case OP_MOV_R8_R2:
        case OP_MOV_R8_R3:
        case OP_MOV_R8_R4:
        case OP_MOV_R8_R5:
        case OP_MOV_R8_R6:
        case OP_MOV_R8_R7:
        case OP_MOV_R8_R9:
        case OP_MOV_R8_R10:
        case OP_MOV_R8_R11:
        case OP_MOV_R8_R12:
        case OP_MOV_R8_R13:
        case OP_MOV_R8_R14:
        case OP_MOV_R8_R15:
        case OP_MOV_R9_R0:
        case OP_MOV_R9_R1:
        case OP_MOV_R9_R2:
        case OP_MOV_R9_R3:
        case OP_MOV_R9_R4:
        case OP_MOV_R9_R5:
        case OP_MOV_R9_R6:
        case OP_MOV_R9_R7:
        case OP_MOV_R9_R8:
        case OP_MOV_R9_R10:
        case OP_MOV_R9_R11:
        case OP_MOV_R9_R12:
        case OP_MOV_R9_R13:
        case OP_MOV_R9_R14:
        case OP_MOV_R9_R15:
        case OP_MOV_R10_R0:
        case OP_MOV_R10_R1:
        case OP_MOV_R10_R2:
        case OP_MOV_R10_R3:
        case OP_MOV_R10_R4:
        case OP_MOV_R10_R5:
        case OP_MOV_R10_R6:
        case OP_MOV_R10_R7:
        case OP_MOV_R10_R8:
        case OP_MOV_R10_R9:
        case OP_MOV_R10_R11:
        case OP_MOV_R10_R12:
        case OP_MOV_R10_R13:
        case OP_MOV_R10_R14:
        case OP_MOV_R10_R15:
        case OP_MOV_R11_R0:
        case OP_MOV_R11_R1:
        case OP_MOV_R11_R2:
        case OP_MOV_R11_R3:
        case OP_MOV_R11_R4:
        case OP_MOV_R11_R5:
        case OP_MOV_R11_R6:
        case OP_MOV_R11_R7:
        case OP_MOV_R11_R8:
        case OP_MOV_R11_R9:
        case OP_MOV_R11_R10:
        case OP_MOV_R11_R12:
        case OP_MOV_R11_R13:
        case OP_MOV_R11_R14:
        case OP_MOV_R11_R15:
        case OP_MOV_R12_R0:
        case OP_MOV_R12_R1:
        case OP_MOV_R12_R2:
        case OP_MOV_R12_R3:
        case OP_MOV_R12_R4:
        case OP_MOV_R12_R5:
        case OP_MOV_R12_R6:
        case OP_MOV_R12_R7:
        case OP_MOV_R12_R8:
        case OP_MOV_R12_R9:
        case OP_MOV_R12_R10:
        case OP_MOV_R12_R11:
        case OP_MOV_R12_R13:
        case OP_MOV_R12_R14:
        case OP_MOV_R12_R15:
        case OP_MOV_R13_R0:
        case OP_MOV_R13_R1:
        case OP_MOV_R13_R2:
        case OP_MOV_R13_R3:
        case OP_MOV_R13_R4:
        case OP_MOV_R13_R5:
        case OP_MOV_R13_R6:
        case OP_MOV_R13_R7:
        case OP_MOV_R13_R8:
        case OP_MOV_R13_R9:
        case OP_MOV_R13_R10:
        case OP_MOV_R13_R11:
        case OP_MOV_R13_R12:
        case OP_MOV_R13_R14:
        case OP_MOV_R13_R15:
        case OP_MOV_R14_R0:
        case OP_MOV_R14_R1:
        case OP_MOV_R14_R2:
        case OP_MOV_R14_R3:
        case OP_MOV_R14_R4:
        case OP_MOV_R14_R5:
        case OP_MOV_R14_R6:
        case OP_MOV_R14_R7:
        case OP_MOV_R14_R8:
        case OP_MOV_R14_R9:
        case OP_MOV_R14_R10:
        case OP_MOV_R14_R11:
        case OP_MOV_R14_R12:
        case OP_MOV_R14_R13:
        case OP_MOV_R14_R15:
        case OP_MOV_R15_R0:
        case OP_MOV_R15_R1:
        case OP_MOV_R15_R2:
        case OP_MOV_R15_R3:
        case OP_MOV_R15_R4:
        case OP_MOV_R15_R5:
        case OP_MOV_R15_R6:
        case OP_MOV_R15_R7:
        case OP_MOV_R15_R8:
        case OP_MOV_R15_R9:
        case OP_MOV_R15_R10:
        case OP_MOV_R15_R11:
        case OP_MOV_R15_R12:
        case OP_MOV_R15_R13:
        case OP_MOV_R15_R14:
            processor_copy_reg(to_step, instruction);
            break;
        
        case OP_MOV_RF0_RF1:
        case OP_MOV_RF0_RF2:
        case OP_MOV_RF0_RF3:
        case OP_MOV_RF1_RF0:
        case OP_MOV_RF1_RF2:
        case OP_MOV_RF1_RF3:
        case OP_MOV_RF2_RF0:
        case OP_MOV_RF2_RF1:
        case OP_MOV_RF2_RF3:
        case OP_MOV_RF3_RF0:
        case OP_MOV_RF3_RF1:
        case OP_MOV_RF3_RF2:
            processor_copy_float_reg(to_step, instruction);
            break;
        
        case OP_MOV_SP_R0:
        case OP_MOV_SP_R1:
        case OP_MOV_SP_R2:
        case OP_MOV_SP_R3:
        case OP_MOV_SP_R4:
        case OP_MOV_SP_R5:
        case OP_MOV_SP_R6:
        case OP_MOV_SP_R7:
        case OP_MOV_SP_R8:
        case OP_MOV_SP_R9:
        case OP_MOV_SP_R10:
        case OP_MOV_SP_R11:
        case OP_MOV_SP_R12:
        case OP_MOV_SP_R13:
        case OP_MOV_SP_R14:
        case OP_MOV_SP_R15:
            to_step->stack_ptr = to_step->reg[(instruction & 0xFF) >> 4];
            break;
        
        case OP_MOV_BP_R0:
        case OP_MOV_BP_R1:
        case OP_MOV_BP_R2:
        case OP_MOV_BP_R3:
        case OP_MOV_BP_R4:
        case OP_MOV_BP_R5:
        case OP_MOV_BP_R6:
        case OP_MOV_BP_R7:
        case OP_MOV_BP_R8:
        case OP_MOV_BP_R9:
        case OP_MOV_BP_R10:
        case OP_MOV_BP_R11:
        case OP_MOV_BP_R12:
        case OP_MOV_BP_R13:
        case OP_MOV_BP_R14:
        case OP_MOV_BP_R15:
            to_step->base_ptr = to_step->reg[(instruction & 0xFF) >> 4];
            break;
        
        case OP_MOV_R0_SP:
        case OP_MOV_R1_SP:
        case OP_MOV_R2_SP:
        case OP_MOV_R3_SP:
        case OP_MOV_R4_SP:
        case OP_MOV_R5_SP:
        case OP_MOV_R6_SP:
        case OP_MOV_R7_SP:
        case OP_MOV_R8_SP:
        case OP_MOV_R9_SP:
        case OP_MOV_R10_SP:
        case OP_MOV_R11_SP:
        case OP_MOV_R12_SP:
        case OP_MOV_R13_SP:
        case OP_MOV_R14_SP:
        case OP_MOV_R15_SP:
            to_step->reg[(instruction & 0xFF) >> 4] = to_step->stack_ptr;
            break;
        
        case OP_MOV_R0_BP:
        case OP_MOV_R1_BP:
        case OP_MOV_R2_BP:
        case OP_MOV_R3_BP:
        case OP_MOV_R4_BP:
        case OP_MOV_R5_BP:
        case OP_MOV_R6_BP:
        case OP_MOV_R7_BP:
        case OP_MOV_R8_BP:
        case OP_MOV_R9_BP:
        case OP_MOV_R10_BP:
        case OP_MOV_R11_BP:
        case OP_MOV_R12_BP:
        case OP_MOV_R13_BP:
        case OP_MOV_R14_BP:
        case OP_MOV_R15_BP:
            to_step->reg[(instruction & 0xFF) >> 4] = to_step->base_ptr;
            break;

        case OP_MOV_SP_IMM32:
            to_step->stack_ptr = processor_read_uint32(to_step);
            break;

        case OP_MOV_BP_IMM32:
            to_step->base_ptr = processor_read_uint32(to_step);
            break;

        default:
            to_step->halted = true;
            processor_dump(to_step);
            printf("\nInvalid instruction 0x%04X encountered\n\n", instruction);
            break;
    }
}

#endif // PROCESSOR_H