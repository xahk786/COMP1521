#include <stdio.h>
#include <stdlib.h>

#define SERIES_MAX 46


void fib(int x, int arr[]){

    int num_next;
    num_next = x +  

    
}


int main(void) {
    
    //int already_computed[SERIES_MAX + 1] = { 0, 1 };
	//(void) already_computed; // keep the compiler quiet, should be removed

    int check[SERIES_MAX + 1];

    for (int i = 0; i < SERIES_MAX + 1; i++)
    {
        check[i] = -1;
    }

    check[0] = 0;
    check[1] = 1;

    int num;

    while (scanf("%d", &num) != EOF)
    {
        if (num == 0 || num == 1)
        {
            printf("%d\n", num);
        } else {
            fib(num, check);
        }
    }
   

    return EXIT_SUCCESS;
}
