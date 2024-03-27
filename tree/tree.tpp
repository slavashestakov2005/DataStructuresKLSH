#include "tree.h"
using own::ds::tree::BinarySearchTree;

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    left = right = nullptr;
    cur_size = 0;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T value) : value(value) {
    left = right = nullptr;
    cur_size = 1;
}

template<typename T>
size_t BinarySearchTree<T>::size() const {
    return cur_size;
}

template<typename T>
BinarySearchTree<T> const* BinarySearchTree<T>::find(T key) const {
    if (cur_size == 0) return nullptr;
    if (key == value) return this;
    if (key < value) {
        if (left == nullptr) return nullptr;
        return left -> find(key);
    } else {
        if (right == nullptr) return nullptr;
        return right -> find(key);
    }
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {}
