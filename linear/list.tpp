#include "list.h"
using own::ds::linear::ForwardListItem;
using own::ds::linear::ForwardListIterator;
using own::ds::linear::ForwardList;
using own::ds::linear::ListItem;
using own::ds::linear::ListIterator;
using own::ds::linear::List;


template<typename T>
ForwardListItem<T>::ForwardListItem(T value, ForwardListItem<T> *next) : value(value), next(next) {}

template<typename T>
ForwardListIterator<T>::ForwardListIterator(ForwardListItem<T> *it) : it(it) {}

template<typename T>
T& ForwardListIterator<T>::operator*() {
    return it -> value;
}

template<typename T>
ForwardListIterator<T> ForwardListIterator<T>::operator++() {
    it = it -> next;
    return *this;
}

template<typename T>
bool ForwardListIterator<T>::operator==(ForwardListIterator<T> const& other) const {
    if (it == nullptr && other.it == nullptr) return true;
    if (it == nullptr || other.it == nullptr) return false;
    return it -> next == other.it -> next;
}


template<typename T>
ForwardList<T>::ForwardList() {
    after_end = first = ForwardListIterator<T>(nullptr);
    cur_size = 0;
}

template<typename T>
size_t ForwardList<T>::size() const {
    return cur_size;
}

template<typename T>
void ForwardList<T>::insert_after(ForwardList<T>::iterator it, T value) {
    it.it -> next = new ForwardListItem<T>(value, it.it -> next);
    ++cur_size;
}

template<typename T>
void ForwardList<T>::erase_after(ForwardList<T>::iterator it) {
    if (it.it == nullptr || it.it -> next == nullptr) return;
    ForwardListItem<T> *next_next = it.it -> next -> next;
    delete it.it -> next;
    it.it -> next = next_next;
    --cur_size;
}

template<typename T>
void ForwardList<T>::push_front(T value) {
    if (cur_size == 0) first = ForwardListIterator<T>(new ForwardListItem<T>(value, nullptr));
    else first = ForwardListIterator<T>(new ForwardListItem<T>(value, first.it));
    ++cur_size;
}

template<typename T>
void ForwardList<T>::pop_front() {
    if (cur_size == 0) return;
    ForwardListItem<T> *new_first = first.it -> next;
    delete first.it;
    first = ForwardListIterator<T>(new_first);
    --cur_size;
}

template<typename T>
ForwardList<T>::iterator ForwardList<T>::begin() {
    return first;
}

template<typename T>
ForwardList<T>::iterator ForwardList<T>::end() {
    return after_end;
}

template<typename T>
ForwardList<T>::const_iterator ForwardList<T>::begin() const {
    return first;
}

template<typename T>
ForwardList<T>::const_iterator ForwardList<T>::end() const {
    return after_end;
}


namespace own::ds::linear {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, ForwardList<T> const& fl) {
        for (T cur_value: fl) os << cur_value << " ";
        os << std::endl;
        return os;
    }
}



template<typename T>
ListItem<T>::ListItem(T value, ListItem<T> *prev, ListItem<T> *next) : value(value), prev(prev), next(next) {}

template<typename T>
ListIterator<T>::ListIterator(ListItem<T> *it) : it(it) {}

template<typename T>
T& ListIterator<T>::operator*() {
    return it -> value;
}

template<typename T>
ListIterator<T> ListIterator<T>::operator++() {
    it = it -> next;
    return *this;
}

template<typename T>
ListIterator<T> ListIterator<T>::operator--() {
    it = it -> prev;
    return *this;
}

template<typename T>
bool ListIterator<T>::operator==(ListIterator<T> const& other) const {
    if (it == nullptr && other.it == nullptr) return true;
    if (it == nullptr || other.it == nullptr) return false;
    return it -> next == other.it -> next;
}


template<typename T>
List<T>::List() {
    first = last = after_end = ListIterator<T>(nullptr);
    cur_size = 0;
}

template<typename T>
size_t List<T>::size() const {
    return cur_size;
}

template<typename T>
void List<T>::insert_after(List<T>::iterator it, T value) {
    bool is_last = (it == last);
    ListItem<T> *tmp = new ListItem<T>(value, it.it, it.it -> next);
    if (it.it -> next != nullptr) it.it -> next -> prev = tmp;
    it.it -> next = tmp;
    if (is_last) {
        last = it.it -> next;
        after_end = ListIterator<T>(new ListItem<T>(0, last.it, nullptr));
        last.it -> next = after_end.it;
    }
    ++cur_size;
}

template<typename T>
void List<T>::insert_before(List<T>::iterator it, T value) {
    bool is_first = (it == first);
    bool is_last = (it == after_end);
    ListItem<T> *tmp = new ListItem<T>(value, it.it -> prev, it.it);
    if (it.it -> prev != nullptr) it.it -> prev -> next = tmp;
    it.it -> prev = tmp;
    if (is_first) first = it.it -> prev;
    if (is_last) {
        last = it.it -> prev;
        after_end = ListIterator<T>(new ListItem<T>(0, last.it, nullptr));
        last.it -> next = after_end.it;
    }
    ++cur_size;
}

template<typename T>
void List<T>::erase(List<T>::iterator it) {
    if (it.it == nullptr) return;
    if (it.it -> prev != nullptr) it.it -> prev -> next = it.it -> next;
    if (it.it -> next != nullptr) it.it -> next -> prev = it.it -> prev;
    delete it.it;
    --cur_size;
}

template<typename T>
void List<T>::push_front(T value) {
    if (cur_size == 0) {
        first = last = ListIterator<T>(new ListItem<T>(value, nullptr, nullptr));
        after_end = ListIterator<T>(new ListItem<T>(0, last.it, nullptr));
        last.it -> next = after_end.it;
    }
    else {
        ListItem<T> *tmp = new ListItem<T>(value, nullptr, first.it);
        first.it -> prev = tmp;
        first = ListIterator<T>(tmp);
    }
    ++cur_size;
}

template<typename T>
void List<T>::push_back(T value) {
    if (cur_size == 0) {
        last = first = ListIterator<T>(new ListItem<T>(value, nullptr, nullptr));
        after_end = ListIterator<T>(new ListItem<T>(0, last.it, nullptr));
        last.it -> next = after_end.it;
    }
    else {
        ListItem<T> *tmp = new ListItem<T>(value, last.it, nullptr);
        after_end = ListIterator<T>(new ListItem<T>(0, tmp, nullptr));
        tmp -> next = after_end.it;
        last.it -> next = tmp;
        last = ListIterator<T>(tmp);
    }
    ++cur_size;
}

template<typename T>
void List<T>::pop_front() {
    if (cur_size == 0) return;
    ListItem<T> *new_first = first.it -> next;
    delete first.it;
    first = ListIterator<T>(new_first);
    --cur_size;
}

template<typename T>
void List<T>::pop_back() {
    if (cur_size == 0) return;
    ListItem<T> *new_last = last.it -> prev;
    delete last.it;
    last = ListIterator<T>(new_last);
    --cur_size;
}

template<typename T>
List<T>::iterator List<T>::begin() {
    return first;
}

template<typename T>
List<T>::iterator List<T>::end() {
    // if (cur_size == 0) return last;
    // if (after_end.it -> prev != last.it) {
    //     after_end = ListIterator<T>(new ListItem<T>(0, last.it, nullptr));
    //     last.it -> next = after_end.it;
    // }
    return after_end;
}


template<typename T>
List<T>::const_iterator List<T>::begin() const {
    return first;
}

template<typename T>
List<T>::const_iterator List<T>::end() const {
    return after_end;
}


namespace own::ds::linear {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, List<T> const& lst) {
        auto it = lst.begin();
        for(size_t i = 0; i < lst.size(); ++i) {
            os << *it << " ";
            ++it;
        }
        // for (T cur_value: lst) os << cur_value << " ";
        os << std::endl;
        return os;
    }
}
