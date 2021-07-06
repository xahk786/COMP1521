#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BCD_DIGITS 8

uint32_t packed_bcd(uint32_t packed_bcd);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= UINT32_MAX);
        uint32_t packed_bcd_value = l;

        printf("%lu\n", (unsigned long)packed_bcd(packed_bcd_value));
    }

    return 0;
}

// given a packed BCD encoded value between 0 .. 99999999
// return the corresponding integer
uint32_t packed_bcd(uint32_t packed_bcd_value) {

    // it is defined that number of blocks (each block holding 4 bits) is 8 
    //each 4 bits holds 1 decimal value
    int mask = 15; //1111
    int i = N_BCD_DIGITS;
    int val = 0;
    int final = 0;

    while (i > 0 ){
        val = packed_bcd_value >> (4 * (i-1));
        val = val & mask;
        final = (final * 10) + val;
        i = i - 1;
    }


    return final;
}
