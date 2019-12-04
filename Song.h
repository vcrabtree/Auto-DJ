#ifndef SONG_H
#define SONG_H

#include <iostream>
#include "LinkedNode.h"

class Playlist;

class Song {
    private:
        std::string artist;
        std::string title;
        float duration;
        int playCount;

    public:
        Song(std::string newTitle, std::string newArtist, float newDuration);
        Song operator++(int);

        void setArtist(std::string newArtist);
        std::string getArtist();
        void setTitle(std::string newTitle);
        std::string getTitle();
        void setDuration(float newDuration);
        float getDuration();
        void setPlayCount(int newPlayCount);
        int getPlayCount();
        std::string toString();
};

#endif
