/* Roll No: B20CSB65
   Name: Sreekanth cs
   Name of the Experiment: Dining Philosophers Problem */

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t chopstick[5];
sem_t mutex;
char status[6] = {'-', '-', '-', '-', '-'};

void print_status()
{
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%c\t", status[i]);
    }
}

void *Philosopher(void *arg)
{
    intptr_t n = (intptr_t)arg;

    // philosopher is hungry
    status[n] = '-';
    print_status();

    // lock the critical section
    sem_wait(&mutex);

    // acquire left and right chopstick
    sem_wait(&chopstick[n]);
    sleep(1);
    sem_wait(&chopstick[(n + 1) % 5]);

    // philosopher is eating
    status[n] = 'E';
    print_status();
    sleep(1);

    // philosopher release chopsticks
    sem_post(&chopstick[(n + 1) % 5]);
    sem_post(&chopstick[n]);

    // unlock the critical section
    sem_post(&mutex);

    // philosopher is thinking
    status[n] = '-';
    print_status();

    pthread_exit(NULL);
}

int main()
{
    pthread_t philosopher[5];
    int i;

    // initialise semaphore
    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    sem_init(&mutex, 0, 1);

    // print headings
    for (i = 0; i < 5; i++)
        printf("P%d\t", i + 1);

    // create philosopher threads
    for (i = 0; i < 5; i++)
        pthread_create(&philosopher[i], NULL, Philosopher, (void *)(intptr_t)i);

    // join the threads
    for (i = 0; i < 5; i++)
        pthread_join(philosopher[i], NULL);
}
