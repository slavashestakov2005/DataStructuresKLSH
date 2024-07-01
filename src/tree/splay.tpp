namespace own::ds::tree {
    template<typename T>
    SplayVertex<T>:: SplayVertex(T value, splay_vertex_ptr_t<T> parent, splay_vertex_ptr_t<T> left, splay_vertex_ptr_t<T> right)
        : value(value), parent(parent), left(left), right(right) {
    }
    
    template<typename T>
    void SplayVertex<T>::print() const {
        if (this == nullptr) return;
        std::cout << "(";
        if (left != nullptr) left -> print();
        std::cout << ") " << value << " (";
        if (right != nullptr) right -> print();
        std::cout << ")";
    }

    template<typename T>
    bool Splay<T>::is_left(splay_vertex_ptr_t<T> v, splay_vertex_ptr_t<T> p) {
        return p -> left == v;
    }

    template<typename T>
    void Splay<T>::rotate(splay_vertex_ptr_t<T> v, splay_vertex_ptr_t<T> p) {
        splay_vertex_ptr_t<T> pp = p -> parent;
        if (pp != nullptr) {
            if (pp -> left == p) pp -> left = v;
            else pp -> right = v;
        }
        if (is_left(v, p)) {
            p -> left = v -> right;
            if (v -> right != nullptr) v -> right -> parent = p;
            v -> right = p;
            v -> parent = p -> parent;
            p -> parent = v;
        } else {
            p -> right = v -> left;
            if (v -> left != nullptr) v -> left -> parent = p;
            v -> left = p;
            v -> parent = p -> parent;
            p -> parent = v;
        }
    }

    template<typename T>
    void Splay<T>::expose(splay_vertex_ptr_t<T> v) {
        while(true) {
            if (v == nullptr) return;
            if (v -> parent == nullptr) {
                root = v;
                return;
            }
            splay_vertex_ptr_t<T> p1 = v -> parent;
            if (p1 -> parent == nullptr) {
                rotate(v, p1);
                continue;
            }
            splay_vertex_ptr_t<T> p2 = p1 -> parent;
            if (is_left(v, p1) == is_left(p1, p2)) {
                rotate(p1, p2);
                rotate(v, p1);
            } else {
                rotate(v, p1);
                rotate(v, p2);
            }
        }
    }

    template<typename T>
    splay_vertex_ptr_t<T> Splay<T>::find(T value) {
        if (root == nullptr) return root;
        splay_vertex_ptr_t<T> current = root;
        splay_vertex_ptr_t<T> last = nullptr;
        while(true) {
            if (current == nullptr) {
                expose(last);
                return nullptr;
            }
            if (current -> value == value) {
                expose(current);
                return current;
            }
            if (current -> value < value) current = current -> right;
            else current = current -> left;
        }
    }

    template<typename T>
    splay_vertex_ptr_t<T> Splay<T>::find_lower(T value) {
        if (root == nullptr) return root;
        splay_vertex_ptr_t<T> current = root;
        splay_vertex_ptr_t<T> last = nullptr;
        splay_vertex_ptr_t<T> answer = nullptr;
        while(true) {
            if (current == nullptr) {
                expose(last);
                return answer;
            }
            if (current -> value == value) {
                expose(current);
                return current;
            }
            if (current -> value < value) {
                answer = current;
                last = current;
                current = current -> right;
            }
            else {
                last = current;
                current = current -> left;
            }
        }
    }

    template<typename T>
    splay_vertex_ptr_t<T> Splay<T>::find_upper(T value) {
        if (root == nullptr) return root;
        splay_vertex_ptr_t<T> current = root;
        splay_vertex_ptr_t<T> last = nullptr;
        splay_vertex_ptr_t<T> answer = nullptr;
        while(true) {
            if (current == nullptr) {
                expose(last);
                return answer;
            }
            if (current -> value == value) {
                expose(current);
                return current;
            }
            if (current -> value < value) {
                last = current;
                current = current -> right;
            }
            else {
                answer = current;
                last = current;
                current = current -> left;
            }
        }
    }

    template<typename T>
    void Splay<T>::insert(T value) {
        splay_vertex_ptr_t<T> added = new splay_vertex_t<T>(value, nullptr, nullptr, nullptr);
        if (root == nullptr) {
            root = added;
            return;
        }
        splay_vertex_ptr_t<T> current = root;
        while(true) {
            if (current -> value == value) {
                expose(current);
                return;
            } else if (current -> value > value) {
                if (current -> left == nullptr) {
                    added -> parent = current;
                    current -> left = added;
                    expose(added);
                    return;
                }
                current = current -> left;
            } else {
                if (current -> right == nullptr) {
                    added -> parent = current;
                    current -> right = added;
                    expose(added);
                    return;
                }
                current = current -> right;
            }
        }
    }

    template<typename T>
    void Splay<T>::erase(T value) {
        if (root == nullptr) return;
        splay_vertex_ptr_t<T> found = find(value);
        if (found == nullptr) return;
        splay_vertex_ptr_t<T> left = root -> left, right = root -> right;
        if (left != nullptr) left -> parent = nullptr;
        if (right != nullptr) right -> parent = nullptr;
        delete root;
        root = nullptr;
        Splay<T> left_tree(left);
        left_tree.find_lower(value);
        root = left_tree.root;
        root -> right = right;
        if (right != nullptr) right -> parent = root;
    }

    template<typename T>
    void Splay<T>::print() const {
        if (root == nullptr) std::cout << "( e )";
        else root -> print();
        std::cout << "\n";
    }

    template<typename T>
    Splay<T>::Splay() : root(nullptr) {
    }

    template<typename T>
    Splay<T>::Splay(splay_vertex_ptr_t<T> root) : root(root) {
    }
};
