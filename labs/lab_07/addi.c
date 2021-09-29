// generate the opcode for an addi instruction

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "addi.h"

// return the MIPS opcode for addi $t,$s, i
uint32_t addi(int t, int s, int i) {

    //build OP code for the instruction 
    //OPCODE = 6 bits (8 in binary) + 5 bits (s in binary) + 5 bits (t in binary) + 16bits (i in binary) 
    //001000ssssstttttIIIIIIIIIIIIIIII
    uint32_t op;

    /*
    uint32_t first = 8; //6 bits
    uint32_t second = s; //5 bits 
    uint32_t third = t; //5 bits 
    uint32_t fourth = i; //16 bits 

    op = first << 5;
    op = op | 31; //0b11111
    op = op & second;
    op = op << 5;
    op = op | 31; //0b11111
    op = op & third;
    op = op << 16;
    op = op | 65535;//0b1111111111111111
    op = op & fourth;
    */
    
    uint16_t imm = i;

    op = 8; //0b1000
    
    op = op << 5;
    op = op | s;
    
    op = op << 5;
    op = op | t;

    op = op << 16;
    op = op | imm;


    return op;


    


    

}
