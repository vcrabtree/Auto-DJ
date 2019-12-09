//
// Created by vcrab on 11/19/2019.
//

#include "Library.h"

Library::Library(int initialCapacity) {
    libraryList = new ArrayList<Song>(initialCapacity);
    duration = 0.0f;
}

Library::~Library() {
    delete libraryList;
}

void Library::sortLibrary() {
    // Compare libraryList artists
    // Takes first artist in list, sorts through entire list to find where is would go alphabetically
    // Takes second artist and sorts through entire list to again find where it belongs alphabetically
    // Does this with all artists in list
    // If artist is equivalent to another artist, compare songs by artist and order alphabetically by song
    // Repeats sort logic with song
}

void Library::add(Song* song) { //Currently inserts at the end
    libraryList->add(song);
    duration += song->getDuration();
}

Song* Library::remove(std::string title, std::string artist) {
    return libraryList->remove(title, artist);
}

Song* Library::getSongAt(int index) {
    return libraryList->getItemAt(index);
}

bool Library::isEmpty() {
    return libraryList->isEmpty();
}

void Library::clear() {
    duration = 0;
    libraryList->clear();
}

int Library::getLength() {
    return libraryList->getLength();
}

float Library::getDuration() {
    return duration;
}

int Library::find(std::string title, std::string artist) {
    return libraryList->find(title, artist);
}

std::string Library::findByArtist(std::string artist) {
    std::string songString = "";
    for (int i = 0; i < libraryList->getLength(); i++) {
        if (libraryList->getItemAt(i)->getArtist() == artist) {
            songString += libraryList->getItemAt(i)->getTitle() + "\n";
        }
    }
    return songString;
}

std::string Library::toString() {
    std::string libraryString = "";
    for (int i = 0; i < libraryList->getLength(); i++) {
        libraryString += libraryList->getItemAt(i)->toString() + "\n\n";
    }
    return libraryString;
}

