namespace own::ds::tree {
    template<typename T, typename Child>
    void BinarySearchTree<T, Child>::update_info() {
        static_cast<Child*>(this) -> update();
    }

    template<typename T, typename Child>
    BinarySearchTree<T, Child>::BinarySearchTree() : left(nullptr), right(nullptr) {}

    template<typename T, typename Child>
    BinarySearchTree<T, Child>::BinarySearchTree(T key) : key(key), left(nullptr), right(nullptr) {}

    template<typename T, typename Child>
    BinarySearchTree<T, Child>::BinarySearchTree(T key, bst_ptr_t<Child> left, bst_ptr_t<Child> right)
        : key(key), left(left), right(right) {}

    template<typename T, typename Child>
    std::pair<bst_ptr_t<Child>, bst_ptr_t<Child>> BinarySearchTree<T, Child>::split_lt_geq(T query_key) {
        if (this == nullptr) return {nullptr, nullptr};
        if (query_key <= key) {
            auto [tl, tr] = left -> split_lt_geq(query_key);
            left = tr;
            update_info();
            return {tl, static_cast<bst_ptr_t<Child>>(this)};
        }
        else {
            auto [tl, tr] = right -> split_lt_geq(query_key);
            right = tl;
            update_info();
            return {static_cast<bst_ptr_t<Child>>(this), tr};
        }
    }

    template<typename T, typename Child>
    std::pair<bst_ptr_t<Child>, bst_ptr_t<Child>> BinarySearchTree<T, Child>::split_leq_gt(T query_key) {
        if (this == nullptr) return {nullptr, nullptr};
        if (query_key < key) {
            auto [tl, tr] = left -> split_leq_gt(query_key);
            left = tr;
            update_info();
            return {tl, static_cast<bst_ptr_t<Child>>(this)};
        }
        else {
            auto [tl, tr] = right -> split_leq_gt(query_key);
            right = tl;
            update_info();
            return {static_cast<bst_ptr_t<Child>>(this), tr};
        }
    }

    template<typename T, typename Child>
    bst_ptr_t<Child> BinarySearchTree<T, Child>::insert(T query_key) {
        if (this == nullptr) return new Child(query_key);
        auto [tl, tmr] = split_lt_geq(query_key);
        auto [tm, tr] = tmr -> split_leq_gt(query_key);
        delete tm;
        tm = new Child(query_key);
        return Child::merge(tl, Child::merge(tm, tr));
    }

    template<typename T, typename Child>
    std::pair<bool, bst_ptr_t<Child>> BinarySearchTree<T, Child>::find(T query_key) {
        if (this == nullptr) return {false, nullptr};
        auto [tl, tmr] = split_lt_geq(query_key);
        auto [tm, tr] = tmr -> split_leq_gt(query_key);
        bool ans = (tm != nullptr);
        return {ans, Child::merge(tl, Child::merge(tm, tr))};
    }

    template<typename T, typename Child>
    bst_ptr_t<Child> BinarySearchTree<T, Child>::erase(T query_key) {
        if (this == nullptr) return nullptr;
        auto [tl, tmr] = split_lt_geq(query_key);
        auto [tm, tr] = tmr -> split_leq_gt(query_key);
        delete tm;
        return Child::merge(tl, tr);
    }

    template<typename T, typename Child>
    BinarySearchTree<T, Child>::~BinarySearchTree() {
        delete left;
        delete right;
    }

    template<typename T, typename Child>
    void BinarySearchTree<T, Child>::print() {
        if (this == nullptr) return;
        std::cout << "(";
        left -> print();
        std::cout << ") " << key << " (";
        right -> print();
        std::cout << ")";
    }
}
