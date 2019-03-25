#include "units.h"

Dollar operator+ (const Dollar& x, const Dollar& y) {
    Dollar ret (x.value + y.value);
    return ret;
}

Dollar operator- (const Dollar& x, const Dollar& y) {
    Dollar ret (x.value - y.value);
    return ret;
}

Dollar operator* (const Dollar& x, const Dollar& y) {
    Dollar ret (x.value * y.value);
    return ret;
}

Dollar operator/ (const Dollar& x, const Dollar& y) {
    Dollar ret (x.value / y.value);
    return ret;
}

std::ostream& operator<< (std::ostream& os, const Dollar& x) {
    mpz_class inter = x.value / mpz_class(100);
    os << fixed << setprecision(2) << "$" << double(inter.get_si())/100;
    return os;
}
