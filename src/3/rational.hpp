#pragma once
#include <exception>
#include <string>

class rational {
public:
    explicit rational(int);
    rational(int, int);

    int get_numerator() const;
    int get_denominator() const;

    rational operator+(const rational&) const;
    rational operator-(const rational&) const;
    rational operator*(const rational&) const;
    rational operator/(const rational&) const;

    rational operator-() const;

    void reduce();
private:
    int numerator_;
    int denominator_;
};

class zero_denom_exception : public std::exception {
private:
    const std::string msg = "Impossible to construct rational number with zero denominator.";

public:
    const char* what() {
        return msg.c_str();
    }
};

class zero_division_exception : public std::exception {
private:
    const std::string msg = "Impossible to apply division: divisor is equal to zero.";

public:
    const char* what() {
        return msg.c_str();
    }
};
