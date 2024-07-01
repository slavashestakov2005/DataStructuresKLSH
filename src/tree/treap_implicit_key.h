#pragma once

#include "bst.h"

namespace own::ds::tree {
    template<typename T> class TreapImplicitKey;
    template<typename T> using treap_implicit_key_t = TreapImplicitKey<T>;
    template<typename T> using treap_implicit_key_ptr_t = TreapImplicitKey<T>*;

    template<typename T>
    class TreapImplicitKey {
    private:
        size_t priority, cur_size;
        T value, sum;
        treap_implicit_key_ptr_t<T> left, right;
        void update();
        static size_t get_size(treap_implicit_key_ptr_t<T> t);
        static T get_sum(treap_implicit_key_ptr_t<T> t);

        std::pair<treap_implicit_key_ptr_t<T>, treap_implicit_key_ptr_t<T>> split_by_left_size(size_t left_size);
        static treap_implicit_key_ptr_t<T> merge(treap_implicit_key_ptr_t<T> l, treap_implicit_key_ptr_t<T> r);
    public:
        TreapImplicitKey();
        TreapImplicitKey(T value);
        TreapImplicitKey(T value, treap_implicit_key_ptr_t<T> left, treap_implicit_key_ptr_t<T> right);
        TreapImplicitKey(T value, treap_implicit_key_ptr_t<T> left, treap_implicit_key_ptr_t<T> right, size_t priority);

        treap_implicit_key_ptr_t<T> insert(size_t pos, T insert_value);
        treap_implicit_key_ptr_t<T> erase(size_t pos);
        std::pair<T, treap_implicit_key_ptr_t<T>> sum_segment(size_t l, size_t r);

        void print() const;
    };
}

#include "treap_implicit_key.tpp"
