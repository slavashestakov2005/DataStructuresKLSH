#pragma once

#include "bst.h"

namespace own::ds::tree {
    template<typename T> class SplayVertex;
    template<typename T> class Splay;
    template<typename T> using splay_vertex_t = SplayVertex<T>;
    template<typename T> using splay_vertex_ptr_t = SplayVertex<T>*;

    template<typename T>
    struct SplayVertex {
    private:
        T value;
        splay_vertex_ptr_t<T> parent, left, right;
    public:
        SplayVertex(T value, splay_vertex_ptr_t<T> parent, splay_vertex_ptr_t<T> left, splay_vertex_ptr_t<T> right);
        void print() const;

        friend Splay<T>;
    };

    template<typename T>
    struct Splay {
    private:
        splay_vertex_ptr_t<T> root;
        static bool is_left(splay_vertex_ptr_t<T> v, splay_vertex_ptr_t<T> p);
        static void replaceChild(splay_vertex_ptr_t<T> v, splay_vertex_ptr_t<T> p1, splay_vertex_ptr_t<T> p2);
        static void rotate(splay_vertex_ptr_t<T> v, splay_vertex_ptr_t<T> p);
        void expose(splay_vertex_ptr_t<T> v);
    public:
        splay_vertex_ptr_t<T> find(T value);
        splay_vertex_ptr_t<T> find_lower(T value);
        splay_vertex_ptr_t<T> find_upper(T value);
        void insert(T value);
        void erase(T value);
        void print() const;

        Splay();
        Splay(splay_vertex_ptr_t<T> root);
    };
}

#include "splay.tpp"
