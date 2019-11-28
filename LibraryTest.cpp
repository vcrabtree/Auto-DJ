//
// Created by vcrab on 11/19/2019.
//

#include <iostream>
#include "Library.h"
#include "Song.h"

void copyConstructorTest(Library& testLibrary) {
    //TODO
}

void assignmentOperatorTest(Library& testLibrary) {
    //TODO
}

void addAndGetSongAtTest(Library* testLibrary) {
    std::cout << "\nadd Test: ";
    testLibrary->clear();
    Song* song1 = new Song ("All I Want For Christmas Is You", "Mariah Carey", 2.9);
    Song* song2 = new Song ("A Holly Jolly Christmas", "Burl Ives", 2.27);
    Song* song3 = new Song ("Sleigh Ride", "The Ronettes", 3.03);
    Song* song4 = new Song ("Last Christmas", "Wham!", 4.6);
    Song* song5 = new Song ("Someday at Christmas", "Jackson 5", 2.64);
    testLibrary->add(song1, 0);
    testLibrary->add(song2, 0);
    testLibrary->add(song3, 1);
    testLibrary->add(song4, 2);
    testLibrary->add(song5, 0);
    if (testLibrary->getSongAt(0) == song5) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    if (testLibrary->getSongAt(1) == song1) {
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
    if (testLibrary->getSongAt(3) == song4) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    if (testLibrary->getSongAt(4) == song2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
}

void removeTest(Library testLibrary) { //TODO
    std::cout << "\nremove Test: ";
    testLibrary.clear();
    Song* song1 = new Song ("All I Want For Christmas Is You", "Mariah Carey", 2.9);
    Song* song2 = new Song ("A Holly Jolly Christmas", "Burl Ives", 2.27);
    Song* song3 = new Song ("Sleigh Ride", "The Ronettes", 3.03);
    Song* song4 = new Song ("Last Christmas", "Wham!", 4.6);
    Song* song5 = new Song ("Someday at Christmas", "Jackson 5", 2.64);
    testLibrary.add(song1, 0);
    testLibrary.add(song2, 0);
    testLibrary.add(song3, 1);
    testLibrary.add(song4, 2);
    testLibrary.add(song5, 0);
    Song* removedSong1 = testLibrary.remove(song2->getTitle(), song2->getArtist());
    if (removedSong1 == song2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
    }
    Song* removedSong2 = testLibrary.remove(song4->getTitle(), song4->getArtist());
    if (removedSong1 == song4) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
    }
    Song* removedSong3 = testLibrary.remove(song3->getTitle(), song3->getArtist());
    if (removedSong1 == song3) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
    }
    Song* removedSong4 = testLibrary.remove(song1->getTitle(), song1->getArtist());
    if (removedSong1 == song1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
    }
    Song* removedSong5 = testLibrary.remove(song5->getTitle(), song5->getArtist());
    if (removedSong1 == song5) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
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

void getLengthTest(Library* testLibrary) {
    std::cout << "\ngetLength Test: ";
    testLibrary->clear();
    if (testLibrary->getLength() == 0) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned " << testLibrary->getLength() << ", length should have been 0";
    }
    testLibrary->add(new Song("Jingle Bell Rock", "Bobby Helms", 2.15), 0);
    if (testLibrary->getLength() == 1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned " << testLibrary->getLength() << ", length should have been 1";
    }
    testLibrary->add(new Song("Christmas Wrapping", "The Waitresses", 5.33), 0);
    if (testLibrary->getLength() == 2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned " << testLibrary->getLength() << ", length should have been 2";
    }
}

void findTest(Library testLibrary) {
    std::cout << "\nfind Test: ";
    Song* song1 = new Song("What's This?", "Danny Elfman", 3.1);
    Song* song2 = new Song("Rockin' Around the Christmas Tree", "Brenda Lee", 2.1);
    Song* song3 = new Song("Hot Chocolate", "Tom Hanks", 2.52);
    testLibrary.add(song3, 0);
    testLibrary.add(song2, 0);
    testLibrary.add(song1, 0);
    if (testLibrary.find(song1->getTitle(), song1->getArtist()) == 1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
    }
    if (testLibrary.find(song2->getTitle(), song2->getArtist()) == 2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
    }
    if (testLibrary.find(song3->getTitle(), song3->getArtist()) == 3) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed";
    }
}

void runAllLibraryTests() {
    Library* testLibrary = new Library();
    copyConstructorTest(Library& testLibrary);
    assignmentOperatorTest(Library& testLibrary);
    addAndGetSongAtTest(Library testLibrary);
    testLibrary->clear();
    removeTest(Library* testLibrary);
    testLibrary->clear();
    isEmptyAndClearTest(Library* testLibrary);
    testLibrary->clear();
    getLengthTest(Library* testLibrary);
    testLibrary->clear();
    findTest(Library testLibrary);
    delete testLibrary;
}

int main(){
    std::cout << "\n\n======================= Library Tests ===========================\n\n" << std::endl;
    runAllLibraryTests();
    return 0;
}
