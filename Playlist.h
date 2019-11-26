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

        Song* removeFromFront();
        Song* removeFromEnd();
        void decrease(float duration);
        void copy(const Playlist& playlistToCopy);

    public:
        Playlist(std::string title);
        ~Playlist();
        Playlist(const Playlist& playlistToCopy);
        Playlist& operator=(const Playlist& playlistToCopy);

        void add(Song* song, int index=-1);
        Song* remove(std::string title);
        bool isEmpty();
        void clear();
        int getLength();
        float getDuration();
        std::string getTitle();
        int find(std::string songTitle);
};
#endif
