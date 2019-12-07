#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "LinkedQueue.h"
#include "LinkedNode.h"
#include "Library.h"
#include "Song.h"
#include <iostream>

class Playlist {
    private:
        LinkedQueue<Song> *songs;
        std::string title;
        float duration;
        void initializeProperties(std::string newTitle);
        void newRandom(float duration, Library& library);

    public:
        Playlist(std::string title);
        Playlist(std::string title, float duration, Library& library);
        ~Playlist();

        void add(Song* song, int index=-1);
        Song* remove(std::string title, std::string artist);
        bool isEmpty();
        void clear();
        int getLength();
        float getDuration();
        std::string getTitle();
        std::string getArtist();
        int find(std::string title, std::string artist);
        Song* playNext();
        std::string toString();
};
#endif
