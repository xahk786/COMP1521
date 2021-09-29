#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

    char *file_name = argv[1];
    
    FILE *fp = fopen(file_name, "r");

    int check = fgetc(fp);
    int count = 0;
    while (check != EOF){
        if ((check >= 128 && check <= 255) && check != '\n'){
            printf("%s: byte %d is non-ASCII\n", file_name, count);
            //printf("%c\n", check);
            return 0;
        }
        count++;
        check = fgetc(fp);
    }

    printf("%s is all ASCII\n", file_name);
    return 0;
}