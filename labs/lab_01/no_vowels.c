#include <stdio.h>
#include <string.h>

int not_vowel(char letter);

int main(void) {
	
	char ch;

	while ( scanf("%c", &ch) != EOF)
	{
		if (not_vowel(ch))
		{
			printf("%c", ch);	
		}
		
	}
	
	return 0;
	
}

int not_vowel(char letter){
	
	int is_true;
	if (letter != 'A' && letter != 'E' && letter != 'I' && letter != 'O' && letter != 'U' && letter != 'a' && letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u')
	{
		is_true = 1;
	} else 
	{
		is_true = 0;
	}

	return is_true;
}
