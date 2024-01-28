#include "circle_buffer.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void circle_buffer_create(circle_buffer_t *buffer, int data_size, int capacity) {
    buffer->data_size = data_size;
    buffer->capacity = capacity;
    buffer->array = calloc(capacity, data_size);
    buffer->read = -1;
    buffer->write = 0;
}

void circle_buffer_destroy(circle_buffer_t *buffer) {
    free(buffer->array);
}

bool circle_buffer_empty(circle_buffer_t *buffer) {
    return buffer->read < 0;
}

bool circle_buffer_full(circle_buffer_t *buffer) {
    return buffer->write < 0;
}

bool circle_buffer_enqueue(circle_buffer_t *buffer, void *data_ptr) {
    if (circle_buffer_full(buffer))
        return false;

    memcpy(&buffer->array[buffer->write * buffer->data_size], data_ptr, buffer->data_size);
    if (buffer->read < 0)
        buffer->read = buffer->write;

    buffer->write = (buffer->write + 1) % buffer->capacity;
    if (buffer->write == buffer->read)
        buffer->write = -1;

    return true;
}

bool circle_buffer_dequeue(circle_buffer_t *buffer, void *data_ptr) {
    if (circle_buffer_empty(buffer))
        return false;

    memcpy(data_ptr, &buffer->array[buffer->read * buffer->data_size], buffer->data_size);
    if (buffer->write < 0)
        buffer->write = buffer->read;

    buffer->read = (buffer->read + 1) % buffer->capacity;
    if (buffer->read == buffer->write)
        buffer->read = -1;

    return true;
}