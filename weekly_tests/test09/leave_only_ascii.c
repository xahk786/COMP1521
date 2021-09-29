#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

    char *file_name = argv[1];
    
    FILE *fp = fopen(file_name, "r");
    FILE *f_temp = fopen("temp.txt", "w");

    int check = fgetc(fp);

    while (check != EOF){
        if (check < 128 || check > 255){
            fprintf(f_temp, "%c", check);
            //remove byte check from the file 
        }
        check = fgetc(fp);
    }
    fclose(fp);
    fclose(f_temp);

    fp = fopen(file_name, "w");
    f_temp = fopen("temp.txt", "r");

    int ch = fgetc(f_temp);

    while (ch != EOF){
        fprintf(fp, "%c", ch);
        ch = fgetc(f_temp);
    }

    return 0;
}