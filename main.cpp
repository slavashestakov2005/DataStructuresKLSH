#include <iostream>
#include "examples/frac.h"
#include "linear/vector.h"
#include "linear/stack.h"
#include "linear/queue.h"
#include "linear/list.h"
#include "linear/deque.h"
#include "tree/rbst.h"

using namespace std;
using namespace own::examples;
using namespace own::ds::linear;
using namespace own::ds::tree;

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

    ForwardList<int> fl;
    cout << "fl\n";
    fl.push_front(1);
    fl.push_front(2);
    fl.push_front(3);
    fl.push_front(4);
    fl.push_front(5);
    fl.push_front(6);
    cout << fl;
    cout << (fl.begin() == fl.begin()) << endl;

    ForwardList<int>::iterator it = fl.begin();
    ++it;
    ++it;
    cout << *it << endl;
    fl.insert_after(it, 10);
    cout << fl;
    fl.erase_after(fl.begin());
    cout << fl;
    fl.pop_front();
    cout << fl;
    fl.pop_front();
    fl.pop_front();
    fl.pop_front();
    fl.pop_front();
    cout << fl;
    fl.pop_front();
    fl.pop_front();
    cout << fl;

    cout << "List<int>\n";
    List<int> lst;
    lst.push_front(1);
    cout << *lst.begin() << "\n";
    cout << lst;
    lst.push_back(2);
    cout << lst;
    lst.insert_after(lst.begin(), 3);
    cout << lst;
    lst.push_back(4);
    cout << *lst.end() << endl;
    cout << *--lst.end() << endl;
    cout << lst;
    lst.insert_before(lst.begin(), 5);
    cout << lst;
    lst.insert_after(--lst.end(), 6);
    cout << lst;
    lst.insert_before(lst.end(), 7);
    cout << lst;
    lst.insert_before(--lst.end(), 8);
    cout << lst;

    cout << "\nDequeList<int>\n";
    DequeList<int> dl;
    dl.push_front(1);
    dl.push_front(2);
    dl.push_back(3);
    cout << dl;
    dl.pop_back();
    cout << dl;
    dl.pop_back();
    cout << dl;
    dl.pop_back();
    cout << dl;

    cout << "\nDequeStack<int>\n";
    DequeStack<int> ds;
    ds.push_front(1);
    ds.push_front(2);
    ds.push_back(3);
    cout << ds.front() << " " << ds.back() << "\n";
    ds.pop_back();
    cout << ds.front() << " " << ds.back() << "\n";
    ds.pop_back();
    cout << ds.front() << " " << ds.back() << "\n";
    ds.pop_back();
    cout << ds.front() << " " << ds.back() << "\n";

    BinarySearchTree<int, int> bt;

    cout << "\nBinary Search Tree\n";
    RandomBinarySearchTree<int> *rbst = nullptr;
    rbst -> print(); cout << "\n";
    rbst = rbst -> insert(1);
    rbst -> print(); cout << "\n";
    rbst = rbst -> insert(2);
    rbst -> print(); cout << "\n";
    rbst = rbst -> insert(3);
    rbst -> print(); cout << "\n";
    rbst = rbst -> insert(4);
    rbst -> print(); cout << "\n";
    rbst = rbst -> insert(5);
    rbst -> print(); cout << "\n";

    {
        auto [a, b] = rbst -> find(100);
        rbst = b;
        cout << a << "\n";
        rbst -> print();
        cout << "\n";
    }{
        auto [a, b] = rbst -> find(1);
        rbst = b;
        cout << a << "\n";
        rbst -> print();
        cout << "\n";
    }{
        auto [a, b] = rbst -> find(4);
        rbst = b;
        cout << a << "\n";
        rbst -> print();
        cout << "\n";
    }{
        auto [a, b] = rbst -> find(3);
        rbst = b;
        cout << a << "\n";
        rbst -> print();
        cout << "\n";
    }
    return 0;
}
