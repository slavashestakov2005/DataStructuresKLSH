#include <iostream>
#include "examples/frac.h"
#include "linear/vector.h"

using namespace std;
using namespace own::examples;
using namespace own::ds::linear;

int main() {
    Vector v;
    v.push_back(5);
    cout << v.get_back() << endl;
    v.push_back(7);
    v.push_back(11);
    cout << v.get_back() << endl;
    cout << v;
    return 0;
}
