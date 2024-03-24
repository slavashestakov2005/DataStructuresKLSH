#include <iostream>

using namespace std;

class Frac {
private:
    int num, den;
public:
    Frac() : num(0), den(1) {}
    Frac(int a, int b) : num(a), den(b) {}

    Frac operator+(Frac other) {
        return Frac(num * other.den + other.num * den , den * other.den);
    }
    Frac operator*(Frac other) {
        return Frac(num * other.num, den * other.den);
    }

    friend ostream& operator<<(ostream& os, Frac const& f);
};

ostream& operator<<(ostream& os, Frac const& f) {
    return os << f.num << "/" << f.den;
}


int main() {
    Frac a(1, 2), b(1, 3);
    Frac c = a + b;
    cout << c;
    return 0;
}
