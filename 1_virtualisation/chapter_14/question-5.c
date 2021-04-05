#include <stdio.h>
#include <stdlib.h>


int main()
{
    int* array = malloc(100 * sizeof(int));
    array = 0;
    free(array);
}
