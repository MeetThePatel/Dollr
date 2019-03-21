#ifndef units_h
#define units_h

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

// Because of rounding errors when using Floating-Precision data structures, multiply the
// dollar amount by 10000
struct Dollar {
public:
    mpz_class value;
    Dollar();
    Dollar(double);
    Dollar(int);
    Dollar(mpz_class);
    
    friend Dollar operator+ (const Dollar&, const Dollar&);
    friend Dollar operator- (const Dollar&, const Dollar&);
    friend Dollar operator* (const Dollar&, const Dollar&);
    friend Dollar operator/ (const Dollar&, const Dollar&);
    friend std::ostream& operator<< (std::ostream&, const Dollar&);
    
    
};

#endif
