#ifndef INT_ALLOC_H
#define INT_ALLOC_H

#define POOL_SIZE 10

typedef struct {
    int data;
    int is_used;
} IntMemorySlot;

// Allocates memory for one integer (returns 1-based cell ID)
int allocate_int(void);

// Frees a cell, given its ID (returns 0 on success)
int free_int(int cell_id);

// Allocates and returns a pointer to the integer cell, or NULL
int* allocate_int_ptr(void);

// Frees the memory using its pointer
void free_int_ptr(int* ptr);

// Initializes the memory pool (call once at program start)
void init_memory_pool(void);

#endif // INT_ALLOC_H
