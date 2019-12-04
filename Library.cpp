//
// Created by vcrab on 11/19/2019.
//

#include "Library.h"

Library::Library() {
    if (initialCapacity >= 1) {
        this->arrayList = new Song[initialCapacity];
        this->currItemCount = 0;
        this->currCapacity = initialCapacity;
        int duration = 0;
    }
    else {
        throw std::invalid_argument("Library Capacity cannot be less than 1");
    }
}

Library::~Library() {
    delete[] arrayList;
}

void ArrayList::doubleCapacity() {
    int newCapacity = currCapacity * 2;
    Song* newArray = new Song[newCapacity];
    for (int i = 0; i < currCapacity; i ++) {
        newArray[i] = arrayList[i];
    }
    delete[] arrayList;
    arrayList = newArray;
    currCapacity = newCapacity;
}

void Library::add(Song* song) { //Currently inserts at the end
    if (currItemCount < currCapacity) {
        arrayList[currItemCount] = *song;
        currItemCount++;
        duration = duration + song->getDuration();
    }
    else {
        doubleCapacity();
        arrayList[currItemCount] = *song;
        currItemCount++;
        duration = duration + song->getDuration();
    }
}

Song* Library::remove(std::string title, std::string artist) {
    if (currItemCount <= 0) {
        throw std::out_of_range ("There are no items in this library");
    }
    else {
        int songToRemoveIndex = find(title, artist);
        Song* songToRemove = arrayList[songToRemoveIndex];
        for (int i = songToRemoveIndex; i <= currItemCount; i++) {
            arrayList[i] = arrayList[i + 1];
        }
        currItemCount--;
        duration = duration - songToRemove->getDuration();
        return songToRemove;
    }
}

Song* Library::getSongAt(int index) {
    if (index < 0) {
        throw std::out_of_range ("There is no song at this index");
    }
    else if (index < currItemCount) {
        return *arrayList[index];
    }
    else {
        throw std::out_of_range ("There is no song at this index");
    }
}

bool Library::isEmpty() {
    if (currItemCount == 0) {
        return true;
    }
    else {
        return false;
    }
}

void Library::clear() {
    currItemCount = 0;
}

int Library::getLength() {
    return currItemCount;
}

float Library::getDuration() {
    return duration;
}

int Library::find(std::string title, std::string artist) {
    for (int i = 0; i < currItemCount; i++) {
        if (arrayList[i].getTitle() == title && arrayList[i].getArtist() == artist) {
            return i;
        }
    }
    return -1;
}

std::string Library::toString() {
    std::string libraryString;
    for (int i = 0; i < currItemCount; i++) {
        libraryString = libraryString + (arrayList[i].getTitle()) + " by "
                + (arrayList[i].getArtist()) + "\n";
    }
    return libraryString;
}

