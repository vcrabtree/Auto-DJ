//
// Created by vcrab on 12/4/2019.
//

#include "ArrayList.h"

ArrayList::ArrayList(int initialCapacity) {
    if (initialCapacity >= 1) {
        this->arrayList = new int[initialCapacity];
        this->currItemCount = 0;
        this->currCapacity = initialCapacity;
        int duration = 0;
    }
    else {
        throw std::invalid_argument("Array list capacity cannot be less than 1");
    }
}

ArrayList::~ArrayList() {
    delete[] arrayList;
}

void ArrayList::doubleCapacity() {
    int newCapacity = currCapacity * 2;
    Song* newArray = new int[newCapacity];
    for (int i = 0; i < currCapacity; i ++) {
        newArray[i] = arrayList[i];
    }
    delete[] arrayList;
    arrayList = newArray;
    currCapacity = newCapacity;
}

void ArrayList::add(Song* song) { //Currently inserts at the end
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

Song* ArrayList::remove(std::string title, std::string artist) {
    if (currItemCount <= 0) {
        throw std::out_of_range ("There are no items in this array list");
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

Song* ArrayList::getSongAt(int index) {
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

bool ArrayList::isEmpty() {
    if (currItemCount == 0) {
        return true;
    }
    else {
        return false;
    }
}

void ArrayList::clear() {
    currItemCount = 0;
}

int ArrayList::getLength() {
    return currItemCount;
}

float ArrayList::getDuration() {
    return duration;
}

int ArrayList::find(std::string title, std::string artist) {
    for (int i = 0; i < currItemCount; i++) {
        if (arrayList[i].getTitle() == title && arrayList[i].getArtist() == artist) {
            return i;
        }
    }
    return -1;
}

std::string ArrayList::toString() {
    std::string libraryString;
    for (int i = 0; i < currItemCount; i++) {
        libraryString = libraryString + (arrayList[i].getTitle()) + " by "
                        + (arrayList[i].getArtist()) + "\n";
    }
    return libraryString;
}

