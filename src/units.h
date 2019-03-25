#ifndef units_h
#define units_h

#include <iostream>
#include <iomanip>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

// Because of rounding errors when using Floating-Precision data structures, multiply the
// dollar amount by 10000
struct Dollar {
public:
    mpz_class value;
    
    Dollar() : value(0.0){};
    explicit Dollar(double value) : value(10000 * value){};
    explicit Dollar(int value) : value(10000 * value){};
    explicit Dollar(mpz_class value) : value(value){};
    
    friend Dollar operator+ (const Dollar&, const Dollar&);
    friend Dollar operator- (const Dollar&, const Dollar&);
    friend Dollar operator* (const Dollar&, const Dollar&);
    friend Dollar operator/ (const Dollar&, const Dollar&);
    friend std::ostream& operator<< (std::ostream&, const Dollar&);
};

#endif
