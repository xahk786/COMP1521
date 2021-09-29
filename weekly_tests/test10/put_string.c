#include <stdio.h>

#include "put_string.h"

// print s to stdout with a new line appended using fputc (only)

void put_string(char *s) {

   
   int i = 0;
   int ch;
   while (1){
      ch = (int)s[i];
      if (s[i] == '\0'){
         fputc(10, stdout);
         break;
      }
      fputc(ch, stdout);
      i++;
   }

   

}
