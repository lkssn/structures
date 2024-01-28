#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t not_empty;
pthread_cond_t not_full;
int waffles = 0;

#define N 2
#define M 2
#define W 10

void *consumer(void *arg) {
	int id = *(int*)arg;
	printf("consumer: %d\n", id);
	while (1) {
		pthread_mutex_lock(&mutex);
		while (waffles == 0) pthread_cond_wait(&not_empty, &mutex);
		waffles--;
		printf("waffles eaten by consumer %d: waffles = %d\n", id, waffles);
		pthread_mutex_unlock(&mutex);
		pthread_cond_broadcast(&not_full);
	}
	return NULL;
}

void *producer(void *arg) {
	int id = *(int*)arg;
	printf("producer: %d\n", id);
	while (1) {
                pthread_mutex_lock(&mutex);
                while (waffles == W) pthread_cond_wait(&not_full, &mutex);
                waffles++;
		waffles++;
		waffles = waffles < W ? waffles : W;
                printf("waffles baked by producer %d: waffles = %d\n", id, waffles);
                pthread_mutex_unlock(&mutex);
		pthread_cond_broadcast(&not_empty);
        }
	return NULL;
}

int main(void) {
	pthread_t producers[N];
	pthread_t consumers[M];
	int producer_ids[N];
	int consumer_ids[M];

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&not_empty, NULL);
	pthread_cond_init(&not_full, NULL);

	for (int i=0; i<N; i++) {
		producer_ids[i] = i;
		pthread_create(&producers[i], NULL, &producer, &producer_ids[i]);
	}
	for (int j=0; j<M; j++) {
		consumer_ids[j] = j;
		pthread_create(&consumers[j], NULL, &consumer, &consumer_ids[j]);
	}

	
	for (int j=0; j<M; j++) {
		pthread_join(consumers[j], NULL);
	}
	for (int i=0; i<N; i++) {
		pthread_join(producers[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&not_empty);
	pthread_cond_destroy(&not_full);

	return 0;
}
