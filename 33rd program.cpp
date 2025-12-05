/* PROGRAM 33 : PRODUCER CONSUMER USING SEMAPHORES */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;
int buffer[5], in = 0, out = 0;

void* producer(void* arg) {
    int item = 1;
    sem_wait(&empty);
    buffer[in] = item;
    printf("Produced %d\n", item);
    in = (in + 1) % 5;
    sem_post(&full);
    return NULL;
}

void* consumer(void* arg) {
    sem_wait(&full);
    int item = buffer[out];
    printf("Consumed %d\n", item);
    out = (out + 1) % 5;
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
