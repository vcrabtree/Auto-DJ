#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <iostream>
#include <string>

class LinkedNode {
    public:
        virtual void setItem()=0;
        virtual *LinkedNode getItem()=0;
        virtual void setNext(LinkedNode* newNext)=0;
        virtual *LinkedNode getNext()=0;
        virtual std::string toString()=0;
};
#endif
