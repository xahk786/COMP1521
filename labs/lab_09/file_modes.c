#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int i = 1;
    char *path;
    struct stat buf;

    while (i < argc){
        path = argv[i];
        stat(path, &buf);

        //The first character on each line should be '-' for ordinary files and 'd' for directories.
        if (buf.st_mode & S_IFREG){
            printf("-");
        } else {
            printf("d");
        }
        //Permision struct members, if bitwise true print permission letter granted, else print '-' 
        //r = read 
        //w = write
        //x = execute
        printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
        printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
        printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
        printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
        printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
        printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
        printf( (buf.st_mode & S_IROTH) ? "r" : "-");
        printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
        printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
        
        printf(" %s", argv[i]);
        printf("\n");
        i++;
    }
    
    return 0;

}