//
// Created by vcrab on 11/25/2019.
//

#include <iostream>
#include "Song.h"

void testGetters(Song* testSong) {
    std::cout << "getTitle Test: ";
    if (testSong->getTitle() == "The Best of Both Worlds") {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->getTitle() << " instead of The Best of Both Worlds";
    }
    std::cout << "\ngetArtist Test: ";
    if (testSong->getArtist() == "Hannah Montana") {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->getArtist() << " instead of Hannah Montana";
    }
    std::cout << "\ngetDuration Test: ";
    testSong->setDuration(2.9);
    if (testSong->getDuration() == 2.9f) {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->getDuration() << " instead of 2.9";
    }
    std::cout << "\ngetPlayCount Test: ";
    if (testSong->getPlayCount() == 0) {
        std::cout << "Passed\n";
    }
    else {
        std::cout << "\nFailed, printed " << testSong->getDuration() << " instead of 0\n";
    }
    std::cout << "-----done-----";
}

void settersTest(Song* testSong) {
    std::cout << "\nsetArtist Test: ";
    testSong->setArtist("Miley Cyrus");
    if (testSong->getArtist() == "Miley Cyrus") {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->getArtist() << " instead of Miley Cyrus";
    }
    std::cout << "\nsetTitle Test: ";
    testSong->setTitle("The Climb");
    if (testSong->getTitle() == "The Climb") {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->getTitle() << " instead of The Climb";
    }
    std::cout << "\nsetDuration Test: ";
    testSong->setDuration(3.92);
    if (testSong->getDuration() == 3.92f) {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->getDuration() << " instead of 3.92";
    }
    std::cout << "\nsetPlayCount Test: ";
    testSong->setPlayCount(7);
    if (testSong->getPlayCount() == 7) {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->getPlayCount() << " instead of 7";
    }
    std::cout << "\n-----done-----\n";
}

void toStringTest(Song* testSong) {
    std::cout << "\ntoString Test: ";
    if (testSong->toString() ==
    "artist:\t\tMiley Cyrus\ntitle:\t\tThe Climb\nduration:\t3.920000\nplay count:\t7") {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, printed " << testSong->toString() <<
        " instead of artist:\t\tMiley Cyrus\ntitle:\t\tThe Climb\nduration:\t3.920000\nplay count:\t7";
    }
    std::cout << "\n-----done-----";
}

void runAllSongTests() {
    Song* newSong = new Song ("The Best of Both Worlds", "Hannah Montana", 2.9);
    testGetters(newSong);
    settersTest(newSong);
    toStringTest(newSong);
}

int main() {
    std::cout << "\n======================= Song Tests ===========================\n" << std::endl;
    runAllSongTests();
    return 0;
}

