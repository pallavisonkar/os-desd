#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
pthread_barrier_t barr;

void *serial(void *arg)
{
    printf("serial: Initialzation started\n");
    sleep(2);
    printf("serial: Initialzed completed\n");
    pthread_barrier_wait(&barr);
    printf("serial: started\n");
}
void *Ethernet(void *arg)
{
    printf("Ethernet: Initialazation started\n");
    sleep(10);
    printf("Ethernet: Initialazation completed \n");
    pthread_barrier_wait(&barr);
    printf("Ethernet: started\n");
}
void *lcd(void *arg)
{
    printf("LCD: Initialazation started\n");
    sleep(7);
    printf("LCD: Initilazation completed\n");
    pthread_barrier_wait(&barr);
    printf("LCD: started\n");
}
void *ADC(void *arg)
{
    printf("ADC: Initilazation started\n");
    sleep(4);
    printf("ADC: Initilazation completed\n");
    pthread_barrier_wait(&barr);
    printf("ADC: started\n");
}


int main(int *argc, char const *argv[])
{
    pthread_t s, E, l, A;
    pthread_barrier_init(&barr, NULL, 4);
    pthread_create(&s, NULL, serial, NULL);
    pthread_create(&E, NULL, Ethernet, NULL);
    pthread_create(&l, NULL, lcd, NULL);
    pthread_create(&A, NULL, ADC, NULL);

    pthread_join(s, NULL);
    pthread_join(E, NULL);
    pthread_join(l, NULL);
    pthread_join(A, NULL);

    pthread_barrier_destroy(&barr);
    return 0;

}




