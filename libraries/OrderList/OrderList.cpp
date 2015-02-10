/* Copyright 2015 ToxaKniotee */
#ifndef ORDER_LIST_H
#define ORDER_LIST_H

#include <cstddef>

template <typename T>
struct Node {
    T item;
    Node<T> *next;
};

template <typename T>
class OrderList {
    public:
        OrderList();
        bool add(T new_item);
        int size();
        T operator[](int index);

    protected:
        Node<T> *_first, *_last;
        int _size;

        Node<T>* create_node(T new_item);
        Node<T>* create_node(T new_item, Node<T> *next);
};

template <typename T>
OrderList<T>::OrderList() {
    _first = NULL;
    _size = 0;
}

template <typename T>
bool OrderList<T>::add(T new_item) {
    if (_first == NULL) {
        _first = create_node(new_item);
        _last = _first;
        _size++;
        return true;
    } else if (new_item < _first->item) {
        _first = create_node(new_item, _first);
        _size++;
        return true;
    }

    Node<T> *temp = _first->next, *prev = _first;
    while (temp != NULL) {
        if (new_item == temp->item) {
            return false;
        } else if (new_item > temp->item) {
            prev = temp;
            temp = temp->next;
        } else {
            prev->next = create_node(new_item, temp);
            _size++;
            return true;
        }
    }
    prev->next = create_node(new_item);
    _size++;
    return true;
}

template <typename T>
int OrderList<T>::size() {
    return _size;
}

template <typename T>
T OrderList<T>::operator[](int index) {
    Node<T> *temp = _first;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->item;
}

template <typename T>
Node<T>* OrderList<T>::create_node(T new_item) {
    Node<T> *temp = new Node<T>;
    temp->item = new_item;
    temp->next = NULL;
    return temp;
}

template <typename T>
Node<T>* OrderList<T>::create_node(T new_item, Node<T> *next) {
    Node<T> *temp = new Node<T>;
    temp->item = new_item;
    temp->next = next;
    return temp;
}


#endif
