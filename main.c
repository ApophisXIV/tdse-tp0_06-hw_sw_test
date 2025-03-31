/**
 * @file main.c
 * @author Karla Duque (kduque@fi.uba.ar)
 * @author Guido Rodriguez (guerodriguez@fi.uba.ar)
 * @brief Repaso de programacion en C
 * @version 0.1
 * @date 2025-03-24
 *
 * @copyright Copyright (c) 2025. All rights reserved.
 *
 * Licensed under the MIT License, see LICENSE for details.
 * SPDX-License-Identifier: MIT
 *
 */

#include <stdint.h>
#include <stdio.h>

#define EJ_N 12

#if EJ_N == 1

#include <stdbool.h>

typedef struct {
    float l1, l2, l3;
} triangle_t;

bool is_isosceles(triangle_t *triangle) {
    return triangle->l1 == triangle->l2 ||
           triangle->l1 == triangle->l3 ||
           triangle->l2 == triangle->l3;
}

bool is_equilateral(triangle_t *triangle) {
    return triangle->l1 == triangle->l2 &&
           triangle->l1 == triangle->l3 &&
           triangle->l2 == triangle->l3;
}

bool is_scalene(triangle_t *triangle) {
    return !is_equilateral(triangle);
}

typedef enum {
    SCALENE,
    EQUILATERAL,
    ISOCELES,
    OTHER,
} triangle_name_t;

triangle_name_t get_triangle_classification(triangle_t *triangle) {
    if (is_scalene(triangle)) return SCALENE;
    if (is_equilateral(triangle)) return EQUILATERAL;
    if (is_isosceles(triangle)) return ISOCELES;
    return OTHER;
}

int main() {
    triangle_t triangle_arr[3] = {
        {.l1 = 1, .l2 = 2, .l3 = 3},
        {.l1 = 1, .l2 = 1, .l3 = 3},
        {.l1 = 1, .l2 = 1, .l3 = 1},
    };

    const char *lut_triangle_to_string[] = {
        [SCALENE]     = "Escaleno",
        [EQUILATERAL] = "Equilatero",
        [ISOCELES]    = "Isoceles",
        [OTHER]       = "No clasificable",
    };

    for (int i = 0; i < sizeof(triangle_arr) / sizeof(triangle_t); i++) {
        printf(
            "El tringualo %d es %s\n", i,
            lut_triangle_to_string[get_triangle_classification(&triangle_arr[i])]);
    }

    return 0;
}

#elif EJ_N == 2

#define N_MAX 10

int main() {

    unsigned int n_multiples = 0;
    unsigned long i          = 0;

    while (n_multiples < N_MAX) {
        if (!(i % 3)) {
            printf("%ld es multiplo de 3\n", i);
            n_multiples++;
        }
        i++;
    }

    return 0;
}

#elif EJ_N == 3

unsigned int get_n_bits_set(int number) {
    unsigned int set_bits_count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
        if ((number >> i) & 0x1) set_bits_count++;
    return set_bits_count;
}

int main() {

    // int n1 = 0b1110111010;    // 7 ones
    int n1 = 954;    // 7 ones
    int n2 = 0;      // 0 ones

    printf("n1 tiene %u bits en estado alto\n", get_n_bits_set(n1));
    printf("n2 tiene %u bits en estado alto\n", get_n_bits_set(n2));

    return 0;
}

#elif EJ_N == 4

void print_byte(uint8_t byte) {
    // uint8_t nos asegura que son 8 bits
    // independiente de la plataforma por lo
    // que estoy habilitado a simplemente
    // recorrer hasta 8 en vez de medir
    // el tamaño correspondiente
    printf("[ ");
    for (uint8_t i = 0; i < 8; i++)
        printf("%d ", (byte >> (7 - i)) & 1);

    printf("]\n");
}

int main() {

    print_byte(16);
    print_byte(8);
    print_byte(23);
    print_byte(255);

    return 0;
}

#elif EJ_N == 5

void set_n_bit(int *number, uint8_t n_bit) {
    *number |= 1 << n_bit;
}

int main() {

    int n = 0;

    set_n_bit(&n, 0);
    set_n_bit(&n, 1);
    set_n_bit(&n, 2);
    set_n_bit(&n, 3);

    // Se espera 15

    printf("%d\n", n);

    return 0;
}

#elif EJ_N == 6

void clear_n_bit(int *number, uint8_t n_bit) {
    *number &= ~(1 << n_bit);
}

int main() {

    int n = 256 + 15;    // 1 0000 1111

    clear_n_bit(&n, 0);
    clear_n_bit(&n, 1);
    clear_n_bit(&n, 2);
    clear_n_bit(&n, 3);

    // Se espera 256

    printf("%d\n", n);

    return 0;
}

#elif EJ_N == 7

#include "funciones.h"

int main() {

    int number = 0;

    set_n_bit(&number, 4);
    set_n_bit(&number, 5);
    set_n_bit(&number, 0);

    print_byte((uint8_t)number);    //[0011 0001]

    clear_n_bit(&number, 4);

    print_byte((uint8_t)number);    //[0010 0001]

    return 0;
}

#elif EJ_N == 8

#include <stdbool.h>

typedef void (*callback_fn)(int *);

/**
 * @brief  Linear find function
 * @note   O(n) complexity. Return on first ocurrency
 * @param  *vect: Vector to find
 * @param  n_elements: Size of vector
 * @param  value: Value to find
 * @param  callback: Callback function
 * @retval True if it is find, False otherwise
 */
bool find_int(int *vect, const int n_elements, const int value, callback_fn callback) {

    if (vect == NULL) return false;

    for (unsigned int i = 0; i < n_elements; i++) {
        if (vect[i] == value) {
            callback(vect + i);
            return true;
        }
    }

    return false;
}

void divide_by_two(int *n) {
    *n /= 2;
}

void print_array(const int *arr, unsigned int n_elements) {
    printf("[ ");
    for (int i = 0; i < n_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {

    int arr[] = {1, 24, 52435, 21, 2, 34, 41};

    const unsigned int n_elements = sizeof(arr) / sizeof(int);

    printf("Array antes\n");
    print_array(arr, n_elements);

    bool has_finded = find_int(arr, n_elements, 21, &divide_by_two);

    printf("%s encontro  en el array\n", has_finded ? "Se" : "No se");
    print_array(arr, n_elements);

    return 0;
}

#elif EJ_N == 9

unsigned long factorial(const unsigned int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

unsigned long binomial_coefficient(const unsigned int n, const unsigned int k) {
    if (k > n) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {

    printf("(6,2) = %lu combinaciones distintas\n", binomial_coefficient(6, 2));
    printf("(6,9) = %lu combinaciones distintas\n", binomial_coefficient(6, 9));

    return 0;
}

#elif EJ_N == 10 || EJ_N == 11

#include "combinatoria.h"

int main() {
    printf("5! = %lu\n", factorial(5));
    printf("3! = %lu\n", factorial(3));
    printf("5C3 = %lu\n", binomial_coefficient(5, 3));
    printf("5P3 = %lu\n", permutations(5, 3));
    return 0;
}

#elif EJ_N == 12

#include "queue.h"

void print_int(void *n) {
    char *cn = (char *)n;
    printf("n: %s\n", cn);
}

int main() {

    queue_t *q = get_queue_instance();

    enqueue(q, "a");
    enqueue(q, "b");
    enqueue(q, "c");

    dequeue(q, NULL);

    enqueue(q, "d");
    enqueue(q, "e");
    enqueue(q, "f");

    print(q, print_int);

    dequeue(q, NULL);
    dequeue(q, NULL);
    dequeue(q, NULL);
    dequeue(q, NULL);
    dequeue(q, NULL);

    return 0;
}

#elif EJ_N == 13
#endif