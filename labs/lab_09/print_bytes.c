#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    int c, i;
    i = 0;
    c = fgetc(fp);

    while (c != EOF){
        printf("byte %4d: %3d 0x%02x", i,c,c);
        if (isprint(c)){
            printf(" '%c'", c);
        }
        printf("\n");
        c = fgetc(fp);
        i++;
    }

    fclose(fp);

    return 0;

}