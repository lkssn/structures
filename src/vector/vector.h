#pragma once

#include <stdint.h>

// can be used as:
// static array
// dynamic array
// stack
typedef struct vector {
    int data_size;
    int length;
    int capacity;
    uint8_t *array;
} vector_t;

void vector_create(vector_t *vector, int data_size);
void vector_destroy(vector_t *vector);
void vector_reserve(vector_t *vector, int length);
int vector_length(vector_t *vector);
void vector_set(vector_t *vector, int i, void *data_ptr);
void vector_get(vector_t *vector, int i, void *data_ptr);
void vector_push(vector_t *vector, void *data_ptr);
void vector_pop(vector_t *vector, void *data_ptr);
void vector_each(vector_t *vector, void (*f)(void*));
