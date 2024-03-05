#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>

#include "../src/1/myxor.hpp"
#include "../src/2/polyeval.hpp"
#include "../src/3/rational.hpp"

void test_myxor1() {
    size_t n = 5;

    char bytes[n] = {
        3, // 0011
        7, // 0111
        9, // 1001
        4, // 0100
        15 // 1111
    };

    // When we apply XOR to multiple bytes, we get 1 for
    // i-th bit if for all bytes the number of ones at i-th position is odd.
    // Otherwize, we get 0. Thus, the result for the above example should be 0110.

    char xor1 = my_xor_naive(bytes, n);
    char xor2 = my_xor(bytes, n);

    assert(xor1 == xor2);
    assert(static_cast<int>(xor1) == 6);

    std::cout << "test_myxor1 passed" << std::endl;
}

void test_myxor2() {
    const size_t num_bytes_init = 20000;
    const size_t num_tests = 32;

    char bytes[num_bytes_init + num_tests];

    for (size_t test_num = 0; test_num < num_tests; test_num++) {
        size_t num_bytes = num_bytes_init + test_num;

        for (size_t i = 0; i < num_bytes; i++) {
            bytes[i] = static_cast<char>(std::rand());
        }

        char xor1 = my_xor_naive(bytes, num_bytes);
        char xor2 = my_xor(bytes, num_bytes);

        assert(xor1 == xor2);
    }

    std::cout << "test_myxor2 passed" << std::endl;
}

void test_polyeval1() {
    // p(x) = 4.0 + 3.0 * x + 2.0 * x^2 + 1.0 * x^3
    // p(0.5) = 6.125

    size_t n = 4;
    double p[n] = {4.0, 3.0, 2.0, 1.0};
    double x = 0.5;

    double result1 = polyeval1(p, n, x);
    double result2 = polyeval2(p, n, x);

    assert(std::abs(result1 - result2) < 1.0E-6);

    std::cout << "test_polyeval1 passed" << std::endl;
}

void test_polyeval2() {
    size_t n = 1000;
    double p[n] = {999.5};
    double x = 0.0175;

    for (size_t i = 1; i < n; i++) {
        p[i] = p[i - 1] - 0.3; 
    }

    double result1 = polyeval1(p, n, x);
    double result2 = polyeval2(p, n, x);

    assert(std::abs(result1 - result2) < 1.0E-6);   

    std::cout << "test_polyeval2 passed" << std::endl;
}

void test_rational1() {
    rational r1 = rational(-3, 2);
    rational r2 = rational(5, 8);

    rational sum = r1 + r2;
    rational diff = r1 - r2;
    rational mult = r1 * r2;
    rational div = r1 / r2;

    assert(sum.get_numerator() == -14);
    assert(sum.get_denominator() == 16);

    sum.reduce();

    assert(sum.get_numerator() == -7);
    assert(sum.get_denominator() == 8);

    assert(diff.get_numerator() == -34);
    assert(diff.get_denominator() == 16);

    diff.reduce();

    assert(diff.get_numerator() == -17);
    assert(diff.get_denominator() == 8);

    assert(mult.get_numerator() == -15);
    assert(mult.get_denominator() == 16);

    assert(div.get_numerator() == -24);
    assert(div.get_denominator() == 10);

    div.reduce();

    assert(div.get_numerator() == -12);
    assert(div.get_denominator() == 5);

    std::cout << "test_rational1 passed" << std::endl;
}

void test_rational2() {
    try {
        rational r(5, 0);
    } catch (zero_denom_exception &e) {
        // std::cout << e.what() << std::endl;
    }

    std::cout << "test_rational2 passed" << std::endl;
}

void test_rational3() {
    try {
        rational r1 = rational(3, 2);
        rational r2 = rational(6, 4);
        
        rational r3 = r2 / (r1 - r2);
    } catch (zero_division_exception &e) {
        // std::cout << e.what() << std::endl;
    }

    std::cout << "test_rational3 passed" << std::endl;
}

int main() {
    std::srand(std::time(nullptr));

    test_myxor1();
    test_myxor2();

    test_polyeval1();
    test_polyeval2();

    test_rational1();
    test_rational2();
    test_rational3();

    return 0;
}
