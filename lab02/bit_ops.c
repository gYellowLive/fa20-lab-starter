#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {

    if (x & (1<<n)){
        return 1;
    }
    else{
        return 0;
    }
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {

    
    if (v==0){
        *x = (*x) & (~(1<<n));
    }
    else{
        *x = (*x) | (1<<n);
    }
    
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    *x = (*x) ^ (1<<n);
}

