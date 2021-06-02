#include <stdio.h>
#include <stdlib.h>

#define SERIES_MAX 46


void fib(int target, int num, int check[]){

    if (check[num-1] != -1 && check[num - 2] != -1)
    {
        int f_curr;
        f_curr = check[num-1] + check[num -2];
        check[num] = f_curr;
        
        if (num == target) 
        {
            return;    
        }
        
    } else {
        num = num - 1;
        return fib(target, num, check);
    }
    
    num = num + 1;
    
    return fib(target, num, check);

    
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
        if (check[num] != -1)
        {
            printf("%d\n", check[num]);
        } else {
            fib(num, num, check);
            printf("%d\n", check[num]);
        }
    } 
   
    //fib(num, check);
    return EXIT_SUCCESS;
}
