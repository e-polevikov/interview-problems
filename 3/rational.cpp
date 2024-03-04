#include "rational.hpp"
#include <cmath>

namespace {

int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        (a > b) ? a %= b : b %= a;
    }

    return a + b;
}

}

rational::rational(int numerator)
    : numerator_(numerator)
    , denominator_(1)
{ }

rational::rational(int numerator, int denominator)
    : numerator_(numerator)
    , denominator_(denominator)
{ 
    if (denominator_ == 0) {
        throw zero_denom_exception();
    }
}

int rational::get_numerator() const {
    return numerator_;
}

int rational::get_denominator() const {
    return denominator_;
}

rational rational::operator+(const rational &other) const {
    int numerator
        = numerator_ * other.get_denominator()
        + other.get_numerator() * denominator_;
    
    int denominator = denominator_ * other.denominator_;

    return rational(numerator, denominator);
}

rational rational::operator-(const rational &other) const {
    return (*this) + (-other);
}

rational rational::operator-() const {
    return rational(-numerator_, denominator_);
}

rational rational::operator*(const rational &other) const {
    return rational(
        numerator_ * other.get_numerator(),
        denominator_ * other.get_denominator()
    );
}

rational rational::operator/(const rational &other) const {
    if (other.get_numerator() == 0) {
        throw zero_division_exception();
    }

    return rational(
        numerator_ * other.get_denominator(),
        denominator_ * other.get_numerator()
    );
}

void rational::reduce() {
    int num_denom_gcd = gcd(abs(numerator_), denominator_);
    numerator_ /= num_denom_gcd;
    denominator_ /= num_denom_gcd;
}
