#include "modules/cpu.h"
#include <stdio.h>

void reset_cpu(Z80 *cpu) {
    cpu->pc = 0x0000;
    cpu->sp = 0xFFFF;  
    cpu->af = 0x0000; 
    cpu->bc = 0x0000; 
    cpu->de = 0x0000;  
    cpu->hl = 0x0000; 

    for (int i = 0; i < 65536; i++) {
        cpu->memory[i] = 0;
    }
}


void execute_instruction(Z80 *cpu) {
    uint8_t opcode = cpu->memory[cpu->pc++];
    switch (opcode) {
        case 0x00: break; // NOP
        case 0x3E: cpu->af = (cpu->af & 0xFF00) | cpu->memory[cpu->pc++]; break; // LD A, n
        case 0x06: cpu->bc = (cpu->bc & 0xFF00) | cpu->memory[cpu->pc++]; break; // LD B, n
        case 0xC3: cpu->pc = cpu->memory[cpu->pc] | (cpu->memory[cpu->pc + 1] << 8); break; // JP nn
        default: printf("Opcode not implemented: 0x%02X\n", opcode); break;
    }
}
