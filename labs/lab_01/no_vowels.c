#include <stdio.h>
#include <string.h>

int main(void) {
	
	char string[100];

	//scanf("%[^\n]", string)
	
	while ( scanf("%s", string) != EOF )
	{
		printf("%s\n", string);
	}
	
	return 0;
	
}
