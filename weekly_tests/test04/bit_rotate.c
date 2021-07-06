#include "bit_rotate.h"

// return the value bits rotated left n_rotations
uint16_t bit_rotate(int n_rotations, uint16_t bits) {
    
    //if n positive shift left, else if n negative shift right 
    
    //when shifting left, shift left as usual but if encountering a '1' bit on the front and need to shift left:
    //we can turn that front bit into 0, shift left, then make the back bit 1

    //when shifting right, shift right as usual but if encountering a '1' bit on the back:
    //can turn that back bit into 0, shift right then make front bit 1

    int i = 0;
    uint16_t val = bits;

    uint16_t mask_front = 32768; //0b1000000000000000;
    uint16_t mask_back = 1;
    //uint16_t mask_back = 65534; //0b1111111111111110

    if (n_rotations > 0){
        //shift left
        while (i < n_rotations){
            if ( val & mask_front ){
                //convert front to 0
                val = val & 32767;//0b0111111111111111
                //left shift 
                val = val << 1;
                //bring the '1' bit thats at the front, to the back
                val = val | 1;
            } else {
                val = val << 1;
            }
            i = i + 1;
        }

    } else if (n_rotations < 0){
        n_rotations = n_rotations * (-1);
        while (i < n_rotations){
            if (val & mask_back){
                //coverrt back to 0
                val = val & 65534; //0b1111111111111110
                //right shift
                val = val >> 1;
                //bring '1' bit to the front 
                val = val | mask_front;
            } else {
                val = val >> 1;
            }
            i = i + 1;
        }
    }


    return val;


}
