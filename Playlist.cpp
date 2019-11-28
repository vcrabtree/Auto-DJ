#include "Playlist.h"
 
Playlist::Playlist(std::string newTitle) {
    initializeProperties(newTitle);
}

Playlist::Playlist(std::string newTitle, float newDuration, List& songs) {
    initializeProperties(newTitle);
    newRandom(newDuration, songs);
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

Song* Playlist::getSongAt(int index) {
    if (index == 0) return head->getItem();
    else if (index == length-1) return tail->getItem();
    else {
        LinkedNode<Song> *currNode = head;
        int i = 0;

        while (i < index) {
            currNode = currNode->getNext();
            i++;
        }
        if (currNode) return currNode->getItem();
        else return nullptr;
    }
}

Song* Playlist::playNext() {
   Song *song = removeFromFront();
   (*song)++;
   return song;
}

std::string Playlist::toString() {
    LinkedNode<Song> *currNode = head;
    std::string playlistString = "";

    while (currNode) {
        playlistString += currNode->getItem()->toString()+"\n\n";
        currNode = currNode->getNext();
    }
    return playlistString;
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

void Playlist::initializeProperties(std::string newTitle) {
    head = tail = nullptr;
    title = newTitle;
    duration = 0.0;
    length = 0;
}

void Playlist::newRandom(float newDuration, List& songs) {
    int listLength = songs.getLength(), 
        index = 0, 
        randIdx,
        *selected = new int[listLength]{0};
    float currDuration = 0.0, 
          sum = 0.0;
    Song *song;

    while (index < listLength && sum < newDuration) {
        randIdx = rand() % listLength;
        while (selected[randIdx]) randIdx = rand() % listLength;
        selected[randIdx] = 1;

        song = songs.getSongAt(randIdx);
        currDuration = song->getDuration();

        if ((currDuration + sum) <= newDuration) {
            add(song);
            sum += currDuration;
            std::cout << "sum: " << sum << std::endl;
        }
        index++;
    } 

    delete[] selected;
    selected = nullptr;
}

bool Playlist::isEmpty() { return !length; }

int Playlist::getLength() { return length; }

float Playlist::getDuration() { return duration; }

std::string Playlist::getTitle() { return title; }
