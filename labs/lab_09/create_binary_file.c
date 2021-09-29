#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    //printf("%d\n", argc);
    if (argc < 2){
        //fprintf(stderr, "Number of arguments is incorrect\n");
        perror("File name is not included");
        return 1;
    }

    char *file_name = argv[1];
    FILE *fp = fopen(file_name, "w");

    if (fp == NULL) {
        perror("File cannot be created");
        return 1;
    }

    int i = 2;
    int end = argc;

    while (i < end){
        fprintf(fp, "%c", atoi(argv[i]));
        i++;
    }

    fclose(fp);
    return 0;
}