#include <stdio.h>
#include "memory.h"


int main(void) {
    // Initialize pool
    init_memory_pool();

    // Test allocate_int and free_int
    int id1 = allocate_int();
    int id2 = allocate_int();
    printf("Allocated IDs: %d, %d\n", id1, id2);

    // Test set_int_value
    // set_int_value(id1, 42);
    


    if (free_int(id1) == 0)
        printf("Freed ID: %d\n", id1);
    else
        printf("Failed to free ID: %d\n", id1);

    // Test allocate_int_ptr and free_int_ptr
    int* ptr = allocate_int_ptr();
    if (ptr) {
        *ptr = 123;
        printf("Allocated via pointer. Value: %d\n", *ptr);

        free_int_ptr(ptr);
        printf("Freed pointer allocation.\n");
    } else {
        printf("Pointer allocation failed.\n");
    }

    // Pool exhausted test
    int ids[POOL_SIZE];
    for(int i=0; i<POOL_SIZE; i++)
        ids[i] = allocate_int();

    int fail = allocate_int();
    printf("Allocation with full pool (should be 0): %d\n", fail);

    // Free all
    for(int i=0; i<POOL_SIZE; i++)
        free_int(ids[i]);

    printf("Test complete.\n");
    return 0;
}
