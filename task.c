
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int i = 0;

void *task2(void *arg)
{
    sleep(1);
    printf("2\n");
    return (NULL);
}

void *task1(void *arg)
{
    pthread_t tid;
    pthread_create(&tid, NULL, task2, NULL);
    pthread_join(tid, NULL);
    sleep(1);
    printf("1\n");
    return (NULL);
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, task1, NULL);
    pthread_join(tid, NULL);
    printf("0\n");
    return (0);
}
