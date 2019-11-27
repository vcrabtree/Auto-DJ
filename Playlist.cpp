#include "Playlist.h"
 
Playlist::Playlist(std::string newTitle) {
    head = tail = nullptr;
    title = newTitle;
    duration = 0.0;
    length = 0;
}

Playlist::~Playlist() { clear(); }

Playlist::Playlist(const Playlist& playlistToCopy) { copy(playlistToCopy); }

Playlist& Playlist::operator=(const Playlist& playlistToCopy) {
    copy(playlistToCopy);
    return *this;
}

void Playlist::add(Song *song, int index){
    if (isEmpty()) head = tail = new LinkedNode<Song>(*song);
    else {
        LinkedNode<Song> *newNode = new LinkedNode<Song>(*song);
        tail->setNext(newNode);
        tail = newNode;
    }
    duration += song->getDuration();
    length++;
}

Song* Playlist::remove(std::string title, std::string artist) {
    if (isEmpty()) throw std::out_of_range("playlist is empty");

    Song* song;
    std::string  firstTitle = head->getItem()->getTitle(),
                 lastTitle = tail->getItem()->getTitle();

    if (firstTitle == title) song = removeFromFront();
    else if (lastTitle == title) song = removeFromEnd();
    else {
        LinkedNode<Song> *currNode = head, *nextNode = head->getNext();
        song = nextNode->getItem();
        while (nextNode && song->getTitle() != title && song->getArtist() != artist) {
            currNode = nextNode;
            nextNode = nextNode->getNext();
        }

        if (!nextNode) song = nullptr;
        else {
            song = nextNode->getItem();
            currNode->setNext(nextNode->getNext());
            delete nextNode;
            decrease(song->getDuration());
        }
    }

    return song;
}

Song* Playlist::removeFromFront() {
    Song *song = head->getItem();
    LinkedNode<Song> *prevHead = head;

    delete prevHead;
    head = head->getNext();
    decrease(song->getDuration());

    return song;
}

Song* Playlist::removeFromEnd() {
    LinkedNode<Song> *currNode = head, *nextNode = head->getNext();
    Song *song = tail->getItem();

    while (currNode->getNext() && nextNode->getNext()) {
        currNode = currNode->getNext();
        nextNode = nextNode->getNext();
    }
    delete nextNode;
    currNode->setNext(nullptr);
    tail = currNode;
    decrease(song->getDuration());

    return song;
}

int Playlist::find(std::string title, std::string artist) {
    LinkedNode<Song> *currNode = head;
    Song* song;
    int index = 0, indexFound = -1;

    while (index < length && indexFound == -1) {
        song = currNode->getItem();

        if (song->getTitle() == title && song->getArtist() == artist) 
            indexFound = index;

        currNode = currNode->getNext();
        index++;
    }
    return indexFound;
}

Song* Playlist::playNext() {
   Song *song = removeFromFront();
   (*song)++;
   return song;
}

void Playlist::copy(const Playlist& playlistToCopy) {
    LinkedNode<Song> *currNode = playlistToCopy.head;
    while (length != playlistToCopy.length) {
        add(currNode->getItem());
        currNode = currNode->getNext();
    }
}

void Playlist::clear() {
    while (!isEmpty()) removeFromFront();
}

void Playlist::decrease(float songDuration) {
    length--;
    duration -= songDuration;
}

bool Playlist::isEmpty() { return !length; }

int Playlist::getLength() { return length; }

float Playlist::getDuration() { return duration; }

std::string Playlist::getTitle() { return title; }
