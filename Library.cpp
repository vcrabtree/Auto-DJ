//
// Created by vcrab on 11/19/2019.
//

#include "Library.h"

Library::Library(int initialCapacity) {
    ArrayList libraryList = new ArrayList(initialCapacity);
}

Library::~Library() {
    delete[] libraryList;
}

void Library::doubleCapacity() {
    libraryList.doubleCapacity();
}

void Library::add(Song* song) { //Currently inserts at the end
    libraryList.add(song);
}

Song* Library::remove(std::string title, std::string artist) {
    return libraryList.remove(title, artist);
}

Song* Library::getSongAt(int index) {
    return libraryList.getSongAt(index);
}

bool Library::isEmpty() {
    return libraryList.isEmpty();
}

void Library::clear() {
    libraryList.clear();
}

int Library::getLength() {
    return libraryList.getLength();
}

float Library::getDuration() {
    return libraryList.getDuration();
}

int Library::find(std::string title, std::string artist) {
    return libraryList.find(title, artist);
}

std::string Library::toString() {
    return libraryList.toString();
}

