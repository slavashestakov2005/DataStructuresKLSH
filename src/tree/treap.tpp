namespace own::ds::tree {
    template<typename T>
    treap_ptr_t<T> Treap<T>::merge(treap_ptr_t<T> l, treap_ptr_t<T> r) {
        if (l == nullptr) return r;
        if (r == nullptr) return l;
        if (l -> priority < r -> priority) {
            l -> right = merge(l -> right, r);
            l -> update();
            return l;
        } else {
            r -> left = merge(l, r -> left);
            r -> update();
            return r;
        }
    }

    template<typename T>
    void Treap<T>::update() {
    }

    template<typename T>
    Treap<T>::Treap() : BinarySearchTree<T, Treap<T>>(), priority(rnd()) {
        update();
    }

    template<typename T>
    Treap<T>::Treap(T value) : BinarySearchTree<T, Treap<T>>(value), priority(rnd()) {
        update();
    }

    template<typename T>
    Treap<T>::Treap(T value, treap_ptr_t<T> left, treap_ptr_t<T> right) : BinarySearchTree<T, Treap<T>>(value, left, right), priority(rnd()) {
        update();
    }

    template<typename T>
    Treap<T>::Treap(T value, treap_ptr_t<T> left, treap_ptr_t<T> right, size_t priority) : BinarySearchTree<T, Treap<T>>(value, left, right), priority(priority) {
        update();
    }
}
