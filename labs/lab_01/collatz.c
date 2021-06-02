#include <stdio.h>
#include <stdlib.h>

void compress (int x){
	
	//exit condition
	if (x == 1)
	{
		
		return;
	}

	if (x % 2 == 0)
	{
		x = x / 2;
	} else if (x % 2 == 1)
	{
		x = (3 * x) + 1;
	}

	printf("%d\n", x);
	return compress(x); 

}

int main(int argc, char **argv)
{
	//(void) argc, (void) argv; // keep the compiler quiet, should be removed

	int x;
	if (argc == 1)
	{
		printf("Usage: ./collatz NUMBER\n");
	} else {
		x = atoi(argv[1]);
		printf("%d\n", x);
	}
	
	
	compress(x);
	
	return EXIT_SUCCESS;
}
