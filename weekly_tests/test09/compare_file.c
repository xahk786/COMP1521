#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

    char *file_name_1 = argv[1];
    char *file_name_2 = argv[2];
    
    FILE *f1 = fopen(file_name_1, "r");
    FILE *f2 = fopen(file_name_2, "r");

    int check_1 = fgetc(f1);
    int check_2 = fgetc(f2);
    int count = 0;

    while (1){
        
        if (check_1 == EOF && check_2 == EOF){
            break;
        }

        if (check_1 == EOF && check_2 != EOF){
            printf("EOF on %s\n", file_name_1);
            return 0;
        }
        
        if (check_1 != EOF && check_2 == EOF){
            printf("EOF on %s\n", file_name_2);
            return 0;
        }

        if (check_1 != check_2){
            printf("Files differ at byte %d\n", count);
            return 0;
        }
        count++;
        check_1 = fgetc(f1);
        check_2 = fgetc(f2);
    }

    printf("Files are identical\n");
    return 0;
}