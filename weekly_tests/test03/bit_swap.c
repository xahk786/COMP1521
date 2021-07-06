// swap pairs of bits of a 64-bit value, using bitwise operators

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

// return value with pairs of bits swapped
uint64_t bit_swap(uint64_t value) {
    // PUT YOUR CODE HERE

    //the plan:
    //check the 2nd last and last bits of the integer using an appropriate mask ie. 0b11 
    //extract these values and then flip them around if need to swap them
    //append them to an output integer 
    //right shift the value by 2

    //on next iteration left shift the (extarcted and flipped) by 2 to make room to OR it with the output value
    //then by 4..6..8..10..12 etc.. 

    uint64_t original = value;

    uint64_t extract, construct;

    uint64_t output = 0;

    int i = 0;

    while (1) {
        if (original == 0){
            break;
        } 
        extract = original & 3; //0b11
        //extract can be 0b11, 0b00, 0b10, 0b01
        if (extract == 2){
            construct = 1; //0b10 --> 0b01
        }
        else if (extract == 1){
            construct = 2; //0b01 --> 0b10
        } else {
            construct = extract; //0b00 or 0b11 no need to swap 
        }
        construct = construct << (2*i);
        output = construct | output;
        original = original >> 2;
        i = i+1;
    }

    return output;
}
