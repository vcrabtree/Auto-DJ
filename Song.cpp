#include "Song.h"

Song::Song(std::string newTitle, std::string newArtist, float newDuration) {
    artist = newArtist;
    title = newTitle;
    duration = newDuration;
    playCount = 0;
    playlistsHead = playlistsTail = nullptr;
}

Song Song::operator++(int) {
    Song temp = *this;
    ++playCount;
    return temp;
}

void Song::setArtist(std::string newArtist) { artist = newArtist; }

std::string Song::getArtist() { return artist; }

void Song::setTitle(std::string newTitle) { title = newTitle; }

std::string Song::getTitle() { return title; }

void Song::setDuration(float newDuration) { duration = newDuration; }

float Song::getDuration() { return duration; }

void Song::setPlayCount(int newPlayCount) { playCount = newPlayCount; }

int Song::getPlayCount() { return playCount; }

std::string Song::toString() {
    return 
        "artist:\t\t"        +artist+
        "\ntitle:\t\t"       +title+
        "\nduration:\t"    +std::to_string(duration)+
        "\nplay count:\t"  +std::to_string(playCount);
}

void Song::add(Playlist *playlist) {
    if (!playlistsHead) {
        playlistsHead = playlistsTail = new LinkedNode<Playlist>(*playlist);
    } else {
        LinkedNode<Playlist> *newNode = new LinkedNode<Playlist>(*playlist);
        playlistsTail->setNext(newNode);
        playlistsTail = newNode; 
    } 
} 

void Song::remove(Playlist *playlist) {
    if (playlist == playlistsHead->getItem()) removeFromFront();
    else if (playlist == playlistsTail->getItem()) removeFromEnd();
    else {
        LinkedNode<Playlist> *currNode = playlistsHead, *nextNode = playlistsHead->getNext();

        while (nextNode && nextNode->getItem() != playlist) {
            currNode = nextNode;
            nextNode = nextNode->getNext();
        }
        currNode->setNext(nextNode->getNext());
        delete nextNode;
    }
}

void Song::removeFromFront() {
    LinkedNode<Playlist> *prevHead = playlistsHead;
    playlistsHead = playlistsHead->getNext();

    delete prevHead;
}

void Song::removeFromEnd() {
    LinkedNode<Playlist> *currNode = playlistsHead, *nextNode = playlistsHead->getNext();

    while (currNode->getNext() && nextNode->getNext()) {
        currNode = currNode->getNext();
        nextNode = nextNode->getNext();
    }
    delete nextNode;
    currNode->setNext(nullptr);
    playlistsTail = currNode;
}

LinkedNode<Playlist>* Song::getExistingPlaylists() {
    return playlistsHead;
}

