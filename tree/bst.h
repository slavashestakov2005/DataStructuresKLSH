#pragma once

#include <random>

namespace own::ds::tree {
    template<typename Child> using bst_t = Child;
    template<typename Child> using bst_ptr_t = Child*;

    template<typename T, typename Child>
    class BinarySearchTree {
    private:
        void update_info();
    protected:
        T key;
        bst_ptr_t<Child> left, right;
        virtual void update() = 0;
    public:
        BinarySearchTree();
        BinarySearchTree(T key);
        BinarySearchTree(T key, bst_ptr_t<Child> left, bst_ptr_t<Child> right);

        std::pair<bst_ptr_t<Child>, bst_ptr_t<Child>> split_lt_geq(T query_key);      // < x  | >= x
        std::pair<bst_ptr_t<Child>, bst_ptr_t<Child>> split_leq_gt(T query_key);      // <= x | > x

        bst_ptr_t<Child> insert(T query_key);
        std::pair<bool, bst_ptr_t<Child>> find(T query_key);
        bst_ptr_t<Child> erase(T query_key);

        virtual ~BinarySearchTree();
        void print();
    };

    std::mt19937 rnd(421);
}

#include "bst.tpp"
