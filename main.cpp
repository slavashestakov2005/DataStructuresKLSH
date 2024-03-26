#include <iostream>
#include "examples/frac.h"
#include "linear/vector.h"
#include "linear/stack.h"
#include "linear/queue.h"

using namespace std;
using namespace own::examples;
using namespace own::ds::linear;

int main() {
    Vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    cout << v1;
    Vector<int> v2 = v1;
    cout << "v1: " << v1;
    cout << "v2: " << v2;
    v1.push_back(11);
    v2.push_back(13);
    cout << "v1: " << v1;
    cout << "v2: " << v2;
    v2.pop_back();
    v2.pop_back();
    cout << (v1 > v2) << "\n";
    Vector<char> text;
    text.push_back('H');
    text.push_back('e');
    text.push_back('l');
    text.push_back('l');
    text.push_back('o');
    cout << text;

    Stack<int> s;
    s.push(3);
    cout << s.top() << " " << s.size() << "\n";
    s.push(5);
    s.push(7);
    cout << s.top() << " " << s.size() << "\n";
    s.pop();
    cout << s.top() << " " << s.size() << "\n";

    Stack<int> t(s);
    t.push(11);
    cout << "s : " << s.top() << " " << s.size() << "\n";
    cout << "t : " << t.top() << " " << t.size() << "\n";

    Queue<int> q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);

    cout << q.size() << " " << q.front() << "\n";
    q.pop();
    cout << q.size() << " " << q.front() << "\n";
    q.pop();
    cout << q.size() << " " << q.front() << "\n";
    q.pop();
    cout << q.size() << " " << q.front() << "\n";
    q.pop();
    cout << q.size() << " " << q.front() << "\n";
    q.pop();
    return 0;
}
