#include <stdio.h>
#include "memory.h"

int main(void) {
    init_memory();
    print_state();
    int a = alloc_cell();
    int b = alloc_cell();
    int c = alloc_cell();

    free_cell(b);
    free_cell(a);

    int d = alloc_cell();

    return 0;
}