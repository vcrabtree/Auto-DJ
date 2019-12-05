//
// Created by vcrab on 11/19/2019.
//

#ifndef AUTO_DJ_LIBRARY_H
#define AUTO_DJ_LIBRARY_H

#include "ArrayList.h"
#include "Song.h"

class Library : public ArrayList {
private:
    ArrayList libraryList;

public:
    Library(int initialCapacity);

    ~Library();

    void add(Song* song);

    Song* remove(std::string title, std::string artist);

    Song* getSongAt(int index);

    bool isEmpty();

    void clear();

    int getLength();

    float getDuration();

    int find(std::string title, std::string artist);

    std::string toString();
};
#endif //AUTO_DJ_LIBRARY_H
