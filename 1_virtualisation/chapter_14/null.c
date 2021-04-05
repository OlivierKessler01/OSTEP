#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void interrupt()
{
}

int main()
{
    signal(SIGINT, interrupt);
    int* pointer;
    pointer = NULL;
    printf("%d", *pointer);
}
