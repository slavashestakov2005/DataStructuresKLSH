#pragma once

#include "bst.h"

namespace own::ds::tree {
    template<typename T> class RandomBinarySearchTree;
    template<typename T> using rbst_t = bst_t<RandomBinarySearchTree<T>>;
    template<typename T> using rbst_ptr_t = bst_ptr_t<RandomBinarySearchTree<T>>;

    template<typename T>
    class RandomBinarySearchTree : public BinarySearchTree<T, RandomBinarySearchTree<T>> {
    private:
        static size_t get_size(rbst_ptr_t<T> t);
        static rbst_ptr_t<T> merge(rbst_ptr_t<T> l, rbst_ptr_t<T> r);
        size_t cur_size;
        void update() override;
    public:
        RandomBinarySearchTree();
        RandomBinarySearchTree(T value);
        RandomBinarySearchTree(T value, rbst_ptr_t<T> left, rbst_ptr_t<T> right);

        friend BinarySearchTree<T, RandomBinarySearchTree<T>>;
    };
}

#include "rbst.tpp"
