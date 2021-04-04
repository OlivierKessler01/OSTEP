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
        int size_in_bytes;
        sscanf(argv[1], "%d", &size_in_bytes);
        char* arr = malloc(size_in_bytes * sizeof(char));
        signal(SIGINT, interrupt);

        while(keep_running) {
            for(int i = 1; i < size_in_bytes; i++){
                arr[i] = 't';
            }
        }
    } else {
        printf("The program need one argument, the array size in bytes.\n");
    }

    return 0;
}
