namespace own::ds::tree {
    template<typename T>
    size_t RandomBinarySearchTree<T>::get_size(rbst_ptr_t<T> t) {
        return (t == nullptr ? 0 : t -> cur_size);
    }

    template<typename T>
    rbst_ptr_t<T> RandomBinarySearchTree<T>::merge(rbst_ptr_t<T> l, rbst_ptr_t<T> r) {
        if (l == nullptr) return r;
        if (r == nullptr) return l;
        size_t lsz = l -> cur_size, rsz = r -> cur_size;
        size_t val = rnd() % (lsz + rsz);
        if (val < lsz) {
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
    void RandomBinarySearchTree<T>::update() {
        cur_size = 1 + get_size(this -> left) + get_size(this -> right);
    }

    template<typename T>
    RandomBinarySearchTree<T>::RandomBinarySearchTree() : BinarySearchTree<T, RandomBinarySearchTree<T>>() {
        update();
    }

    template<typename T>
    RandomBinarySearchTree<T>::RandomBinarySearchTree(T value) : BinarySearchTree<T, RandomBinarySearchTree<T>>(value) {
        update();
    }

    template<typename T>
    RandomBinarySearchTree<T>::RandomBinarySearchTree(T value, rbst_ptr_t<T> left, rbst_ptr_t<T> right) : BinarySearchTree<T, RandomBinarySearchTree<T>>(value, left, right) {
        update();
    }
}
