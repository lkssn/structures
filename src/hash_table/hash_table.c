#include "hash_table.h"

#include <string.h>
#include <stdlib.h>

void hash_table_create(hash_table_t *hash_table, int data_size) {
    hash_table->data_size = data_size;
    hash_table->array = malloc(1);
}

void hash_table_destroy(hash_table_t *hash_table) {
    free(hash_table->array);
}
