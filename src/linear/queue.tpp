#include "queue.h"
using own::ds::linear::Queue;

template<typename T>
void Queue<T>::move_stack() {
    while (right.size()) {
        left.push(right.top());
        right.pop();
    }
}

template<typename T>
size_t Queue<T>::size() const {
    return left.size() + right.size();
}

template<typename T>
void Queue<T>::push(T value) {
    right.push(value);
}

template<typename T>
T Queue<T>::front() {
    if (!left.size()) move_stack();
    return left.top();
}

template<typename T>
void Queue<T>::pop() {
    if (!left.size()) move_stack();
    left.pop();
}
