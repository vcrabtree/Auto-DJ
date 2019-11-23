#include "LinkedNode.h"

template <class T>
LinkedNode<T>::LinkedNode(T& newItem) {
    item = &newItem;
    next = nullptr;
}

template <class T>
void LinkedNode<T>::setItem(T& newItem) { item = &newItem; }

template <class T>
T* LinkedNode<T>::getItem() { return item; }

template <class T>
void LinkedNode<T>::setNext(LinkedNode* newNext) { next = newNext; }

template <class T>
LinkedNode<T>* LinkedNode<T>::getNext() { return next; }
