#include "Song.h"

Song::Song() {}

Song::Song(std::string newTitle, std::string newArtist, float newDuration) {
    artist = newArtist;
    title = newTitle;
    duration = newDuration;
    playCount = 0;
}

Song Song::operator++(int) {
    Song temp = *this;
    ++playCount;
    return temp;
}

void Song::setArtist(std::string newArtist) { artist = newArtist; }

std::string Song::getArtist() { return artist; }

void Song::setTitle(std::string newTitle) { title = newTitle; }

std::string Song::getTitle() { return title; }

void Song::setDuration(float newDuration) { duration = newDuration; }

float Song::getDuration() { return duration; }

void Song::setPlayCount(int newPlayCount) { playCount = newPlayCount; }

int Song::getPlayCount() { return playCount; }

std::string Song::toString() {
    return 
        "artist:\t\t"        +artist+
        "\ntitle:\t\t"       +title+
        "\nduration:\t"    +std::to_string(duration)+
        "\nplay count:\t"  +std::to_string(playCount);
}

std::string Song::toFileString(bool forPlaylist) {
    std::string fileString = title+"~\n"+artist+"~\n";
    if (!forPlaylist) fileString += std::to_string(duration)+"~\n";
    fileString += "\n";
    return fileString;
}
