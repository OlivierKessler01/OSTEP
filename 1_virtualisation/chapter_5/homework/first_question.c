#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{
    int rc = fork();
    int x = 0;

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process : %d\n", x);
        x++;
        printf("child process, incremented : %d\n", x);
    } else {
        x = 100;
        int wc = wait(NULL);
        printf("parent process: %d\n", x);
    }
    
    return 0;
}
