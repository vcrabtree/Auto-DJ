#include "Playlist.h"
 
Playlist::Playlist(std::string newTitle) {
    initializeProperties(newTitle);
}

Playlist::Playlist(std::string newTitle, float newDuration, Library& songs) {
    initializeProperties(newTitle);
    newRandom(newDuration, songs);
}

Playlist::~Playlist() { clear(); }

void Playlist::add(Song *song, int index){
    songs->enqueue(song);
    duration += song->getDuration();
    length++;
}

Song* Playlist::remove(std::string title, std::string artist) { 
    Song *song = songs->remove(title, artist); 
    decrease(song->getDuration());
    return song;
}

int Playlist::find(std::string title, std::string artist) { return songs->find(title, artist); }

std::string Playlist::toString() { return songs->toString(); }

Song* Playlist::playNext() {
    if (isEmpty()) throw std::out_of_range("playlist is empty");
    Song *song = songs->dequeue();
    (*song)++;
    return song;
}

void Playlist::clear() {
    while (!isEmpty()) songs->dequeue();
    duration = 0.0f;
    length = 0;
}

void Playlist::decrease(float songDuration) {
    length--;
    duration -= songDuration;
}

void Playlist::initializeProperties(std::string newTitle) {
    songs = new LinkedQueue<Song>();
    title = newTitle;
    duration = 0.0;
    length = 0;
}

void Playlist::newRandom(float newDuration, Library& library) {
    if (newDuration <= 0) throw std::invalid_argument("invalid duration");
    int listLength = library.getLength(), 
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

        song = library.getSongAt(randIdx);
        currDuration = song->getDuration();

        if ((currDuration + sum) <= newDuration) {
            add(song);
            sum += currDuration;
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

std::string Playlist::getArtist() { return ""; }


