#include "stack.h"
using own::ds::linear::Stack;

template<typename T>
Stack<T>::Stack() : Vector<T>::Vector() {}

template<typename T>
size_t Stack<T>::size() const {
    return Vector<T>::size();
}

template<typename T>
void Stack<T>::push(T value) {
    Vector<T>::push_back(value);
}

template<typename T>
T Stack<T>::top() const {
    return Vector<T>::get_back();
}

template<typename T>
void Stack<T>::pop() {
    Vector<T>::pop_back();
}

template<typename T>
Stack<T>::~Stack() {}
