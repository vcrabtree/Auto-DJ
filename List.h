//
// Created by vcrab on 11/19/2019.
//

#ifndef AUTO_DJ_LIST_H
#define AUTO_DJ_LIST_H

#include <stdexcept>
#include <string>
#include "Song.h"

template <typename T> class List {
public:
    List() {}

    virtual ~List() {}

    List(const List& listToCopy);

    virtual List& operator=(const List& listToCopy) {}

    virtual void add(T* item) = 0;

    virtual T* remove(std::string title, std::string artist="") = 0;

    virtual bool isEmpty() = 0;

    virtual void clear() = 0;

    virtual int getLength() = 0;

    virtual int find(std::string title, std::string artist="") = 0;

    virtual T* getItemAt(int index) = 0;
};

#endif //AUTO_DJ_LIST_H
