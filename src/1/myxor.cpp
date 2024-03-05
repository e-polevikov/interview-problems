#include "myxor.hpp"

char my_xor_naive(char *p, size_t n) {
    char bytes_xor = p[0];

    for (size_t i = 1; i < n; i++) {
        bytes_xor ^= p[i];
    }

    return bytes_xor;
}

char my_xor(char *p, size_t n) {
    long int *ibytes = reinterpret_cast<long int*>(p);
    long int ibytes_xor = ibytes[0];
    
    for (size_t i = 1; i < n / sizeof(long int); i++) {
        ibytes_xor ^= ibytes[i];
    }

    char *cbytes = reinterpret_cast<char*>(&ibytes_xor);
    char cbytes_xor = cbytes[0];

    for (size_t i = 1; i < sizeof(long int); i++) {
        cbytes_xor ^= cbytes[i];
    }

    if (n <= sizeof(long int)) {
        return cbytes_xor;
    }

    for (size_t i = n % sizeof(long int); i > 0; i--) {
        cbytes_xor ^= p[n - i];
    }

    return cbytes_xor;
}
