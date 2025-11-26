#include <stdio.h>
#include "memory.h"

typedef struct {
    int value;
    int next;   // next in allocated or available list
    int prev;   // previous in allocated list ONLY
} Cell;

static Cell memory_pool[POOL_SIZE];

static int available_head;   // head of free list
static int allocated_head;   // head of allocated list


void print_state(void) {
    printf("\n========== MEMORY STATE ==========\n");
    printf("Available Head : %d\n", available_head);
    printf("Allocated Head : %d\n\n", allocated_head);

    printf("Index | Value | Next | Prev\n");
    printf("------------------------------\n");
    for (int i = 0; i < POOL_SIZE; i++) {
        printf("%5d | %5d | %4d | %4d\n",
               i,
               memory_pool[i].value,
               memory_pool[i].next,
               memory_pool[i].prev);
    }

    printf("\nAvailable List: ");
    int f = available_head;
    while (f != -1) {
        printf("[%d] -> ", f);
        f = memory_pool[f].next;
    }
    printf("NULL\n");

    printf("Allocated List: ");
    int a = allocated_head;
    while (a != -1) {
        printf("[%d] -> ", a);
        a = memory_pool[a].next;
    }
    printf("NULL\n");
    printf("===================================\n");
}


void init_memory(void) {
    for (int i = 0; i < POOL_SIZE; i++) {
        memory_pool[i].value = 0;
        memory_pool[i].prev = -1;
        memory_pool[i].next = (i == POOL_SIZE - 1) ? -1 : i + 1;
    }
    available_head = 0;
    allocated_head = -1;

    print_state();
}


int alloc_cell(void) {
    if (available_head == -1) {
        printf("\n[ALLOC FAILED] No free memory\n");
        return -1;
    }

    int new = available_head;
    available_head = memory_pool[new].next;

    // insert at head of allocated list (O(1))
    memory_pool[new].next = allocated_head;
    memory_pool[new].prev = -1;

    if (allocated_head != -1) {
        memory_pool[allocated_head].prev = new;
    }

    allocated_head = new;

    print_state();
    return new;
}


int free_cell(int index) {
    if (index < 0 || index >= POOL_SIZE) {
        printf("\n[FREE FAILED] Invalid index %d\n", index);
        return -1;
    }

    // unlink from allocated list — O(1)
    int prev = memory_pool[index].prev;
    int next = memory_pool[index].next;

    if (prev != -1) {
        memory_pool[prev].next = next;
    } else {
        allocated_head = next;
    }

    if (next != -1) {
        memory_pool[next].prev = prev;
    }

    // insert into available list head — O(1)
    memory_pool[index].next = available_head;
    memory_pool[index].prev = -1;
    available_head = index;

    memory_pool[index].value = 0;

    print_state();
    return 0;
}