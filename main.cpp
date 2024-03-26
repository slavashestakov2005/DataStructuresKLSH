#include <iostream>
#include "examples/frac.h"
#include "linear/vector.h"

using namespace std;
using namespace own::examples;
using namespace own::ds::linear;

int main() {
    Vector v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    cout << v1;
    Vector v2 = v1;
    cout << "v1: " << v1;
    cout << "v2: " << v2;
    v1.push_back(11);
    v2.push_back(13);
    cout << "v1: " << v1;
    cout << "v2: " << v2;
    v2.pop_back();
    v2.pop_back();
    cout << (v1 > v2);
    return 0;
}
