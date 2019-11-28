#include "Playlists.h"

Playlists::Playlists() {
    head = tail = nullptr;
    length = 0;
}

Playlists::~Playlists() { clear(); }

void Playlists::add(Playlist* playlist, int index) {
    if (isEmpty()) head = tail = new LinkedNode<Playlist>(*playlist);
    else {
        LinkedNode<Playlist> *newNode = new LinkedNode<Playlist>(*playlist);
        tail->setNext(newNode);
        tail = newNode;
    }
    length++;
}

Playlist* Playlists::remove(std::string title) {
    if (isEmpty()) throw std::out_of_range("playlist is empty");

    Playlist* playlist;
    std::string  firstTitle = head->getItem()->getTitle(),
                 lastTitle = tail->getItem()->getTitle();

    if (firstTitle == title) playlist = removeFromFront();
    else if (lastTitle == title) playlist = removeFromEnd();
    else {
        LinkedNode<Playlist> *currNode = head, *nextNode = head->getNext();
        playlist = nextNode->getItem();
        while (nextNode && playlist->getTitle() != title) {
            currNode = nextNode;
            nextNode = nextNode->getNext();
        }

        if (!nextNode) playlist = nullptr;
        else {
            playlist = nextNode->getItem();
            currNode->setNext(nextNode->getNext());
            delete nextNode;
            length--;
        }
    }

    return playlist;
}

Playlist* Playlists::removeFromFront() {
    Playlist *playlist = head->getItem();
    LinkedNode<Playlist> *prevHead = head;

    delete prevHead;
    head = head->getNext();
    length--;

    return playlist;
}

Playlist* Playlists::removeFromEnd() {
    LinkedNode<Playlist> *currNode = head, *nextNode = head->getNext();
    Playlist *playlist = tail->getItem();

    while (currNode->getNext() && nextNode->getNext()) {
        currNode = currNode->getNext();
        nextNode = nextNode->getNext();
    }
    delete nextNode;
    currNode->setNext(nullptr);
    tail = currNode;
    length--;

    return playlist;
}


int Playlists::find(std::string title) {
    LinkedNode<Playlist> *currNode = head;
    Playlist* playlist;
    int index = 0, indexFound = -1;

    while (index < length && indexFound == -1) {
        playlist = currNode->getItem();

        if (playlist->getTitle() == title) 
            indexFound = index;

        currNode = currNode->getNext();
        index++;
    }
    return indexFound;
}

Playlist* Playlists::getPlaylistAt(int index) {
    if (index == 0) return head->getItem();
    else if (index == length-1) return tail->getItem();
    else {
        LinkedNode<Playlist> *currNode = head;
        int i = 0;

        while (i < index) {
            currNode = currNode->getNext();
            i++;
        }
        if (currNode) return currNode->getItem();
        else return nullptr;
    }
}

std::string Playlists::toString() {
    LinkedNode<Playlist> *currNode = head;
    std::string playlistsString = "";

    while (currNode) {
        playlistsString += currNode->getItem()->getTitle()+"\n\n";
        currNode = currNode->getNext();
    }
    return playlistsString;
}

std::string Playlists::displayPlaylist(std::string title) {
    Playlist *playlist = nullptr;
    std::string  firstTitle = head->getItem()->getTitle(),
                 lastTitle = tail->getItem()->getTitle(),
                 playlistString = "";

    if (firstTitle == title) playlist = removeFromFront();
    else if (lastTitle == title) playlist = removeFromEnd();
    else {
        LinkedNode<Playlist> *currNode = head;
        while (currNode && currNode->getItem()->getTitle() != title) {
            currNode = currNode->getNext();
        }

        if (currNode) playlist = currNode->getItem();
    }
    if (playlist) playlistString = playlist->toString();

    return playlistString;
}

void Playlists::clear() {
    while (!isEmpty()) removeFromFront();
};

bool Playlists::isEmpty() { return !length; }

int Playlists::getLength() { return length; }
