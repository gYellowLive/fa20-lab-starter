#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"
#include "bit_ops.h"


// uint16_t get_bit(uint16_t x,
//                  uint16_t n) {

//     if (x & (1<<n)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// // Set the nth bit of the value of x to v.
// // Assume 0 <= n <= 31, and v is 0 or 1
// void set_bit(uint16_t * x,
//              uint16_t n,
//              uint16_t v) {

    
//     if (v==0){
//         *x = (*x) & (~(1<<n));
//     }
//     else{
//         *x = (*x) | (1<<n);
//     }
    
// }
// // Flip the nth bit of the value of x.
// // Assume 0 <= n <= 31
// void flip_bit(uint16_t * x,
//               uint16_t n) {
//     *x = (*x) ^ (1<<n);
// }


void lfsr_calculate(uint16_t *reg) {
    unsigned temp_content = (unsigned) *reg;
    unsigned bit0 = get_bit(temp_content, 0);
    unsigned bit2 = get_bit(temp_content, 2);
    unsigned bit3 = get_bit(temp_content, 3);
    unsigned bit5 = get_bit(temp_content, 5);
    unsigned bit_to_shift_in = ((bit0^bit2)^bit3)^bit5;

    temp_content = (temp_content)>>1;
    set_bit(&temp_content, 15, bit_to_shift_in);

    *reg = (uint16_t) (temp_content);

}

