#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static volatile int keep_running = 1;

void interrupt() {
    keep_running = 0;
}

int main(int argc, char* argv[])
{
    if(argc == 2) {
        int size_in_bytes = atoi(argv[1]);
        signal(SIGINT, interrupt);
        char arr[size_in_bytes];

        while(keep_running) {
            for(int i = 0; i < size_in_bytes; i++){
                arr[i] = 'a';
                printf("%s", arr[i]);
            }
        }
    } else {
        printf("The program need one argument, the array size in bytes.\n");
    }
}
