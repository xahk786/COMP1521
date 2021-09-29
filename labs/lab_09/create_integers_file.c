#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    //printf("%d\n", argc);
    if (argc != 4){
        //fprintf(stderr, "Number of arguments is incorrect\n");
        perror("Number of arguments is incorrect\n");
        return 1;
    }


    int low = atoi(argv[2]);
    int high = atoi(argv[3]);
    char *file_name = argv[1];
    FILE *output_stream = fopen(file_name, "w");
    
    if (output_stream == NULL) {
        perror("File cannot be created");
        return 1;
    }

    while (low <= high){
        fprintf(output_stream, "%d\n", low);
        low++;
    }

    fclose(output_stream);
    return 0;
}