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
        Playlist* getPlaylistAt(int index);
        Playlist* getPlaylist(std::string title);
        std::string playlistString(std::string title);
        std::string allPlaylistsString();
        std::string toFileString();
};

#endif
