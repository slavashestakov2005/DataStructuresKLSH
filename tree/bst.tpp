namespace own::ds::tree {
    template<typename T, typename Child>
    void BinarySearchTree<T, Child>::update_info() {
        static_cast<Child*>(this) -> update();
    }

    template<typename T, typename Child>
    BinarySearchTree<T, Child>::BinarySearchTree() : left(nullptr), right(nullptr) {}

    template<typename T, typename Child>
    BinarySearchTree<T, Child>::BinarySearchTree(T value) : value(value), left(nullptr), right(nullptr) {}

    template<typename T, typename Child>
    BinarySearchTree<T, Child>::BinarySearchTree(T value, bst_ptr_t<Child> left, bst_ptr_t<Child> right)
        : value(value), left(left), right(right) {}

    template<typename T, typename Child>
    std::pair<bst_ptr_t<Child>, bst_ptr_t<Child>> BinarySearchTree<T, Child>::split_lt_geq(T key) {
        if (this == nullptr) return {nullptr, nullptr};
        if (key <= value) {
            auto [tl, tr] = left -> split_lt_geq(key);
            left = tr;
            update_info();
            return {tl, static_cast<bst_ptr_t<Child>>(this)};
        }
        else {
            auto [tl, tr] = right -> split_lt_geq(key);
            right = tl;
            update_info();
            return {static_cast<bst_ptr_t<Child>>(this), tr};
        }
    }

    template<typename T, typename Child>
    std::pair<bst_ptr_t<Child>, bst_ptr_t<Child>> BinarySearchTree<T, Child>::split_leq_gt(T key) {
        if (this == nullptr) return {nullptr, nullptr};
        if (key < value) {
            auto [tl, tr] = left -> split_leq_gt(key);
            left = tr;
            update_info();
            return {tl, static_cast<bst_ptr_t<Child>>(this)};
        }
        else {
            auto [tl, tr] = right -> split_leq_gt(key);
            right = tl;
            update_info();
            return {static_cast<bst_ptr_t<Child>>(this), tr};
        }
    }

    template<typename T, typename Child>
    bst_ptr_t<Child> BinarySearchTree<T, Child>::insert(T value) {
        if (this == nullptr) return new Child(value);
        auto [tl, tmr] = split_lt_geq(value);
        auto [tm, tr] = tmr -> split_leq_gt(value);
        delete tm;
        tm = new Child(value);
        return Child::merge(tl, Child::merge(tm, tr));
    }

    template<typename T, typename Child>
    std::pair<bool, bst_ptr_t<Child>> BinarySearchTree<T, Child>::find(T value) {
        if (this == nullptr) return {false, nullptr};
        auto [tl, tmr] = split_lt_geq(value);
        auto [tm, tr] = tmr -> split_leq_gt(value);
        bool ans = (tm != nullptr);
        return {ans, Child::merge(tl, Child::merge(tm, tr))};
    }

    template<typename T, typename Child>
    bst_ptr_t<Child> BinarySearchTree<T, Child>::erase(T value) {
        if (this == nullptr) return nullptr;
        auto [tl, tmr] = split_lt_geq(value);
        auto [tm, tr] = tmr -> split_leq_gt(value);
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
        std::cout << ") " << value << " (";
        right -> print();
        std::cout << ")";
    }
}
