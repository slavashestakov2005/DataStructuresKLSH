#pragma once

#include "bst.h"

namespace own::ds::tree {
    template<typename T> class Treap;
    template<typename T> using treap_t = bst_t<Treap<T>>;
    template<typename T> using treap_ptr_t = bst_ptr_t<Treap<T>>;

    template<typename T>
    class Treap : public BinarySearchTree<T, Treap<T>> {
    private:
        static treap_ptr_t<T> merge(treap_ptr_t<T> l, treap_ptr_t<T> r);
        size_t priority;
        void update() override;
    public:
        Treap();
        Treap(T value);
        Treap(T value, treap_ptr_t<T> left, treap_ptr_t<T> right);
        Treap(T value, treap_ptr_t<T> left, treap_ptr_t<T> right, size_t priority);

        friend BinarySearchTree<T, Treap<T>>;
    };
}

#include "treap.tpp"
