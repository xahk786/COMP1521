#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]){

    int check_cd = chdir(argv[1]);

    if (check_cd == 0){
        printf("%d\n", 1);
    } else {
        printf("%d\n", 0);
    }
    return 0;
}