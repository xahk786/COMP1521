#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]){

    char *check = getenv(argv[1]);

    if (check == NULL || check[0] == '\0' || *check == '\0'){
        printf("%d\n", 0);
    } else {
        printf("%d\n", 1);
    }

    /*
    printf("%s\n", check);

    printf("%c\n", check[0]);

    if (check[0] == '\0'){
        printf("TRUE\n");
    }
    */

    return 0;
}
