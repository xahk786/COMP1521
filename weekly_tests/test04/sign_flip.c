#include "sign_flip.h"

// given the 32 bits of a float return it with its sign flipped
uint32_t sign_flip(uint32_t f) {
    uint32_t val = f;

    //need to extract frac, exponent and sign, then build the float again 

    uint32_t mask_exp, mask_frac, mask_sign;
    uint32_t frac, exp, sign;

    mask_frac = 8388607; //0b11111111111111111111111
    mask_exp = 255; //0b11111111
    mask_sign = 1; //0b1

    frac = val & mask_frac;
    val = val >> 23;

    exp = val & mask_exp;
    val = val >> 8;

    if ((val & mask_sign) == 1){
        sign = 0;
    } else {
        sign = 1;
    }


    //now build the float 
    uint32_t build;

    build = sign << 8;

    build = build | exp;

    build = build << 23;

    build = build | frac;

    return build;

}
