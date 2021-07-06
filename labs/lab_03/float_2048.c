// Multiply a float by 2048 using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"


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

uint32_t float_2048(uint32_t f) {
    
    // float_2048 is given the bits of a float f as a uint32_t
    // it uses bit operations and + to calculate f * 2048
    // and returns the bits of this value as a uint32_t
    //
    // if the result is too large to be represented as a float +inf or -inf is returned
    //
    // if f is +0, -0, +inf or -inf, or Nan it is returned unchanged
    //
    // float_2048 assumes f is not a denormal number
    //
    // PUT YOUR CODE HERE

    float_components_t my_fl = float_bits(f);
    
    if ( (is_positive_infinity(my_fl)) || (is_negative_infinity(my_fl)) || (is_nan(my_fl)) || (is_zero(my_fl))  ){
        return f;
    }

    my_fl.exponent = my_fl.exponent + 11;

    uint32_t val = 0;
    val = (my_fl.sign << 8) | (my_fl.exponent);
    val = (val << 23) | (my_fl.fraction);
    
    if (my_fl.exponent >= 255){   
        uint32_t found = 0;
        if (my_fl.sign == 0){
            //found will be positive infinity 
            found = (my_fl.sign << 8) | 255;
            found = (found << 23) | 0;
            return found;    
        } 
        else if (my_fl.sign == 1){
            //found will be negative infinity
            found = (my_fl.sign << 8) | 255;
            found = (found << 23) | 0;
            return found; 
        }
        
    }

    return val;
}
