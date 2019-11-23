#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "List.h"
#include "LinkedNode.h"
#include "Song.h"
#include <iostream>

class Playlist: public List {
    private:
        LinkedNode<Song> *head, *tail;
        std::string title;
        float duration;
        int length;

    public:
        Playlist(std::string title);
        ~Playlist();
        Playlist& operator=(const List& listToCopy);

        void add(Song* song, int index);
        Song* remove(std::string title);
        bool isEmpty();
        void clear();
        int getLength();
        float getDuration();
        int find(std::string searchKey);
};
#endif
