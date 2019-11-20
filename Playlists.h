#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playlist.h"

class Playlists: public list {
    private:
        LinkedNode<Playlist> *head, *tail;
        int length;

    public:
        void add(Playlist* song, int index);
        Playlist* remove(std::string title);
        bool isEmpty();
        void clear();
        int getLength();
        int find(std::string searchKey);

}

#endif
