//
// Created by vcrab on 12/3/2019.
//

#ifndef AUTO_DJ_ARRAYLIST_H
#define AUTO_DJ_ARRAYLIST_H

#include <string>
#include "List.h"

class ArrayList : public List {
private:
    int* arrayList;
    int currItemCount;
    int currCapacity;

    void doubleCapacity();

public:
    ArrayList(int initialCapacity);

    ~ArrayList();

    virtual void add(Song* song, int index=-1) = 0;

    virtual Song* remove(std::string title, std::string artist) = 0;

    virtual bool isEmpty() = 0;

    virtual void clear() = 0;

    virtual int getLength() = 0;

    virtual int find(std::string title, std::string artist) = 0;

    virtual Song* getSongAt(int index) = 0;

    virtual std::string toString() = 0;
};

#endif //AUTO_DJ_ARRAYLIST_H
