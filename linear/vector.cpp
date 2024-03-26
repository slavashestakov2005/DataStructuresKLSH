#include "vector.h"
#include <iostream>
using own::ds::linear::Vector;

Vector::Vector(size_t size) {
    std::cout << "Call " << size << "\n";
    data = new int[size];
    cur_size = 0;
    cur_capacity = size;
}

Vector::Vector(Vector const& v) {
    copy(v); 
}

Vector& Vector::operator=(Vector const& v) {
    if (this == &v) return *this; 
    copy(v);    // или Vector(v).swap(*this);
    return *this;
}

void Vector::copy(Vector const& v) {
    cur_size = cur_capacity = v.cur_size;
    data = new int[cur_capacity];
    for (size_t copy_pos = 0; copy_pos < cur_capacity; ++copy_pos) data[copy_pos] = v.data[copy_pos];
}

void Vector::swap(Vector& v) {
    std::swap(data, v.data);
    std::swap(cur_size, v.cur_size);
    std::swap(cur_capacity, v.cur_capacity);
}

size_t Vector::size() const {
    return cur_size;
}

size_t Vector::capacity() const {
    return cur_capacity; 
}

void Vector::push_back(int value) {
    if (cur_size == cur_capacity) {
        size_t new_capacity = cur_capacity * 2 + 1;
        int* new_data = new int[new_capacity];
        for (size_t copy_pos = 0; copy_pos < cur_capacity; ++copy_pos) new_data[copy_pos] = data[copy_pos];
        delete[] data;
        cur_capacity = new_capacity;
        data = new_data;
    }
    data[cur_size] = value;
    ++cur_size;
}

int Vector::get_back() const {
    if (cur_size == 0) return -1;
    return data[cur_size - 1];
}

void Vector::pop_back() {
    if (cur_size == 0) return;
    --cur_size;
    if (cur_size * 4 < cur_capacity) {
        size_t new_capacity = cur_size * 2;
        int* new_data = new int[new_capacity];
        for (size_t copy_pos = 0; copy_pos < cur_size; ++copy_pos) new_data[copy_pos] = data[copy_pos];
        delete [] data;
        cur_capacity = new_capacity;
        data = new_data;
    }
}

int& Vector::operator[](int pos) {
    return data[pos];
}

int const& Vector::operator[](int pos) const {
    return data[pos];
}

Vector::iterator Vector::begin() {
    return data;
}

Vector::iterator Vector::end() {
    return data + cur_size;
}

Vector::const_iterator Vector::begin() const {
    return data;
}

Vector::const_iterator Vector::end() const {
    return data + cur_size;
}

std::strong_ordering Vector::operator<=>(Vector const& other) const {
    if (cur_size != other.cur_size) return cur_size <=> other.cur_size;
    for (size_t pos = 0; pos < cur_size; ++pos) if (data[pos] != other.data[pos]) return data[pos] <=> other.data[pos];
    return std::strong_ordering::equal;
}

bool Vector::operator==(Vector const& other) const {
    return (*this <=> other) == std::strong_ordering::equal;
}

Vector::~Vector() {
    delete[] data;
}

namespace own::ds::linear {
    std::ostream& operator<<(std::ostream& os, Vector const& v) {
        for (int cur_value: v) os << cur_value << " ";
        os << std::endl;
        return os;
    }
}
