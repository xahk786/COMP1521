// Swap bytes of a short

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// given uint16_t value return the value with its bytes swapped
uint16_t short_swap(uint16_t value) {
    // PUT YOUR CODE HERE

    //the plan:
    //1 byte = 8 bits
    //extract the first 8 bits, and next 8 bits and store in a variable var1 and var2 respectively
    //then append var 2 to var 1 --> output = var2 append var1 

    uint16_t original = value;

    uint16_t var_1 = original >> 8;

    uint16_t var_2 = original & 255;//0b11111111

    uint16_t output = (var_2 << 8) | (var_1);

    return output;
}
