#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "add.h"

// return the MIPS opcode for add $d, $s, $t
uint32_t make_add(uint32_t d, uint32_t s, uint32_t t) {

    //bit pattern = 000000ssssstttttddddd00000100000

    uint32_t op;

    op = 0;
    op = (op << 5) | s;

    op = (op << 5) | t;

    op = (op << 5) | d;

    op = (op << 11) | 32;

    return op;

    


}
