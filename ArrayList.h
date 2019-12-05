//
// Created by vcrab on 12/3/2019.
//

#ifndef AUTO_DJ_ARRAYLIST_H
#define AUTO_DJ_ARRAYLIST_H

#include <string>
#include "List.h"

template <class T> class ArrayList : public List<T> {
private:
    T **arrayList;
    int currItemCount;
    int currCapacity;
    int duration;

    bool matches(T *item, std::string title, std::string artist);

    void doubleCapacity();

public:
    ArrayList(int initialCapacity);

    ~ArrayList();

    void add(T* item);

    T* remove(std::string title, std::string artist="");

    bool isEmpty();

    void clear();

    int getLength();

    int find(std::string title, std::string artist="");

    T* getItemAt(int index);
};

#include "ArrayList.inl"

#endif //AUTO_DJ_ARRAYLIST_H
