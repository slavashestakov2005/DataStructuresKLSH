#include <iostream>
#include "examples/frac.h"
#include "linear/vector.h"
#include "linear/stack.h"
#include "linear/queue.h"
#include "linear/list.h"
#include "linear/deque.h"
#include "tree/rbst.h"
#include "tree/treap.h"
#include "tree/treap_implicit_key.h"

using namespace std;
using namespace own::examples;
using namespace own::ds::linear;
using namespace own::ds::tree;

template<typename T>
void test_tree_data_structure(std::string const& name) {
    cout << "\n" << name << "\n";
    T *tree_ds = nullptr;
    tree_ds -> print(); cout << "\n";
    tree_ds = tree_ds -> insert(1);
    tree_ds -> print(); cout << "\n";
    tree_ds = tree_ds -> insert(2);
    tree_ds -> print(); cout << "\n";
    tree_ds = tree_ds -> insert(3);
    tree_ds -> print(); cout << "\n";
    tree_ds = tree_ds -> insert(4);
    tree_ds -> print(); cout << "\n";
    tree_ds = tree_ds -> insert(5);
    tree_ds -> print(); cout << "\n";

    {
        auto [a, b] = tree_ds -> find(100);
        tree_ds = b;
        cout << a << "\n";
        tree_ds -> print();
        cout << "\n";
    }{
        auto [a, b] = tree_ds -> find(1);
        tree_ds = b;
        cout << a << "\n";
        tree_ds -> print();
        cout << "\n";
    }{
        auto [a, b] = tree_ds -> find(4);
        tree_ds = b;
        cout << a << "\n";
        tree_ds -> print();
        cout << "\n";
    }{
        auto [a, b] = tree_ds -> find(3);
        tree_ds = b;
        cout << a << "\n";
        tree_ds -> print();
        cout << "\n";
    }
}


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

    // BinarySearchTree<int, int> bt;

    test_tree_data_structure<RandomBinarySearchTree<int>>("Binary Search Tree");
    test_tree_data_structure<Treap<int>>("Treap");

    cout << "\nTreapImplicitKey\n";
    TreapImplicitKey<char> *trik = nullptr;
    trik = trik -> insert(0, 'H');
    trik -> print(); cout << "\n";
    trik = trik -> insert(1, 'l');
    trik -> print(); cout << "\n";
    trik = trik -> insert(1, 'e');
    trik -> print(); cout << "\n";
    trik = trik -> insert(3, 'l');
    trik -> print(); cout << "\n";
    trik = trik -> insert(3, 'l');
    trik -> print(); cout << "\n";
    trik = trik -> insert(5, 'o');
    trik -> print(); cout << "\n";
    trik = trik -> erase(4);
    trik -> print(); cout << "\n";

    TreapImplicitKey<int> *trik2 = nullptr;
    trik2 = trik2 -> insert(0, 5);
    trik2 -> print(); cout << "\n";
    trik2 = trik2 -> insert(1, 7);
    trik2 -> print(); cout << "\n";
    trik2 = trik2 -> insert(1, 3);
    trik2 -> print(); cout << "\n";
    trik2 = trik2 -> insert(3, 9);
    trik2 -> print(); cout << "\n";
    trik2 = trik2 -> insert(3, 1);
    trik2 -> print(); cout << "\n";
    trik2 = trik2 -> insert(5, 4);
    trik2 -> print(); cout << "\n";
    {
        auto z = trik2 -> sum_segment(2, 3);
        trik2 = z.second;
        cout << z.first << "\n";
    }
    trik2 -> print(); cout << "\n";
    {
        auto z = trik2 -> sum_segment(4, 4);
        trik2 = z.second;
        cout << z.first << "\n";
    }
    trik2 -> print(); cout << "\n";
    {
        auto z = trik2 -> sum_segment(0, 5);
        trik2 = z.second;
        cout << z.first << "\n";
    }
    trik2 -> print(); cout << "\n";
    return 0;
}
