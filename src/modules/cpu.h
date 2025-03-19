// cpu.h
#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    uint16_t pc;  
    uint16_t sp;  
    uint16_t af;  
    uint16_t bc;  
    uint16_t de;  
    uint16_t hl;  
    uint8_t memory[65536];  
} Z80;

void reset_cpu(Z80 *cpu);
void execute_instruction(Z80 *cpu);
uint8_t read_memory(Z80 *cpu, uint16_t addr);

#endif 
