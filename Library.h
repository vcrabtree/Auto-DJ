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
    float duration;

public:
    Library();

    ~Library();

    void add(Song* song, int index);

    Song* remove(std::string title, std::string artist);

    Song* getSongAt(int index);

    bool isEmpty();

    void clear();

    int getLength();

    float getDuration();

    int find(std::string title, std::string artist);
};
#endif //AUTO_DJ_LIBRARY_H
