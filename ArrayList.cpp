//
// Created by vcrab on 12/4/2019.
//

#include "ArrayList.h"

ArrayList::ArrayList(int initialCapacity) {
    if (initialCapacity >= 1) {
        this->arrayList = new Song*[initialCapacity];
        this->currItemCount = 0;
        this->currCapacity = initialCapacity;
        int duration = 0;
    }
    else {
        throw std::invalid_argument("Array list capacity cannot be less than 1");
    }
}

ArrayList::~ArrayList() {
    for (int i = 0; i < currItemCount; i++) delete arrayList[i];
    delete[] arrayList;
}

void ArrayList::doubleCapacity() {
    int newCapacity = currCapacity * 2;
    Song **newArray = new Song*[newCapacity];
    for (int i = 0; i < currCapacity; i ++) {
        newArray[i] = arrayList[i];
    }
    delete[] arrayList;
    arrayList = newArray;
    currCapacity = newCapacity;
}

void ArrayList::add(Song* song) { //Currently inserts at the end
    if (currItemCount < currCapacity) {
        arrayList[currItemCount] = song;
        currItemCount++;
    }
    else {
        doubleCapacity();
        arrayList[currItemCount] = song;
        currItemCount++;
    }
}

Song* ArrayList::remove(std::string title, std::string artist) {
    int songToRemoveIndex = find(title, artist);
    if (currItemCount == 0) {
        throw std::out_of_range ("There are no items in this array list");
    } else if (songToRemoveIndex > -1) {
        Song* songToRemove = arrayList[songToRemoveIndex];
        for (int i = songToRemoveIndex; i <= currItemCount; i++) {
            arrayList[i] = arrayList[i + 1];
        }
        currItemCount--;
        return songToRemove;
    } else throw std::out_of_range ("There is no song with this title and artist");
}

Song* ArrayList::getSongAt(int index) {
    if (index < 0) {
        throw std::out_of_range ("There is no song at this index");
    }
    else if (index < currItemCount) {
        return arrayList[index];
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

int ArrayList::find(std::string title, std::string artist) {
    for (int i = 0; i < currItemCount; i++) {
        if (arrayList[i]->getTitle() == title && arrayList[i]->getArtist() == artist) {
            return i;
        }
    }
    return -1;
}

