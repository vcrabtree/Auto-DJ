#include <iostream>
#include "Song.h"
#include "Playlist.h"
#include "TestLib.h"

void emptyPlaylistTest(Playlist* emptyPlaylist) {
    printTestHeader("emptyPlaylistTest");

    printTestCase("check properties");
    printAssert(emptyPlaylist->getLength(), 0);
    printAssert(emptyPlaylist->getDuration(), 0.0f);
    printAssert(emptyPlaylist->isEmpty(), true);
    printAssert(emptyPlaylist->find("title", "artist"), -1);

    printTestCase("get non-existent songs");
    for (int i = 0; i < 5; i++) {
        try {
            emptyPlaylist->getSongAt(i);
            printExceptionFail("getSongAt");
        } catch(std::out_of_range& e){
            printAssert(*("playlist is empty"), *e.what());
        }
    }

    printTestCase("remove non-existent songs after cleared");
    for (int i = 0; i < 5; i++) {
        try {
            emptyPlaylist->remove(i+"", i+"");
            printExceptionFail("remove");
        } catch(std::out_of_range& e){
            printAssert(*("playlist is empty"), *e.what());
        }
    }


    printTestCase("add songs and check updated properties");
    float duration = 0.0f, totalDuration = 0.0f;
    int length = 0;
    for (int i = 0; i < 5; i++) {
        duration = 1.0f+(float)i/10;

        emptyPlaylist->add(
         new Song("title "+std::to_string(i), 
                 "artist "+std::to_string(i), 
                 duration
         ));

        totalDuration += duration;
        length++;
    }
    printAssert(emptyPlaylist->getLength(), length);
    printAssert(emptyPlaylist->getDuration(), totalDuration);

    printTestCase("clear and check updated properties");
    emptyPlaylist->clear();
    printAssert(emptyPlaylist->getLength(), 0);
    printAssert(emptyPlaylist->getDuration(), 0.0f);
    emptyPlaylist->toString().length();
    printAssert((int)emptyPlaylist->toString().length(), 0);


    printTestFooter();
}

void addAndGetSongAtTest(Playlist* playlist) {
    printTestHeader("addTest");

    printTestCase("add songs and get valid songs");
    int songsToAdd = 10;
    for (int i = 0; i < songsToAdd; i++) {
        playlist->add(
            new Song("title "+std::to_string(i+1), 
                     "artist "+std::to_string(i+1),
                     i+1
        ));
    }
    for (int i = 0; i < playlist->getLength(); i++) {
        printAssert(
            playlist->getSongAt(i)->getTitle(), 
            "title "+std::to_string(i+1)
        );
    }


    printTestCase("get songs at invalid index (greater than length)");
    for (int i = playlist->getLength(); i < playlist->getLength()+5; i++) {
        try {
            playlist->getSongAt(i);
            printExceptionFail("getSongAt("+std::to_string(i)+")");
        } catch(std::out_of_range& e){
            printAssert(*("invalid index"), *e.what());
        }
    }
    printTestCase("get songs at invalid index (negative indices)");
    for (int i = -1; i != playlist->getLength()*-1; i--) {
        try {
            playlist->getSongAt(i);
            printExceptionFail("getSongAt("+std::to_string(i)+")");
        } catch(std::out_of_range& e){
            printAssert(*("invalid index"), *e.what());
        }
    }
    printTestFooter();
}

void removeTest(Playlist* playlist) {
    printTestHeader("removeTest");

    int length = playlist->getLength();
    Song *songs[length] = {};
    for (int i = 0; i < length; i++) songs[i] = playlist->getSongAt(i);

    printTestCase("remove non-existent songs");
    Song *remSong;
    for (int i = 0; i < length; i++) {
        remSong = playlist->remove("", "");
        printAssert((bool)remSong, false);
        printAssert((bool)remSong, false);
    }

    printTestCase("return expected removed song");
    std::string currTitle, currArtist;
    for (int i = 0; i < length; i++) {
        currTitle = songs[i]->getTitle();
        currArtist = songs[i]->getArtist();
        remSong = playlist->remove(currTitle, currArtist);
        
        printAssert(remSong->getTitle(), currTitle);
        printAssert(remSong->getArtist(), currArtist);
    }

    printTestCase("remove after songs cleared");
    for (int i = 0; i < length; i++) {
        try {
            currTitle = songs[i]->getTitle();
            currArtist = songs[i]->getArtist();
            playlist->remove(currTitle, currArtist);
            printExceptionFail("remove(title="+currTitle+",artist="+currArtist);
        } catch(std::out_of_range& e) {
            printAssert(*("playlist is empty"), *e.what());
        }
    }

    printTestFooter();
}

void randomPlaylistTest() {}
void findTest(Playlist* playlist) {}
void playNextTest(Playlist* playlist) {}


Playlist* generateRandomPlaylist(std::string title, float duration) {
    // change to Library when Library Tests are complete
    List *library = new Playlist("pseudo-library");
    Playlist *randomPlaylist;
    int size = 10;

    for (int i = 0; i < size; i++) {
        library->add(
         new Song("title "+std::to_string(i), 
                 "artist "+std::to_string(i), 
                 2.0f+(float)i/10
         ));
    }
    randomPlaylist = new Playlist(title, duration, *library);
    delete library;
    library = nullptr;

    return randomPlaylist;
}

Playlist* generateEmptyPlaylist() { 
    return new Playlist("empty playlist"); 
}

void runAllPlaylistTests() {
    Playlist *emptyPlaylist = generateEmptyPlaylist(),
             *randomPlaylist = generateRandomPlaylist("random playlist", 15.5);
    
    emptyPlaylistTest(emptyPlaylist);
    delete emptyPlaylist;

    emptyPlaylist = generateEmptyPlaylist();
    delete emptyPlaylist;

    emptyPlaylist = generateEmptyPlaylist();
    addAndGetSongAtTest(emptyPlaylist);
    delete emptyPlaylist;

    removeTest(randomPlaylist);

    //TODO
    //randomPlaylistTest()
    //findTest(playlist);
    //playNextTest(playlist);
}

int main() {
    printTestTitle("Playlist Tests");
    runAllPlaylistTests();
    return 0;
}
