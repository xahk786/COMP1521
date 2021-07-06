#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

//
// Store an arbitray length Binary Coded Decimal number.
// bcd points to an array of size n_bcd
// Each array element contains 1 decimal digit.
// Digits are stored in reverse order.
//
// For example if 42 is stored then
// n_bcd == 2
// bcd[0] == 0x02
// bcd[1] == 0x04
//

typedef struct big_bcd {
    unsigned char *bcd;
    int n_bcd;
} big_bcd_t;


big_bcd_t *bcd_add(big_bcd_t *x, big_bcd_t *y);
void bcd_print(big_bcd_t *number);
void bcd_free(big_bcd_t *number);
big_bcd_t *bcd_from_string(char *string);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number> <number>\n", argv[0]);
        exit(1);
    }

    big_bcd_t *left = bcd_from_string(argv[1]);
    big_bcd_t *right = bcd_from_string(argv[2]);

    big_bcd_t *result = bcd_add(left, right);

    bcd_print(result);
    printf("\n");

    bcd_free(left);
    bcd_free(right);
    bcd_free(result);

    return 0;
}


// DO NOT CHANGE THE CODE ABOVE HERE



big_bcd_t *bcd_add(big_bcd_t *x, big_bcd_t *y) {

    // PUT YOUR CODE HERE
    char x_buffer[x->n_bcd];
    char y_buffer[y->n_bcd];

    //appending digits for x->bcd such that they appear from front to back into a string array
    int ind_x = 0;
    for (int i = (x->n_bcd) -1; i >= 0; i = i - 1) {
        x_buffer[ind_x] = x->bcd[i];
        ind_x = ind_x + 1;
    }
    
    //appending digits for y->bcd such that they appear from front to back into a string array
    int ind_y = 0;
    for (int i = (y->n_bcd) -1; i >= 0; i = i - 1) {
        y_buffer[ind_y] = y->bcd[i];
        ind_y = ind_y + 1;
    }

    //calculating the total value of left + right 
    int x_num = atoi(x_buffer);
    int y_num = atoi(y_buffer);
    int sum = x_num + y_num;

    //converting the integer into a string array
    char str[(x->n_bcd)+(y->n_bcd)];
    sprintf(str, "%d", sum);
    char *output = str;
    
    //converting the total as a string into a big_bcd_t type 
    //big_bcd_t *total = bcd_from_string("246");
    big_bcd_t *total = bcd_from_string(output);

    return total;
}

// DO NOT CHANGE THE CODE BELOW HERE


// print a big_bcd_t number
void bcd_print(big_bcd_t *number) {
    // if you get an error here your bcd_add is returning an invalid big_bcd_t
    assert(number->n_bcd > 0);
    for (int i = number->n_bcd - 1; i >= 0; i--) {
        putchar(number->bcd[i] + '0');
    }
}

// free storage for big_bcd_t number
void bcd_free(big_bcd_t *number) {
    // if you get an error here your bcd_add is returning an invalid big_bcd_t
    // or it is calling free for the numbers it is given
    free(number->bcd);
    free(number);
}

// convert a string to a big_bcd_t number
big_bcd_t *bcd_from_string(char *string) {
    big_bcd_t *number = malloc(sizeof *number);
    assert(number);

    int n_digits = strlen(string);
    assert(n_digits);
    number->n_bcd = n_digits;

    number->bcd = malloc(n_digits * sizeof number->bcd[0]);
    assert(number->bcd);

    for (int i = 0; i < n_digits; i++) {
        int digit = string[n_digits - i - 1];
        assert(isdigit(digit));
        number->bcd[i] = digit - '0';
    }

    return number;
}