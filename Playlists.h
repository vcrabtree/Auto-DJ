#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "ArrayList.h"
#include "Playlist.h"

class Playlists {
    private:
        ArrayList<Playlist> *playlistList;

    public:
        Playlists(int initialCapacity);
        ~Playlists();

        void add(Playlist* playlist);
        Playlist* remove(std::string title);
        bool isEmpty();
        void clear();
        int getLength();
        int find(std::string title);
        std::string displayPlaylist(std::string title);
        std::string displayAllPlaylists();
};

#endif
