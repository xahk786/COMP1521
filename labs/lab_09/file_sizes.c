#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    
    
    int i = 1;

    char *path;
    struct stat buf;

    long total = 0;
    while (i < argc){
        path = argv[i];
        stat(path, &buf);

        printf("%s: %ld bytes\n", argv[i], buf.st_size);
        total = total + buf.st_size;
        i++;
    }
    
    printf("Total: %ld bytes\n", total);
    
    return 0;
    //char *path = "/import/reed/5/z5208639/Desktop/comp1521/COMP1521/labs/lab_09/create_integers_file.c";
    /*
    char *path = "compile_if_needed.c";
    struct stat buf;

    stat(path, &buf);

    printf("%ld\n", buf.st_size);
    */

    }