#pragma once

namespace own::ds::linear {
    template<typename T> class ForwardListIterator;
    template<typename T> class ForwardList;

    template<typename T>
    class ForwardListItem {
    private:
        T value;
        ForwardListItem<T> *next;
    public:
        ForwardListItem(T value, ForwardListItem<T> *next);
        friend class ForwardListIterator<T>;
        friend class ForwardList<T>;
    };

    template<typename T>
    class ForwardListIterator {
    private:
        ForwardListItem<T> *it;
    public:
        using iterator_category = std::forward_iterator_tag;
        ForwardListIterator(ForwardListItem<T> *it = nullptr);
        T& operator*();
        ForwardListIterator<T> operator++();
        bool operator==(ForwardListIterator<T> const& other) const;
        friend class ForwardList<T>;
    };
    
    template<typename T>
    class ForwardList {
    public:
        using iterator = ForwardListIterator<T>;
        using const_iterator = const ForwardListIterator<T>;
    private:
        iterator first, after_end;
        size_t cur_size;
    public:
        ForwardList();

        size_t size() const;

        void insert_after(iterator it, T value);
        void erase_after(iterator it);
        void push_front(T value);
        void pop_front();

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, ForwardList<T> const& fl);


    template<typename T> class ListIterator;
    template<typename T> class List;

    template<typename T>
    class ListItem {
    private:
        T value;
        ListItem<T> *prev, *next;
    public:
        ListItem(T value, ListItem<T> *prev, ListItem *next);
        friend class ListIterator<T>;
        friend class List<T>;
    };

    template<typename T>
    class ListIterator {
    public:
        ListItem<T> *it;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        ListIterator(ListItem<T> *it = nullptr);
        T& operator*();
        ListIterator<T> operator++();
        ListIterator<T> operator--();
        bool operator==(ListIterator<T> const& other) const;
        friend class List<T>;
    };
    
    template<typename T>
    class List {
    public:
        using iterator = ListIterator<T>;
        using const_iterator = const ListIterator<T>;
    private:
        iterator first, last, after_end;
        size_t cur_size;
    public:
        List();

        size_t size() const;

        void insert_after(iterator it, T value);
        void insert_before(iterator it, T value);
        void erase(iterator it);
        void push_front(T value);
        void push_back(T value);
        void pop_front();
        void pop_back();

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, List<T> const& lst);
}

#include "list.tpp"
