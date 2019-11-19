#ifndef LINKEDNODE_H
#define LINKEDNODE_H

template <class T> class LinkedNode {
    private:
        T *item;
        LinkedNode<T> *next;

    public:
        LinkedNode(const T& item);
        LinkedNode(const LinkedNode& nodeToCopy);

        void setItem();
        T* getItem();
        void setNext(LinkedNode* newNext);
        LinkedNode<T*> getNext();
};
#endif
