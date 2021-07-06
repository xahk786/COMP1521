// Compare 2 floats using bit operations only

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

int is_zero(float_components_t f) {
    
    int is_zero = 0;

    if (f.fraction == 0 && f.exponent == 0){
        is_zero = 1;
    }

    return is_zero;
}

int is_nan(float_components_t f) {
    // PUT YOUR CODE HERE

    int is_nan = 0;

    if (f.exponent == 255 && f.fraction >= 1){
        is_nan = 1;

    }

    return is_nan;
}

// float_less is given the bits of 2 floats bits1, bits2 as a uint32_t
// and returns 1 if bits1 < bits2, 0 otherwise
// 0 is return if bits1 or bits2 is Nan
// only bit operations and integer comparisons are used
uint32_t float_less(uint32_t bits1, uint32_t bits2) {
    // PUT YOUR CODE HERE
    float_components_t fl_1 = float_bits(bits1);
    float_components_t fl_2 = float_bits(bits2);

    //printf("bits are %d %d\n",bits1, bits2);
    //we shall use this to store the binary represenation for integer comparisons (magnitude) 
    uint32_t first, second;
    uint32_t mask_omit = 2147483647; // 0b111111.......(n = 31)
    
    //edge case #1 IMPORTANT 
    //a) both arguments are 0 --> return 0
    if (is_zero(fl_1) && is_zero(fl_2)){
        return 0;
    }
    //b) either arguments are nan
    if (is_nan(fl_2) || is_nan(fl_1)){
        return 0;
    }
    
    //case #2 
    // a) first argument is 0, second argument has sign positive and is not zero --> return 1 
    if (is_zero(fl_1) && ( fl_2.sign == 0 && !is_zero(fl_2) ) ){
        return 1;
    }
    // b) first argument is negative and not zero, second aregument is 0 --> return 1 
    if ( ( fl_1.sign == 1 && !is_zero(fl_1) ) && (is_zero(fl_2) ) ){
        return 1;
    }
    
    //case #3 first argument is negative and second argument is positive --> return 1 
    if ((fl_1.sign == 1 && fl_2.sign == 0)){
        return 1;
    } 

    //case #4 both arguments are positive --> check if first < second --> return 1 
    if (fl_1.sign == 0 && fl_2.sign == 0){
        first = bits1 & mask_omit;
        second = bits2 & mask_omit;
        if (first < second){
            return 1;
        }
    } 

    //case #5 both arguments are negative , ommit the first bit and check if new first arg is greater than new 2nd arg  -->return 1
    if (fl_1.sign == 1 && fl_2.sign == 1){
        first = bits1 & mask_omit;
        second = bits2 & mask_omit;
        if (first > second) {
            return 1;
        }
    }

    return 0;


    
}
