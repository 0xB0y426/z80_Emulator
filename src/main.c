#include "modules/cpu.h"
#include "modules/memory.h"
#include "modules/shell.h"

int main() {
    Z80 cpu;
    reset_cpu(&cpu);

    uint8_t program[] = {0x3E, 0x42, 0x06, 0x10, 0xC3, 0x02, 0x00};
    load_program(&cpu, program, sizeof(program));

    start_shell(&cpu);
    return 0;
}