#pragma once

namespace own::ds::tree {
    template<typename T>
    class BinarySearchTree {
    public:
        T value;
        BinarySearchTree *left, *right;
        size_t cur_size;
    public:
        BinarySearchTree();
        BinarySearchTree(T value);

        size_t size() const;

        BinarySearchTree<T> const* find(T key) const;

        ~BinarySearchTree();
    };
}

#include "tree.tpp"
