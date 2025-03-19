#include "modules/memory.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void load_program(Z80 *cpu, const uint8_t *program, size_t size) {
    memcpy(cpu->memory, program, size);
}

void write_memory(Z80 *cpu, uint16_t addr, uint8_t value) {
    if (addr < 0x10000) {
        cpu->memory[addr] = value;
    } else {
        printf("Invalid memory address: %04X\n", addr);
    }
}

uint8_t read_memory(Z80 *cpu, uint16_t addr) {
    if (addr < 0x0000 || addr > 0xFFFF) {
        printf("Invalid memory address: %04X\n", addr);
        return 0;
    }
    return cpu->memory[addr]; 
}
