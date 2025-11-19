#include "memory.h"

static IntMemorySlot memory_pool[POOL_SIZE];

void init_memory_pool(void) {
    for (int i = 0; i < POOL_SIZE; i++) {
        memory_pool[i].is_used = 0;
        memory_pool[i].data = 0;
    }
}

int allocate_int(void) {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (!memory_pool[i].is_used) {
            memory_pool[i].is_used = 1;
            return i + 1;
        }
    }
    return 0;
}

int free_int(int cell_id) {
    int i = cell_id - 1;
    if (i >= 0 && i < POOL_SIZE && memory_pool[i].is_used) {
        memory_pool[i].is_used = 0;
        memory_pool[i].data = 0;
        return 0;
    }
    return -1;
}

int* allocate_int_ptr(void) {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (!memory_pool[i].is_used) {
            memory_pool[i].is_used = 1;
            return &memory_pool[i].data;
        }
    }
    return 0;
}

void free_int_ptr(int* ptr) {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (ptr == &memory_pool[i].data) {
            memory_pool[i].is_used = 0;
            memory_pool[i].data = 0;
            return;
        }
    }
}
