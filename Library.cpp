//
// Created by vcrab on 11/19/2019.
//

#include "Library.h"

Library::Library(int initialCapacity) {
    libraryList = new ArrayList(initialCapacity);
    duration = 0.0f;
}

Library::~Library() {
    delete[] libraryList;
}

void Library::sortLibrary() {
    //TODO
}

void Library::add(Song* song) { //Currently inserts at the end
    libraryList->add(song);
    duration += song->getDuration();
}

Song* Library::remove(std::string title, std::string artist) {
    return libraryList->remove(title, artist);
}

Song* Library::getSongAt(int index) {
    return libraryList->getSongAt(index);
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

std::string Library::toString() {
    std::string libraryString = "";
    for (int i = 0; i < libraryList->getLength(); i++) {
        libraryString += libraryList->getSongAt(i)->toString() + "\n\n";
    }
    return libraryString;
}

