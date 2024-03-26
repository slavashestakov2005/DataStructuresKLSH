#pragma once

#include "stack.h"

namespace own::ds::linear {
    template<typename T>
    class Queue {
    private:
        Stack<T> left, right;
        void move_stack();
    public:
        size_t size() const;

        void push(T value);
        T front();
        void pop();
    };
}

#include "queue.tpp"
