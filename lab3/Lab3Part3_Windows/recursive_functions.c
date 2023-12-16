/* SYSC 2006 Lab 3, part 3. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "recursive_functions.h"



/* Exercise 1. Return the number of digits in integer n, n >= 0. */
int num_digits(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + num_digits(n / 10);
    }
}

/* Extra-practice exercises. */
/* Exercise 2. Return x raised to the power n for n >= 0. */
double power2(double x, int n) {
    printf("x = %.1f, n = %d\n", x, n);
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
            return power2(x, n / 2) * power2(x, n / 2);
    } else {
        return x * power2(x, n / 2) * power2(x, n / 2);
    }
}

