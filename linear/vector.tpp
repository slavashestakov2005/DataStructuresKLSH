#include "vector.h"
using own::ds::linear::Vector;

template<typename T>
Vector<T>::Vector(size_t size) {
    data = new T[size];
    cur_size = 0;
    cur_capacity = size;
}

template<typename T>
Vector<T>::Vector(Vector<T> const& v) {
    copy(v); 
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& v) {
    if (this == &v) return *this; 
    copy(v);    // или Vector<T>(v).swap(*this);
    return *this;
}

template<typename T>
void Vector<T>::copy(Vector<T> const& v) {
    cur_size = cur_capacity = v.cur_size;
    data = new T[cur_capacity];
    for (size_t copy_pos = 0; copy_pos < cur_capacity; ++copy_pos) data[copy_pos] = v.data[copy_pos];
}

template<typename T>
void Vector<T>::swap(Vector<T>& v) {
    std::swap(data, v.data);
    std::swap(cur_size, v.cur_size);
    std::swap(cur_capacity, v.cur_capacity);
}

template<typename T>
size_t Vector<T>::size() const {
    return cur_size;
}

template<typename T>
size_t Vector<T>::capacity() const {
    return cur_capacity; 
}

template<typename T>
void Vector<T>::push_back(T value) {
    if (cur_size == cur_capacity) {
        size_t new_capacity = cur_capacity * 2 + 1;
        T* new_data = new T[new_capacity];
        for (size_t copy_pos = 0; copy_pos < cur_capacity; ++copy_pos) new_data[copy_pos] = data[copy_pos];
        delete[] data;
        cur_capacity = new_capacity;
        data = new_data;
    }
    data[cur_size] = value;
    ++cur_size;
}

template<typename T>
T Vector<T>::get_back() const {
    if (cur_size == 0) return -1;
    return data[cur_size - 1];
}

template<typename T>
void Vector<T>::pop_back() {
    if (cur_size == 0) return;
    --cur_size;
    if (cur_size * 4 < cur_capacity) {
        size_t new_capacity = cur_size * 2;
        T* new_data = new T[new_capacity];
        for (size_t copy_pos = 0; copy_pos < cur_size; ++copy_pos) new_data[copy_pos] = data[copy_pos];
        delete [] data;
        cur_capacity = new_capacity;
        data = new_data;
    }
}

template<typename T>
T& Vector<T>::operator[](T pos) {
    return data[pos];
}

template<typename T>
T const& Vector<T>::operator[](T pos) const {
    return data[pos];
}

template<typename T>
Vector<T>::iterator Vector<T>::begin() {
    return data;
}

template<typename T>
Vector<T>::iterator Vector<T>::end() {
    return data + cur_size;
}

template<typename T>
Vector<T>::const_iterator Vector<T>::begin() const {
    return data;
}

template<typename T>
Vector<T>::const_iterator Vector<T>::end() const {
    return data + cur_size;
}

template<typename T>
std::strong_ordering Vector<T>::operator<=>(Vector<T> const& other) const {
    if (cur_size != other.cur_size) return cur_size <=> other.cur_size;
    for (size_t pos = 0; pos < cur_size; ++pos) if (data[pos] != other.data[pos]) return data[pos] <=> other.data[pos];
    return std::strong_ordering::equal;
}

template<typename T>
bool Vector<T>::operator==(Vector<T> const& other) const {
    return (*this <=> other) == std::strong_ordering::equal;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

namespace own::ds::linear {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, Vector<T> const& v) {
        for (T cur_value: v) os << cur_value << " ";
        os << std::endl;
        return os;
    }
}
