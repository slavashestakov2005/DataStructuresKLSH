#include "frac.h"

using namespace own::examples;


Frac::Frac() : num(0), den(1) {}

Frac::Frac(int a, int b) : num(a), den(b) {}

Frac Frac::operator+(Frac other) {
    return Frac(num * other.den + other.num * den , den * other.den);
}

Frac Frac::operator*(Frac other) {
    return Frac(num * other.num, den * other.den);
}

namespace own::examples {
    std::ostream& operator<<(std::ostream& os, Frac const& f) {
        return os << f.num << "/" << f.den;
    }
}
