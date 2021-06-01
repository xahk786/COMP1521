#include <stdio.h>
#include <ctype.h>

int main(void) {

	char ch;

	while ( ch = getchar() != EOF )
	{

		if (ch > 'A' && ch < 'Z')
		{
			char answ = ch + 32;

			putchar(answ);
		} else 
		{
			putchar(ch);
		}

	
	}

	char answ = 'a' - 32;

	printf("%c,", answ);
		
	return 0;
}

int convert(char letter)
{
	if (letter > 'A' && letter < 'Z') 
	{
		char answ = letter + 32;

		return answ
	}

	

}