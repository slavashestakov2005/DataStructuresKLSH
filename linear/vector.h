#pragma once

#include <compare>
#include <ostream>

namespace own::ds::linear {
    template<typename T>
    class Vector {
    private:
        T* data;
        size_t cur_size, cur_capacity;
    public:
        explicit Vector(size_t size = 0);
        Vector(Vector<T> const& v);
        Vector<T>& operator=(Vector<T> const& v);
        void copy(Vector<T> const& v);
        void swap(Vector<T>& v);

        size_t size() const;
        size_t capacity() const;

        void push_back(T value);
        T get_back() const;
        void pop_back();

        T& operator[](T pos);
        T const& operator[](T pos) const;

        using iterator = T*;
        using const_iterator = const T*;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;

        std::strong_ordering operator<=>(Vector<T> const& other) const;
        bool operator==(Vector<T> const& other) const;

        ~Vector();
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, Vector<T> const& v);
}

#include "vector.tpp"
