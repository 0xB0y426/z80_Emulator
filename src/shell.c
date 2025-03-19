#include "modules/shell.h"
#include "modules/memory.h"  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start_shell(Z80 *cpu) {
    char command[256];
    system("clear");

    printf("\x1b[36m                      Z80 EMULATOR\n");
    printf("\x1b[36m                     Author: Raidboy\n\x1b[0m");
    printf("\x1b[36m                 Write help to see commands\n\x1b[0m");

    while (1) {
        printf("\x1b[32mz80> \x1b[0m");  
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "run", 3) == 0) {
            execute_instruction(cpu);
        } else if (strncmp(command, "regs", 4) == 0) {
            printf("PC: %04X AF: %04X BC: %04X DE: %04X HL: %04X\n", cpu->pc, cpu->af, cpu->bc, cpu->de, cpu->hl);
        } else if (strncmp(command, "exit", 4) == 0) {
            break;
        } else if (strncmp(command, "set ", 4) == 0) {
            uint16_t addr;
            uint8_t value;
            if (sscanf(command + 4, "%hx %hhx", &addr, &value) == 2) {
                write_memory(cpu, addr, value);  
                printf("Mem[%04X] set to %02X\n", addr, value);
            } else {
                printf("\x1b[31mUsage: set <addr> <val>\x1b[0m\n");
            }
        } else if (strncmp(command, "reset", 5) == 0) {
            reset_cpu(cpu);
            printf("CPU has been reset.\n");
        } else if (strncmp(command, "print ", 6) == 0) {
            uint16_t addr;
            if (sscanf(command + 6, "%hx", &addr) == 1) {
                uint8_t value = read_memory(cpu, addr);
                printf("Mem[%04X]: %02X\n", addr, value);
            } else {
                printf("\x1b[31mUsage: print <addr>\x1b[0m\n");
            }
        } else if (strncmp(command, "help", 4) == 0) {
            printf("\x1b[33mAvailable commands:\x1b[0m\n");
            printf("  run          - Execute the next instruction\n");
            printf("  regs         - Display CPU registers\n");
            printf("  exit         - Exit the emulator\n");
            printf("  set <addr> <val>  - Set a value in memory at a specific address\n");
            printf("  reset        - Reset the CPU\n");
            printf("  print <addr>   - Print the value at a memory address\n");
        } else {
            printf("\x1b[31mUnknown command.\x1b[0m\n");
        }
    }
}
