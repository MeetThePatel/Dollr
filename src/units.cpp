#include "units.h"

Dollar::Dollar() {
    value = 0;
}

Dollar::Dollar(double x) {
    value = x * 10000;
}

Dollar::Dollar(int x) {
    value = x * 10000;
}

Dollar::Dollar(mpz_class x) {
    value = x;
}

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
    os << "$" << double(inter.get_si())/100;
    return os;
}
