#include "vector.h"

using own::ds::linear::Vector;

Vector::Vector() : data(nullptr), cur_size(0), cur_capacity(0) {}

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

int Vector::get_back() {
    if (cur_size == 0) return -1;
    return data[cur_size - 1];
}

Vector::~Vector() {
    delete[] data;
}

namespace own::ds::linear {
    std::ostream& operator<<(std::ostream& os, Vector const& v) {
        for (size_t cur_pos = 0; cur_pos < v.cur_size; ++cur_pos) os << v.data[cur_pos] << " ";
        os << std::endl;
        return os;
    }
}
