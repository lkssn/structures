#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct circle_buffer {
    int data_size;
    int capacity;
    uint8_t *array;
    int read;
    int write;
} circle_buffer_t;

void circle_buffer_create(circle_buffer_t *buffer, int data_size, int capacity);
void circle_buffer_destroy(circle_buffer_t *buffer);
bool circle_buffer_empty(circle_buffer_t *buffer);
bool circle_buffer_full(circle_buffer_t *buffer);
bool circle_buffer_enqueue(circle_buffer_t *buffer, void *data_ptr);
bool circle_buffer_dequeue(circle_buffer_t *buffer, void *data_ptr);
