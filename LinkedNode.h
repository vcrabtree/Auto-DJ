#ifndef LINKEDNODE_H
#define LINKEDNODE_H

template <class T> class LinkedNode {
    private:
        T *item;
        LinkedNode<T> *next;

    public:
        LinkedNode(T& item);
        LinkedNode(const LinkedNode& nodeToCopy);

        void setItem(T& item);
        T* getItem();
        void setNext(LinkedNode* newNext);
        LinkedNode<T>* getNext();
};

#include "LinkedNode.inl"

#endif
