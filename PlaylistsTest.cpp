#include <iostream>
#include "Library.h"
#include "Playlists.h"
#include "TestLib.h"

void addAndRemoveTest(Library *library) {
    printTestHeader("addAndRemoveTest");

    int size = 10;
    Playlists *playlists = generateEmptyPlaylists(size);
    std::string titles[size] = {};

    printTestCase("filled playlists length matches amount of playlists added");
    fillPlaylists(library, playlists, size, titles);
    printAssert(playlists->getLength(), size);

    printTestCase("added playlists are found");
    for (int i = 0; i < size; i++) printAssert(playlists->find(titles[i]), i);

    printTestCase("non-existent playlists can't be removed");
    for (int i = 0; i < size; i++) {
        try {
            playlists->remove("");
            printExceptionFail("remove");
        } catch(std::out_of_range &e) {
            printAssert(*"There is no item at this index", *e.what());
        }
        
    }

    printTestCase("existing playlists are removed");
    for (int i = 0; i < size; i++)
        printAssert(playlists->remove(titles[i])->getTitle(), titles[i]);

    printTestCase("playlists length matches amount of playlists removed");
    printAssert(playlists->getLength(), 0);

    delete playlists;

    printTestFooter();
}

void getLengthTest(Library *library) {
    printTestHeader("getLengthTest");

    int size = 10;
    Playlists *playlists = generateEmptyPlaylists(size);

    printTestCase("playlists length=0");
    printAssert(playlists->getLength(), 0);

    printTestCase("playlists holding music, length is expected value");
    for (int i = 1; i <= size; i++) {
        fillPlaylists(library, playlists, i);
        printAssert(playlists->getLength(), i);
        playlists->clear();
    }
    printTestCase("playists length=0 after cleared");
    printAssert(playlists->getLength(), 0);

    printTestFooter();

    delete playlists;
    playlists = nullptr; 
}

void findTest(Library *library) {
    printTestHeader("findTest");

    int size = 10;
    Playlists *playlists = generateEmptyPlaylists(size);
    Playlist *playlist;
    std::string titles[size] = {}, title;

    fillPlaylists(library, playlists, size, titles);

    printTestCase("existing playlists found in playlists");
    for (int i = 0; i < size; i++) printAssert(playlists->find(titles[i]), i);

    printTestCase("non-existing playlists not found in playlists");
    for (int i = 0; i < size; i++) printAssert(playlists->find("") != i, true);

    printTestCase("nothing to find in emptied playlists");
    playlists->clear();
    printAssert(playlists->find(""), -1);

    delete playlists;
    playlists = nullptr;

    printTestFooter();
}

void getPlaylistAtTest(Library *library) {
    printTestHeader("getPlaylistAtTest");

    int size = 10;
    Playlists *playlists = generateEmptyPlaylists(size);
    std::string titles[size] = {};
    fillPlaylists(library, playlists, size, titles);

    printTestCase("all playlists are available at expected locations");
    for (int i = 0; i < size; i++) 
        printAssert(playlists->getPlaylistAt(i)->getTitle(), titles[i]);

    printTestCase("can't get a playlist at a location exceeding playlists size");
    for (int i = size; i < size+5; i ++) {
        try {
            playlists->getPlaylistAt(i);
            printExceptionFail("getPlaylistAt");
        } catch (std::out_of_range &e) {
            printAssert(*"There is no item at this index", *e.what());
        }
    }

    printTestCase("can't get a playlist at a negative location");
    for (int i = -1; i > -6; i--) {
        try {
            playlists->getPlaylistAt(i);
            printExceptionFail("getPlaylistAt");
        } catch (std::out_of_range &e) {
            printAssert(*"There is no item at this index", *e.what());
        }
    }
    delete playlists;

    printTestFooter();
}

void runAllTests() {
    Library *library = generateLibrary(1000, 1, 20);
    Playlists *emptyPlaylists;

    addAndRemoveTest(library);
    getLengthTest(library);
    findTest(library);
    getPlaylistAtTest(library);

    delete library;
    library = nullptr;
}

int main() {
    printTestTitle("Playlists Test");
    runAllTests();
    return 0;
}
