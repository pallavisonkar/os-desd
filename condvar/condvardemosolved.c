#include <stdio.h>
#include <pthread.h>

int flag = 0;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv1;


void *thread_1(void *data)
{
    printf("T1: Grabbing mutex");
    pthread_mutex_lock(&m1);
    printf("T1: Before BL\n");
    while (flag != 1)
    {
        printf("T1: Entering conditional wait\n");
        pthread_cond_wait(&cv1, &m1);
        printf("T1:Exit conditional wait\n");

    }
          
     printf("T1: After BL\n");
    pthread_mutex_unlock(&m1);
    printf("T1: Relesing mutex\n");

}

void *thread_2(void *data)
{
    printf("T2: Grabbing mutex\n");
    printf("T2: Before setting flag\n");
    pthread_mutex_lock(&m1);
    flag = 1;
    printf("T2: After setting flag\n");
    pthread_mutex_unlock(&m1);
    printf("T2: Relesing mutex\n");
    pthread_cond_signal(&cv1);
    printf("T2: signalling cv\n");
     

}
int main(int *argc, char const *argv[])
{
    pthread_t t1, t2;
    pthread_mutex_init(&m1, NULL);
    pthread_cond_init(&cv1, NULL);
    pthread_create(&t1, NULL, thread_1, NULL);
    pthread_create(&t2, NULL, thread_2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&m1);
    pthread_cond_destroy(&cv1);
    return 0;
}

