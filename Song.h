#ifndef SONG_H
#define SONG_H

#include "LinkedNode.h"

class Song: public LinkedNode {
    private:
        std::string artist;
        std::string title;
        float duration;
        int playCount;
        LinkedNode *next;

    public:
        Song();
        Song(const Song& songToCopy);
        ~Song();
        void setItem();
        *LinkedNode getItem();
        void setNext(LinkedNode* newNext);
        *LinkedNode getNext();
        std::string toString();

        std::string getArtist();
        void setArtist(std::string artist);
        std::string getArtist();
        std::string setTitle(std::string title);
        std::string getTitle();
        void setDuration(float duration);
        float getDuration();
        void setPlayCount(int playCount);
        int getPlayCount();
}

#endif
