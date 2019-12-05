//
// Created by vcrab on 12/3/2019.
//

#ifndef AUTO_DJ_ARRAYLIST_H
#define AUTO_DJ_ARRAYLIST_H

#include <string>
#include "List.h"

class ArrayList : public List {
private:
    Song* arrayList;
    int currItemCount;
    int currCapacity;
    int duration;

    void doubleCapacity();

public:
    ArrayList(int initialCapacity);

    ~ArrayList();

    void add(Song* song);

    Song* remove(std::string title, std::string artist);

    bool isEmpty();

    void clear();

    int getLength();

    float getDuration();

    int find(std::string title, std::string artist);

    Song* getSongAt(int index);

    std::string toString();
};

#endif //AUTO_DJ_ARRAYLIST_H
