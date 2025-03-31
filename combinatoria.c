
#include "combinatoria.h"

unsigned long factorial(const unsigned int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

unsigned long binomial_coefficient(const unsigned int n, const unsigned int k) {
    if (k > n) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

unsigned long permutations(unsigned int n, unsigned int k) {
    return binomial_coefficient(n, k) * factorial(k);
}