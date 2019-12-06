//
// Created by vcrab on 11/19/2019.
//

#include <iostream>
#include "ArrayList.h"
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
    testLibrary->add(song1);
    testLibrary->add(song2);
    testLibrary->add(song3);
    testLibrary->add(song4);
    testLibrary->add(song5);
    if (testLibrary->getSongAt(0) == song1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
    }
    if (testLibrary->getSongAt(1) == song2) {
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
    if (testLibrary->getSongAt(4) == song5) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not return proper value";
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
    testLibrary->add(song1);
    testLibrary->add(song2);
    testLibrary->add(song3);
    testLibrary->add(song4);
    testLibrary->add(song5);
    Song* removedSong1 = testLibrary->remove(song1->getTitle(), song1->getArtist());
    if (removedSong1 == song1) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 1";
    }
    Song* removedSong2 = testLibrary->remove(song2->getTitle(), song2->getArtist());
    if (removedSong2 == song2) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 2";
    }
    Song* removedSong3 = testLibrary->remove(song3->getTitle(), song3->getArtist());
    if (removedSong3 == song3) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 3";
    }
    Song* removedSong4 = testLibrary->remove(song4->getTitle(), song4->getArtist());
    if (removedSong4 == song4) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 4";
    }
    Song* removedSong5 = testLibrary->remove(song5->getTitle(), song5->getArtist());
    if (removedSong5 == song5) {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, did not remove song 5";
    }
    try {
        testLibrary->remove("Last Christmas", "Glee");
        std::cout << "\nFailed, remove did not throw exception";
    }
    catch (std::out_of_range &e) {
        std::cout << "\nPassed";
    }
}

void isEmptyAndClearTest(Library* testLibrary) {
    std::cout << "\nisEmpty Test: ";
    testLibrary->add(new Song("Here Comes Santa Claus", "Bing Crosby", 3.02));
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
        std::cout << "\nGet Duration Failed, returned " << testLibrary->getDuration() << ", duration should have been 0";
    }
    testLibrary->add(new Song("Jingle Bell Rock", "Bobby Helms", 2.15));
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
        std::cout << "\nGet Duration Failed, returned " << testLibrary->getDuration() << ", duration should have been 2.15";
    }
    testLibrary->add(new Song("Christmas Wrapping", "The Waitresses", 5.33));
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
        std::cout << "\nGet Duration Failed, returned " << testLibrary->getDuration() << ", duration should have been 7.48";
    }
}

void findTest(Library* testLibrary) {
    std::cout << "\nfind Test: ";
    Song* song1 = new Song("What's This?", "Danny Elfman", 3.1);
    Song* song2 = new Song("Rockin' Around the Christmas Tree", "Brenda Lee", 2.1);
    Song* song3 = new Song("Hot Chocolate", "Tom Hanks", 2.52);
    testLibrary->add(song1);
    testLibrary->add(song2);
    testLibrary->add(song3);
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

void findByArtistTest(Library* testLibrary) {
    std::cout << "\nfindByArtist Test: ";
    Song *song1 = new Song("Our Song", "Taylor Swift", 3.35);
    Song *song2 = new Song("Hey Stephen", "Taylor Swift", 4.23);
    Song *song3 = new Song("Burnin' Up", "Jonas Brothers", 2.92);
    Song *song4 = new Song("Mean", "Taylor Swift", 3.96);
    Song *song5 = new Song("Girlfriend", "Avril Lavigne", 3.6);
    testLibrary->add(song1);
    testLibrary->add(song2);
    testLibrary->add(song3);
    testLibrary->add(song4);
    testLibrary->add(song5);
    if (testLibrary->findByArtist(song1->getArtist()) == "Our Song\nHey Stephen\nMean\n") {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned\n" << testLibrary->findByArtist(song1->getArtist()) <<
                  "instead of \nOur Song\nHey Stephen\nMean";
    }
    if (testLibrary->findByArtist(song3->getArtist()) == "Burnin' Up\n") {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned\n" << testLibrary->findByArtist(song3->getArtist()) <<
                  "instead of Burnin' Up";
    }
    if (testLibrary->findByArtist(song5->getArtist()) == "Girlfriend\n") {
        std::cout << "\nPassed";
    }
    else {
        std::cout << "\nFailed, returned\n" << testLibrary->findByArtist(song5->getArtist()) <<
                  "instead of Girlfriend";
    }
}

void runAllLibraryTests() {
    Library* testLibrary = new Library(10);
    addAndGetSongAtTest(testLibrary);
    testLibrary->clear();
    removeTest(testLibrary);
    testLibrary->clear();
    isEmptyAndClearTest(testLibrary); 
    testLibrary->clear();
    getLengthAndDurationTest(testLibrary); 
    testLibrary->clear();
    findTest(testLibrary);
    testLibrary->clear();
    findByArtistTest(testLibrary);
    delete testLibrary;
}

int main(){
    std::cout << "\n\n======================= Library Tests ===========================\n\n" << std::endl;
    runAllLibraryTests();
    std::cout << "\n\n======================= Done ===========================\n\n" << std::endl;
    return 0;
}
