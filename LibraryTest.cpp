//
// Created by vcrab on 11/19/2019.
//

#include <iostream>
#include "Library.h"
#include "Song.h"

void addAndGetSongAtTest(Library* testLibrary) {
    std::cout << "\nadd Test: ";
    testLibrary->clear();
    Song *song1 = new Song("All I Want For Christmas Is You", "Mariah Carey", 2.9);
    Song *song2 = new Song("A Holly Jolly Christmas", "Burl Ives", 2.27);
    Song *song3 = new Song("Sleigh Ride", "The Ronettes", 3.03);
    Song *song4 = new Song("Last Christmas", "Wham!", 4.6);
    Song *song5 = new Song("Someday at Christmas", "Jackson 5", 2.64);
    testLibrary->add(song1, 0);
    testLibrary->add(song2, 0);
    testLibrary->add(song3, 0);
    testLibrary->add(song4, 0);
    testLibrary->add(song5, 0);
    if (testLibrary->getSongAt(0) == song5) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    if (testLibrary->getSongAt(1) == song4) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    if (testLibrary->getSongAt(2) == song3) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    if (testLibrary->getSongAt(3) == song2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    if (testLibrary->getSongAt(4) == song1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    try {
        testLibrary->add(new Song("Here Comes Santa Claus", "Bing Crosby", 3.02), -1);
        std::cout << "\nFailed, add did not throw exception";
    }
    catch (std::out_of_range &e) {
        std::cout << "\nPassed";
    }
    try {
        testLibrary->add(new Song("Here Comes Santa Claus", "Bing Crosby", 3.02), 1000);
        std::cout << "\nFailed, add did not throw exception";
    }
    catch (std::out_of_range &e) {
        std::cout << "\nPassed";
    }
    try {
        testLibrary->getSongAt(-1);
        std::cout << "\nFailed, getSongAt did not throw exception";
    }
    catch (std::out_of_range &e) {
        std::cout << "\nPassed";
    }
    try {
        testLibrary->getSongAt(1000);
        std::cout << "\nFailed getSongAt did not throw exception";
    }
    catch (std::out_of_range &e) {
        std::cout << "\nPassed";
    }
    try {
        testLibrary->add(song1, 0);
        std::cout << "\nFailed add did not throw exception";
    }
    catch (std::invalid_argument &e) {
        std::cout << "\nPassed";
    }
}

void removeTest(Library* testLibrary) { //TODO
    std::cout << "\nremove Test: ";
    testLibrary->clear();
    try {
        testLibrary->remove("Last Christmas", "Glee");
        std::cout << "\nFailed, remove did not throw exception";
    }
    catch (std::out_of_range &e) {
        std::cout << "\nPassed";
    }
    Song* song1 = new Song ("All I Want For Christmas Is You", "Mariah Carey", 2.9);
    Song* song2 = new Song ("A Holly Jolly Christmas", "Burl Ives", 2.27);
    Song* song3 = new Song ("Sleigh Ride", "The Ronettes", 3.03);
    Song* song4 = new Song ("Last Christmas", "Wham!", 4.6);
    Song* song5 = new Song ("Someday at Christmas", "Jackson 5", 2.64);
    testLibrary->add(song1, 0);
    testLibrary->add(song2, 0);
    testLibrary->add(song3, 0);
    testLibrary->add(song4, 0);
    testLibrary->add(song5, 0);
    Song* removedSong1 = testLibrary->remove(song1->getTitle(), song1->getArtist());
    if (removedSong1 == song1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 1";
        //std::cout << "\nInstead removed " << removedSong1->getTitle() << " by " << removedSong1->getArtist();
    }
    Song* removedSong2 = testLibrary->remove(song2->getTitle(), song2->getArtist());
    if (removedSong2 == song2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 2";
        //std::cout << "\nInstead removed " << removedSong2->getTitle() << " by " << removedSong2->getArtist();
    }
    Song* removedSong3 = testLibrary->remove(song3->getTitle(), song3->getArtist());
    if (removedSong3 == song3) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 3";
        //std::cout << "\nInstead removed " << removedSong3->getTitle() << " by " << removedSong3->getArtist();
    }
    Song* removedSong4 = testLibrary->remove(song4->getTitle(), song4->getArtist());
    if (removedSong4 == song4) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 4";
        //std::cout << "\nInstead removed " << removedSong4->getTitle() << " by " << removedSong4->getArtist();
    }
    Song* removedSong5 = testLibrary->remove(song5->getTitle(), song5->getArtist());
    if (removedSong5 == song5) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 5";
        //std::cout << "\nInstead removed " << removedSong5->getTitle() << " by " << removedSong5->getArtist();
    }
    try {
        testLibrary->remove("Last Christmas", "Glee");
        std::cout << "\nFailed, remove did not throw exception";
    }
    catch (std::invalid_argument &e) {
        std::cout << "\nPassed";
    }
}

void isEmptyAndClearTest(Library* testLibrary) {
    std::cout << "\nisEmpty Test: ";
    testLibrary->add(new Song("Here Comes Santa Claus", "Bing Crosby", 3.02), 0);
    if (testLibrary->isEmpty() == false) {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, returned true rather than false";
    }
    std::cout << "\nisEmpty and clear Test: ";
    testLibrary->clear();
    if (testLibrary->isEmpty() == true) {
        std::cout << "Passed";
    }
    else {
        std::cout << "Failed, returned false rather than true";
    }
}

void getLengthAndDurationTest(Library* testLibrary) {
    std::cout << "\ngetLength and getDuration Test: ";
    testLibrary->clear();
    if (testLibrary->getLength() == 0) {
        std::cout << "\nGet Length Passed";
    }
    else {
        std::cout << "\nGet Length Failed, returned " << testLibrary->getLength() << ", length should have been 0";
    }
    if (testLibrary->getDuration() == 0) {
        std::cout << "\nGet Duration Passed";
    }
    else {
        std::cout << "\nGet Duration Failed, returned " << testLibrary->getDuration() << ", length should have been 0";
    }
    testLibrary->add(new Song("Jingle Bell Rock", "Bobby Helms", 2.15), 0);
    if (testLibrary->getLength() == 1) {
        std::cout << "\nGet Length Passed";
    }
    else {
        std::cout << "\nGet Length Failed, returned " << testLibrary->getLength() << ", length should have been 1";
    }
    if (testLibrary->getDuration() == 2.15f) {
        std::cout << "\nGet Duration Passed";
    }
    else {
        std::cout << "\nGet Duration Failed, returned " << testLibrary->getDuration() << ", length should have been 2.15";
    }
    testLibrary->add(new Song("Christmas Wrapping", "The Waitresses", 5.33), 0);
    if (testLibrary->getLength() == 2) {
        std::cout << "\nGet Length Passed";
    }
    else {
        std::cout << "\nGet Length Failed, returned " << testLibrary->getLength() << ", length should have been 2";
    }
    if (testLibrary->getDuration() == 7.48f) {
        std::cout << "\nGet Duration Passed";
    }
    else {
        std::cout << "\nGet Duration Failed, returned " << testLibrary->getDuration() << ", length should have been 7.48";
    }
}

void findTest(Library* testLibrary) {
    std::cout << "\nfind Test: ";
    Song* song1 = new Song("What's This?", "Danny Elfman", 3.1);
    Song* song2 = new Song("Rockin' Around the Christmas Tree", "Brenda Lee", 2.1);
    Song* song3 = new Song("Hot Chocolate", "Tom Hanks", 2.52);
    testLibrary->add(song3, 0);
    testLibrary->add(song2, 0);
    testLibrary->add(song1, 0);
    if (testLibrary->find(song1->getTitle(), song1->getArtist()) == 0) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned " << testLibrary->find(song1->getTitle(), song1->getArtist()) <<
            " instead of 0";
    }
    if (testLibrary->find(song2->getTitle(), song2->getArtist()) == 1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned " << testLibrary->find(song2->getTitle(), song2->getArtist()) <<
            " instead of 1";
    }
    if (testLibrary->find(song3->getTitle(), song3->getArtist()) == 2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned " << testLibrary->find(song3->getTitle(), song3->getArtist()) <<
            " instead of 2";
    }
}

void runAllLibraryTests() {
    Library* testLibrary = new Library();
    addAndGetSongAtTest(testLibrary);
    testLibrary->clear();
    removeTest(testLibrary);
    testLibrary->clear();
    isEmptyAndClearTest(testLibrary);
    testLibrary->clear();
    getLengthAndDurationTest(testLibrary);
    testLibrary->clear();
    findTest(testLibrary);
    delete testLibrary;
}

int main(){
    std::cout << "\n\n======================= Library Tests ===========================\n\n" << std::endl;
    runAllLibraryTests();
    return 0;
}
