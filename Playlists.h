#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "PlaylistList.h"

class Playlists: public PlaylistList {
    private:
        LinkedNode<Playlist> *head, *tail;
        int length;

        Playlist* removeFromFront();
        Playlist* removeFromEnd();

    public:
        Playlists();
        ~Playlists();

        void add(Playlist* song, int index);
        Playlist* remove(std::string title);
        bool isEmpty();
        void clear();
        int getLength();
        Playlist* getPlaylistAt(int index);
        int find(std::string searchKey);
        std::string toString();
        std::string displayPlaylist(std::string title);
};

#endif
