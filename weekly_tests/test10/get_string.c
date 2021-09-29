#include <stdio.h>

#include "get_string.h"

// print a line from stream using fgetc (only)
// reads  in at  most one less than size characters from stream and stores them into the
// buffer pointed to by s.  Reading stops after an EOF or a newline.  If a newline is read, it  is
// stored  into  the buffer.  A terminating null byte ('\0') is stored after the last character in the buffer.
void get_string(char *s, int size, FILE *stream) {

    // PUT YOUR CODE HERE

    int c_val = fgetc(stream);
    char ch = c_val;
    //s[0] = ch;
    //s[1] = '\0';

    int i = 0;

    while (1){
        
        if (i == (size-1)){
            s[i] = '\0';
            break;
        }
        
        if (ch == '\n'){
            s[i] = '\n';
            s[i+1] = '\0';
            break;
        }
        
        if (c_val == EOF){
            s[i] = '\0';
            break;
        }

        s[i] = ch;

        c_val = fgetc(stream);
        ch = c_val;
        i++;
    
    }

    //s[i] = '\0';
    /*
    int i = 0;

    char str[size];

    int ch = fgetc(stream);
    char val;
    while (i < size){
        val = ch + '0';

        if (val == '\n'){
            str[i] = '\n';
            break;
        }

        if (ch == EOF){
            break;
        }

        str[i] = val;

        ch = fgetc(stream);
        i++;
    
    }

    str[i] = '\0';

    s = str;
    */

}
