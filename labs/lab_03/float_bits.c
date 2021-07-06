// Extract the 3 parts of a float using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

// separate out the 3 components of a float
float_components_t float_bits(uint32_t f) {
    // PUT YOUR CODE HERE

    // we are given a 32 bit float f in the ieee 754 representation
    uint32_t val = f;
    uint32_t mask_fraction = 8388607; //0b11111111111111111111111
    uint32_t mask_exponent = 255; //0b11111111
    uint32_t mask_sign = 1; //0b1
    
    float_components_t my_float;

    my_float.fraction = (val & mask_fraction);

    val = val >> 23;

    my_float.exponent = (val & mask_exponent);

    val = val >> 8;

    my_float.sign = (val & mask_sign);

    return my_float;

}

// given the 3 components of a float
// return 1 if it is NaN, 0 otherwise
int is_nan(float_components_t f) {
    // PUT YOUR CODE HERE

    int is_nan = 0;

    if (f.exponent == 255 && f.fraction >= 1){
        is_nan = 1;

    }

    return is_nan;
}

// given the 3 components of a float
// return 1 if it is inf, 0 otherwise
int is_positive_infinity(float_components_t f) {
    // PUT YOUR CODE HERE

    int is_pos_inf = 0;

    if (f.sign == 0 && f.exponent == 255 && f.fraction == 0){
        is_pos_inf = 1;
    }

    return is_pos_inf;
}

// given the 3 components of a float
// return 1 if it is -inf, 0 otherwise
int is_negative_infinity(float_components_t f) {
    // PUT YOUR CODE HERE
    int is_pos_inf = 0;

    if (f.sign == 1 && f.exponent == 255 && f.fraction == 0){
        is_pos_inf = 1;
    }

    return is_pos_inf;
}

// given the 3 components of a float
// return 1 if it is 0 or -0, 0 otherwise
int is_zero(float_components_t f) {
    
    int is_zero = 0;

    if (f.fraction == 0 && f.exponent == 0){
        is_zero = 1;
    }

    return is_zero;
}
