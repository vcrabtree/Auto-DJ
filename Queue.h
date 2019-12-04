#ifndef AUTO_DJ_QUEUE_H
#define AUTO_DJ_QUEUE_H

#include <string>
#include <stdexcept>

template <typename T> class Queue {
    public:
        Queue() {}

        virtual ~Queue() {}

        virtual void enqueue(T *item) = 0;

        virtual T* dequeue() = 0;

        virtual void empty() = 0;

        virtual bool isEmpty()=  0;
};

#endif
