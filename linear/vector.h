#pragma once

#include <compare>
#include <ostream>

namespace own::ds::linear {
    class Vector {
    private:
        int* data;
        size_t cur_size, cur_capacity;
    public:
        explicit Vector(size_t size = 0);
        Vector(Vector const& v);
        Vector& operator=(Vector const& v);
        void copy(Vector const& v);
        void swap(Vector& v);

        size_t size() const;
        size_t capacity() const;

        void push_back(int value);
        int get_back() const;
        void pop_back();

        int& operator[](int pos);
        int const& operator[](int pos) const;

        using iterator = int*;
        using const_iterator = const int*;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;

        std::strong_ordering operator<=>(Vector const& other) const;
        bool operator==(Vector const& other) const;

        ~Vector();
    };
    std::ostream& operator<<(std::ostream& os, Vector const& v);
}
