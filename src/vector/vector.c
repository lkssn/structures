#include "vector.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void vector_create(vector_t *vector, int data_size) {
    vector->data_size = data_size;
    vector->length = 0;
    vector->capacity = 0;
    vector->array = NULL;
}

void vector_destroy(vector_t *vector) {
    free(vector->array);
}

// check if we should change the capacity for our array
// if so: change the capacity and decrease/increase memory allocation
void vector_reserve(vector_t *vector, int length) {
    vector->length = length;

    // do not resize if length is in range [floor(cap/2), cap]
    if (length >= (vector->capacity / 2) && length <= vector->capacity)
        return;

    // take the next highest power of 2 which suffices
    vector->capacity = 1;
    while (vector->capacity < length) {
        vector->capacity = vector->capacity << 1;
    }

    vector->array = reallocarray(vector->array, vector->capacity, vector->data_size);
}

int vector_length(vector_t *vector) {
    return vector->length;
}

void vector_set(vector_t *vector, int i, void *data_ptr) {
    if (i >= vector->length)
        return;

    memcpy(&vector->array[i * vector->data_size], data_ptr, vector->data_size);
}

void vector_get(vector_t *vector, int i, void *data_ptr) {
    if (i >= vector->length)
        return;

    memcpy(data_ptr, &vector->array[i * vector->data_size], vector->data_size);
}

void vector_push(vector_t *vector, void *data_ptr) {
    vector_reserve(vector, vector->length + 1);
    vector_set(vector, vector->length - 1, data_ptr);
}

void vector_pop(vector_t *vector, void *data_ptr) {
    vector_get(vector, vector->length - 1, data_ptr);
    vector_reserve(vector, vector->length - 1);
}

void vector_each(vector_t *vector, void (*f)(void*)) {
    for (int i = 0; i < vector->length; i++) {
        (*f)(&vector->array[i * vector->data_size]);
    }
}
