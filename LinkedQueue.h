#ifndef AUTO_DJ_LINKED_QUEUE_H
#define AUTO_DJ_LINKED_QUEUE_H

#include "Queue.h"
#include "LinkedNode.h"

template <class T> class LinkedQueue: public Queue<T> {
    private:
        LinkedNode<T> *head, *tail;

        int length;

        T* removeFromEnd();

        bool matches(T *item, std::string title, std::string artist="");

    public:
        LinkedQueue();

        ~LinkedQueue();
        
        void enqueue(T *item);

        T* dequeue();

        T* remove(std::string title, std::string artist="");

        void empty();

        bool isEmpty();

        int getLength();

        std::string toString();

        int find(std::string title, std::string artist);

};

#include "LinkedQueue.inl"

#endif
