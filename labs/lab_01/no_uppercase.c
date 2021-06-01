#include <stdio.h>
#include <ctype.h>

int main(void) {

	char ch;

	while ( ch = getchar() )
	{
		
		if (ch == EOF)
		{
			break;
		}

		if (ch <= 'Z' && ch >= 'A')
		{
			char answ;
			answ = ch + 32;

			putchar(answ);
		} else
		{
			putchar(ch);
		}

		
	
	}


}
