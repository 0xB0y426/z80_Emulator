#ifndef MEMORY_H
#define MEMORY_H

#include "cpu.h"
#include <stddef.h>

void load_program(Z80 *cpu, const uint8_t *program, size_t size);
void write_memory(Z80 *cpu, uint16_t addr, uint8_t value);
void load_program_from_file(Z80 *cpu, const char *filename);

#endif