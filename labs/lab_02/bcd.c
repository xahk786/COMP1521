#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int bcd(int bcd_value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= 0x0909);
        int bcd_value = l;

        printf("%d\n", bcd(bcd_value));
    }

    return 0;
}

// given a  BCD encoded value between 0 .. 99
// return corresponding integer
int bcd(int bcd_value) {

    // PUT YOUR CODE HERE
    int mask = 15;
    int right = 0;
    int left = 0;
    
    //we can use 15 as mask to extract digits as it has binary 1111 
    
    right = bcd_value & mask; 

    // since we are only after 2 digit BCD values, we can shift the binary string 8 spots to the right
    // then can extract that value using the mask of 1111  
    left = (bcd_value >> 8) & 15; 

    //combining the two digits to form a a 2-digit value / 2-character string 

    int output = (left * 10) + right;

    return output;



     


    

    return 0;
}

