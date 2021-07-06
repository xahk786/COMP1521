// Convert a 16-bit signed integer to a string of binary digits

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BITS 16

char *sixteen_out(int16_t value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= INT16_MIN && l <= INT16_MAX);
        int16_t value = l;

        char *bits = sixteen_out(value);
        printf("%s\n", bits);

        free(bits);
    }

    return 0;
}

// given a signed 16 bit integer
// return a null-terminated string of 16 binary digits ('1' and '0')
// storage for string is allocated using malloc
char *sixteen_out(int16_t value) {

    // PUT YOUR CODE HERE
    int max_index = N_BITS - 1;
    char *output = malloc((N_BITS + 1) *sizeof(char));
    
    output[N_BITS] = '\0';
    
    int i = max_index;
    
    int mask = 0;

    while ( i >= 0){
        mask = value >> i;
        if (mask & 1){
            //printf("1");
            output[max_index - i] = '1';
        } else {
            //printf("0");
            output[max_index - i] = '0';        
        }
        i = i - 1;
    }


    return output;
}

