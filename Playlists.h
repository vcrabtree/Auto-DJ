#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "PlaylistList.h"

class Playlists: public PlaylistList {
    private:
        LinkedNode<Playlist> *head, *tail;
        int length;

    public:
        Playlists();
        ~Playlists();

        void add(Playlist* song, int index);
        Playlist* remove(std::string title);
        bool isEmpty();
        void clear();
        int getLength();
        int find(std::string searchKey);
};

#endif
