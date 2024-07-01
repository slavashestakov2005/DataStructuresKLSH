namespace own::ds::tree {
    template<typename T>
    void TreapImplicitKey<T>::update() {
        cur_size = 1 + get_size(left) + get_size(right);
        sum = value + get_sum(left) + get_sum(right);
    }

    template<typename T>
    size_t TreapImplicitKey<T>::get_size(treap_implicit_key_ptr_t<T> t) {
        return (t == nullptr ? 0 : t -> cur_size);
    }

    template<typename T>
    T TreapImplicitKey<T>::get_sum(treap_implicit_key_ptr_t<T> t) {
        return (t == nullptr ? 0 : t -> sum);
    }

    template<typename T>
    std::pair<treap_implicit_key_ptr_t<T>, treap_implicit_key_ptr_t<T>> TreapImplicitKey<T>::split_by_left_size(size_t left_size) {
        if (this == nullptr) return {nullptr, nullptr};
        size_t real_left_size = get_size(left);
        if (left_size < real_left_size) {
            auto [tl, tr] = left -> split_by_left_size(left_size);
            left = tr;
            update();
            return {tl, this};
        } else if (left_size == real_left_size) {
            auto tl = left;
            left = nullptr;
            update();
            return {tl, this};
        } else if (left_size == real_left_size + 1) {
            auto tr = right;
            right = nullptr;
            update();
            return {this, tr};
        } else {
            auto [tl, tr] = right -> split_by_left_size(left_size - real_left_size - 1);
            right = tl;
            update();
            return {this, tr};
        }
    }

    template<typename T>
    treap_implicit_key_ptr_t<T> TreapImplicitKey<T>::merge(treap_implicit_key_ptr_t<T> l, treap_implicit_key_ptr_t<T> r) {
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
    TreapImplicitKey<T>::TreapImplicitKey() : priority(rnd()), left(nullptr), right(nullptr) {
        update();
    }

    template<typename T>
    TreapImplicitKey<T>::TreapImplicitKey(T value) : priority(rnd()), value(value), left(nullptr), right(nullptr) {
        update();
    }

    template<typename T>
    TreapImplicitKey<T>::TreapImplicitKey(T value, treap_implicit_key_ptr_t<T> left, treap_implicit_key_ptr_t<T> right) : priority(rnd()), value(value), left(left), right(right) {
        update();
    }

    template<typename T>
    TreapImplicitKey<T>::TreapImplicitKey(T value, treap_implicit_key_ptr_t<T> left, treap_implicit_key_ptr_t<T> right, size_t priority) : priority(priority), value(value), left(left), right(right) {
        update();
    }

    template<typename T>
    treap_implicit_key_ptr_t<T> TreapImplicitKey<T>::insert(size_t pos, T insert_value) {
        if (this == nullptr) return new TreapImplicitKey(insert_value);
        auto [tl, tr] = split_by_left_size(pos);
        auto tm = new TreapImplicitKey(insert_value);
        return TreapImplicitKey::merge(tl, TreapImplicitKey::merge(tm, tr));
    }

    template<typename T>
    treap_implicit_key_ptr_t<T> TreapImplicitKey<T>::erase(size_t pos) {
        if (this == nullptr) return nullptr;
        auto [tl, tmr] = split_by_left_size(pos);
        auto [tm, tr] = tmr -> split_by_left_size(1);
        delete tm;
        return TreapImplicitKey::merge(tl, tr);
    }

    template<typename T>
    std::pair<T, treap_implicit_key_ptr_t<T>> TreapImplicitKey<T>::sum_segment(size_t l, size_t r) {
        if (this == nullptr) return {0, nullptr};
        auto [tl, tmr] = split_by_left_size(l);
        auto [tm, tr] = tmr -> split_by_left_size(r - l + 1);
        T ans = get_sum(tm);
        return {ans, TreapImplicitKey::merge(tl, TreapImplicitKey::merge(tm, tr))};
    }

    template<typename T>
    void TreapImplicitKey<T>::print() const {
        if (this == nullptr) return;
        std::cout << "(";
        left -> print();
        std::cout << ") " << value << " (";
        right -> print();
        std::cout << ")";
    }
}
