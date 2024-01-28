#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct hash_table {
    // TODO: hash functions, struct elements, ...
    int data_size;
    uint8_t *array;
} hash_table_t;

// TODO: API
void hash_table_create(hash_table_t *hash_table, int data_size);
void hash_table_destroy(hash_table_t *hash_table);
bool hash_table_has_key(hash_table_t *hash_table, void *key);
void hash_table_set(hash_table_t *hash_table, void *key, void *data);
bool hash_table_get(hash_table_t *hash_table, void *key, void *data);

