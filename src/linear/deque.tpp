#include "deque.h"
using own::ds::linear::DequeList;
using own::ds::linear::DequeStack;

template<typename T>
size_t DequeList<T>::size() const {
    return List<T>::size();
}

template<typename T>
void DequeList<T>::push_front(T value) {
    List<T>::push_front(value);
}

template<typename T>
void DequeList<T>::push_back(T value) {
    List<T>::push_back(value);
}

template<typename T>
T DequeList<T>::front() const {
    return *List<T>::begin();
}

template<typename T>
T DequeList<T>::back() const {
    return *--List<T>::end();
}

template<typename T>
void DequeList<T>::pop_front() {
    List<T>::pop_front();
}

template<typename T>
void DequeList<T>::pop_back() {
    List<T>::pop_back();
}

template<typename T>
DequeList<T>::iterator DequeList<T>::begin() {
    return List<T>::begin();
}

template<typename T>
DequeList<T>::iterator DequeList<T>::end() {
    return List<T>::end();
}

template<typename T>
DequeList<T>::const_iterator DequeList<T>::begin() const {
    return List<T>::begin();
}

template<typename T>
DequeList<T>::const_iterator DequeList<T>::end() const {
    return List<T>::end();
}

namespace own::ds::linear {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, DequeList<T> const& dl) {
        for (T cur_value: dl) os << cur_value << " ";
        os << std::endl;
        return os;
    }
}


template<typename T>
void DequeStack<T>::move_lr() {
    Stack<T> tmp;
    while (tmp.size() + 1 < left.size()) {
        tmp.push(left.top());
        left.pop();
    }
    while (left.size()) {
        right.push(left.top());
        left.pop();
    }
    while (tmp.size()) {
        left.push(tmp.top());
        tmp.pop();
    }
}

template<typename T>
void DequeStack<T>::move_rl() {
    Stack<T> tmp;
    while (tmp.size() + 1 < right.size()) {
        tmp.push(right.top());
        right.pop();
    }
    while (right.size()) {
        left.push(right.top());
        right.pop();
    }
    while (tmp.size()) {
        right.push(tmp.top());
        tmp.pop();
    }
}

template<typename T>
size_t DequeStack<T>::size() const {
    return left.size() + right.size();
}

template<typename T>
void DequeStack<T>::push_front(T value) {
    left.push(value);
}

template<typename T>
void DequeStack<T>::push_back(T value) {
    right.push(value);
}

template<typename T>
T DequeStack<T>::front() {
    if (!left.size()) move_rl();
    return left.top();
}

template<typename T>
T DequeStack<T>::back() {
    if (!right.size()) move_lr();
    return right.top();
}

template<typename T>
void DequeStack<T>::pop_front() {
    if (!left.size()) move_rl();
    left.pop();
}

template<typename T>
void DequeStack<T>::pop_back() {
    if (!right.size()) move_lr();
    right.pop();
}
