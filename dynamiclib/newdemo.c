#include <stdio.h>
#include "newdemo.h"

int add(int, int);
int sub(int, int);

int main(int argc, char const *argv[])
{
    printf("addition: %d\n",add(50,60));
    printf("diff: %d\n",sub(50,60));
    return 0;
}