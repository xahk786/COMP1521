// Convert string of binary digits to 16-bit signed integer

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define N_BITS 16

int16_t sixteen_in(char *bits);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        printf("%d\n", sixteen_in(argv[arg]));
    }

    return 0;
}

//
// given a string of binary digits ('1' and '0')
// return the corresponding signed 16 bit integer
//
int16_t sixteen_in(char *bits) {
    
    //16 character binary string conversion to decimal (signed)
    int mask = 0;
    int16_t val = 0;

    int i = 0;

    while ( i < 16) { 
        if (bits[i] == '1') {
            mask = 1 << ((16 - 1) - i);
            val = val | mask;
        }
        i = i + 1;
    }
    
    return val;

} 

