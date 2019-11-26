//
// Created by vcrab on 11/19/2019.
//

#ifndef AUTO_DJ_LIBRARY_H
#define AUTO_DJ_LIBRARY_H

#include "List.h"
#include "Song.h"
#include "LinkedNode.h"

class Library : public List {
private:
    LinkedNode<Song> *front;
    LinkedNode<Song> *end;

public:
    Library();

    ~Library();

    Library(const Library& libraryToCopy);

    Library& operator=(const Library& libraryToCopy);

    void add(Song* song, int index);

    Song remove(int index);

    bool isEmpty();

    void clear();

    int getLength();

    int find(Song song);
};
#endif //AUTO_DJ_LIBRARY_H
