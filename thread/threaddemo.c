#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *thread(void *arg)
{
    printf("thread\n");

}
int main(int argc, char const *argv[])
{
    pthread_t tid;
    printf("Before thread creation\n");
    pthread_create(&tid, NULL, thread, NULL);
    printf("After thread creation\n");
    sleep(1);
    printf("After sleep creation\n");
    
    
    return 0;
} 