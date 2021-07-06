#include "float_exp.h"

// given the 32 bits of a float return the exponent
uint32_t float_exp(uint32_t f) {

    uint32_t val = f;
    uint32_t mask = 255; //0b11111111
    uint32_t exponent;

    //get rid of the 23 bits at the back of the float 
    val = val >> 23;
    
    exponent = val & mask;

    return exponent;


}
