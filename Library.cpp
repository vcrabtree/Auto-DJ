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
    for (int i = 0; i < libraryList->getLength(); i++) {
        std::string minValue = libraryList->getItemAt(i)->getArtist();
        std::string minSong = libraryList->getItemAt(i)->getTitle();
        int minIndex = i;
        for (int a = i; a < libraryList->getLength(); a++) {
            if (libraryList->getItemAt(a)->getArtist() < minValue) {
                minValue = libraryList->getItemAt(a)->getArtist();
                minSong = libraryList->getItemAt(a)->getTitle();
                minIndex = a;
            }
            else if (libraryList->getItemAt(a)->getArtist() == minValue) {
                if (libraryList->getItemAt(a)->getTitle() < minSong) {
                    minValue = libraryList->getItemAt(a)->getArtist();
                    minSong = libraryList->getItemAt(a)->getTitle();
                    minIndex = a;
                }
            }
        }
        std::string tempTitle = libraryList->getItemAt(minIndex)->getTitle();
        std::string tempArtist = libraryList->getItemAt(minIndex)->getArtist();
        float tempDuration = libraryList->getItemAt(minIndex)->getDuration();
        int tempPlayCount = libraryList->getItemAt(minIndex)->getPlayCount();
        libraryList->getItemAt(minIndex)->setTitle(libraryList->getItemAt(i)->getTitle());
        libraryList->getItemAt(minIndex)->setArtist(libraryList->getItemAt(i)->getArtist());
        libraryList->getItemAt(minIndex)->setDuration(libraryList->getItemAt(i)->getDuration());
        libraryList->getItemAt(minIndex)->setPlayCount(libraryList->getItemAt(i)->getPlayCount());
        libraryList->getItemAt(i)->setTitle(tempTitle);
        libraryList->getItemAt(i)->setArtist(tempArtist);
        libraryList->getItemAt(i)->setDuration(tempDuration);
        libraryList->getItemAt(i)->setPlayCount(tempPlayCount);
    }
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

Song* Library::getSong(std::string title, std::string artist) {
    return libraryList->getItem(title, artist);
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

std::string Library::findBySong(std::string title, std::string artist) {
    Song *song;
    std::string songString = "";
    for (int i = 0; i < libraryList->getLength(); i++) {
        song = libraryList->getItemAt(i);
        if (song->getTitle() == title && song->getArtist() == artist) break;
    }
    if (song) songString = song->toString();
    return songString;
}

std::string Library::toString() {
    sortLibrary();
    std::string libraryString = "";
    for (int i = 0; i < libraryList->getLength(); i++) {
        libraryString += libraryList->getItemAt(i)->toString() + "\n\n";
    }
    return libraryString;
}

