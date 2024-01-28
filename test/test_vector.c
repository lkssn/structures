#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

typedef struct dog {
    const char *name;
    int age;
} dog_t;

void dog_print(void *arg) {
    dog_t *dog = arg;
    printf("Dog: name=%s, age=%d\n", dog->name, dog->age);
}

int main(void) {
    vector_t v;
    dog_t dog;
    vector_create(&v, sizeof(dog_t));

    dog.name = "A";
    dog.age = 20;
    vector_push(&v, &dog);

    dog.name = "B";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "C";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "D";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "E";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "F";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "G";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "H";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "I";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "J";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "K";
    dog.age = 20;
    vector_push(&v, &dog);
    dog.name = "L";
    dog.age = 20;
    vector_push(&v, &dog);
    vector_each(&v, &dog_print);


    vector_pop(&v, &dog);
    dog_print(&dog);
    vector_pop(&v, &dog);
    dog_print(&dog);
    vector_pop(&v, &dog);
    dog_print(&dog);
    vector_pop(&v, &dog);
    dog_print(&dog);
    vector_pop(&v, &dog);
    dog_print(&dog);
    vector_pop(&v, &dog);
    dog_print(&dog);
    vector_pop(&v, &dog);
    dog_print(&dog);

    return 0;
}
