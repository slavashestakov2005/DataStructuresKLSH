#pragma once

#include "vector.h"

namespace own::ds::linear {
    template<typename T>
    class Stack : private Vector<T> {
    public:
        Stack();

        size_t size() const;

        void push(T value);
        T top() const;
        void pop();

        ~Stack();
    };
}

#include "stack.tpp"
