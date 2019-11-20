#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "List.h"
#include "LinkedNode.h"
#include "Song.h"

class Playlist: public List {
    private:
        LinkedNode<Song> *head, *tail;
        int length;

    public:
        void add(Song* song, int index);
        Song* remove(std::string title);
        bool isEmpty();
        void clear();
        int getLength();
        int find(std::string searchKey);
}
#endif
