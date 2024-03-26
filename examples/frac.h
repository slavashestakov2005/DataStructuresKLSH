#pragma once

#include <ostream>

namespace own::examples {
    class Frac {
    private:
        int num, den;
    public:
        Frac();
        Frac(int a, int b);
        Frac operator+(Frac other);
        Frac operator*(Frac other);
        friend std::ostream& operator<<(std::ostream& os, Frac const& f);
    };
}
