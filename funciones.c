#include "funciones.h"
#include <stdio.h>

void clear_n_bit(int *number, uint8_t n_bit) {
    *number &= ~(1 << n_bit);
}

void set_n_bit(int *number, uint8_t n_bit) {
    *number |= 1 << n_bit;
}

void print_byte(uint8_t byte) {
    printf("[ ");
    for (uint8_t i = 0; i < 8; i++)
        printf("%d ", (byte >> (7 - i)) & 1);

    printf("]\n");
}
