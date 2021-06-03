#include <stdio.h>
#include <stdlib.h>

int find_min(void);

int main(int argc, char **argv) {
	//(void) argc, (void) argv; // keep the compiler quiet, should be removed

	int min = atoi(argv[1]);
	int max = atoi(argv[1]);
	int sum = 0;
	int prod = 1;
	int mean = 0;

	
	for (int i = 1; i < argc; i++)
	{
		if (atoi(argv[i]) < min)
		{
			min = atoi(argv[i]);
		}
		
		if (atoi(argv[i]) > max)
		{
			max = atoi(argv[i]);
		}

		sum = sum + atoi(argv[i]);
		prod = prod * atoi(argv[i]);
		//printf("%d %d\n", atoi(argv[i]), min);	
	}
	
	mean = sum / (argc - 1);
	printf("MIN:  %d\n", min);
	printf("MAX:  %d\n", max);
	printf("SUM:  %d\n", sum);
	printf("PROD: %d\n", prod);
	printf("MEAN: %d\n", mean);

	
	return 0;
}
