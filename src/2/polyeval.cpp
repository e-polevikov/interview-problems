#include "polyeval.hpp"

double polyeval1(double *a, size_t n, double x) {
    double result = a[0];
    double xPow = x;

    // 2 * (n - 1) multiplications
    // n - 1 additions
    for (size_t coeff_id = 1; coeff_id < n; coeff_id++) {
        result += a[coeff_id] * xPow;
        xPow *= x;
    }

    return result;
}

double polyeval2(double *a, size_t n, double x) {
    double result = a[n - 1];

    // n - 1 multiplications
    // n - 1 additions
    for (size_t i = 2; i <= n; i++) {
        result = result * x + a[n - i];
    }

    return result;
}