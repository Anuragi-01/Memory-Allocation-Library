#ifndef MEMORY_H
#define MEMORY_H

#define POOL_SIZE 10

void init_memory(void);
int alloc_cell(void);
int free_cell(int index);

// void print_available_list(void);
// void print_allocated_list(void);

void print_state(void);
#endif
