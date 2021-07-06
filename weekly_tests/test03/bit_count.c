// count bits in a uint64_t

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

// return how many 1 bits value contains
int bit_count(uint64_t value) {
    // PUT YOUR CODE HERE

    uint64_t val = value;

    uint64_t mask = 1; //0b01
    int count = 0;
    int check;

    while (val != 0 ){
        check = val & mask;
        if (check == 1){
            count = count + 1;
        }
        val = val >> 1;
    }
    return count;
}
