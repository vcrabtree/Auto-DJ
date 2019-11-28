#ifndef PLAYLIST_LIST_H
#define PLAYLIST_LIST_H

#include <stdexcept>
#include <string>
#include "Playlist.h"

class PlaylistList {
    public:
        PlaylistList() {}

        virtual ~PlaylistList() {}

        virtual void add(Playlist* playlist, int index=-1) = 0;

        virtual Playlist* remove(std::string title) = 0;

        virtual bool isEmpty() = 0;

        virtual void clear() = 0;

        virtual void getLength() = 0;

        virtual int find(std::string title) = 0;

        virtual Playlist* getPlaylistAt(int index) = 0;
};

#endif 
