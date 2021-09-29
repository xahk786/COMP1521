#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    char dest_path[300];
    strcpy(dest_path, getenv("HOME"));
    strcat(dest_path, "/.diary");

    FILE *fp = fopen(dest_path, "a");

    if (fp == NULL){
        fprintf(stderr, "File couldnt open\n");
    }

    for (int i = 1; i < argc; i++){
        fprintf(fp, "%s", argv[i]);
        if (i != (argc - 1)){
            fprintf(fp, " ");
        }
    }

    fprintf(fp, "\n");

    fclose(fp);

    
    return 0;

}