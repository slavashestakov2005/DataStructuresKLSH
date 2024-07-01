#pragma once

#include "list.h"
#include "stack.h"

namespace own::ds::linear {
    template<typename T>
    class DequeList : private List<T> {
    public:
        using iterator = ListIterator<T>;
        using const_iterator = const ListIterator<T>;
        size_t size() const;

        void push_front(T value);
        void push_back(T value);
        T front() const;
        T back() const;
        void pop_front();
        void pop_back();

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, DequeList<T> const& dl);

    template<typename T>
    class DequeStack {
    private:
        Stack<T> left, right;
        void move_lr();
        void move_rl();
    public:
        size_t size() const;

        void push_front(T value);
        void push_back(T value);
        T front();
        T back();
        void pop_front();
        void pop_back();
    };

    template<typename T>
    using Deque = DequeStack<T>;
}

#include "deque.tpp"
