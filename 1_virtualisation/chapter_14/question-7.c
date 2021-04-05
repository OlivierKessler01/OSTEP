#include <stdio.h>
#include <stdlib.h>


int main()
{
    int* array = calloc(100, sizeof(int));
    free(&array[10]);

    printf("%d", array[10]);
}
