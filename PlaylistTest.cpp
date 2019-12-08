#include <iostream>
#include "Library.h"
#include "Playlist.h"
#include "TestLib.h"

void getLengthAndDurationTest(Library *library, Playlist *filledPlaylist) {
    printTestHeader("getLengthAndDurationTest");

    printTestCase("filled playlist length == library length");
    printAssert(filledPlaylist->getLength(), library->getLength());

    printTestCase("filled playlist duration == library duration");
    printAssert(filledPlaylist->getDuration(), library->getDuration());

    for (int i = 0; i < library->getLength()/2; i++) filledPlaylist->playNext();

    printTestCase("half-emptied playlist length == library length/2");
    printAssert(filledPlaylist->getLength(), library->getLength()/2);

    printTestCase("half-emptied playlist duration == library duration/2");
    printAssert(filledPlaylist->getDuration(), library->getDuration()/2);

    printTestCase("emtpy playlist length=0");
    filledPlaylist->clear();
    printAssert(filledPlaylist->getLength(), 0);
    
    printTestFooter();
}

void addAndRemoveTest(Library *library, Playlist *emptyPlaylist) {
    printTestHeader("addAndRemoveTest");

    printTestCase("all songs from library added to playlist");
    fillPlaylist(library, emptyPlaylist);
    printAssert(emptyPlaylist->getLength(), library->getLength());
    printAssert(emptyPlaylist->getDuration(), library->getDuration());

    printTestCase("all songs removed match songs added from library");
    Song *song;
    std::string title, artist;
    for (int i = 0; i < library->getLength(); i++) {
        song = library->getSongAt(i);
        title = song->getTitle();
        artist = song->getArtist();
        printAssert(emptyPlaylist->remove(title, artist), song);
    }

    printTestCase("playlist length=0");
    printAssert(emptyPlaylist->isEmpty(), true);
    printTestCase("playlist duration=0");
    printAssert(emptyPlaylist->getDuration(), 0.0f);

    printTestCase("can't remove from empty playlist");
    try {
        emptyPlaylist->remove(title, artist);
        printExceptionFail("remove");
    } catch(std::out_of_range &e) {
        printAssert(*("queue is empty"), *e.what());
    }
}

void playNextTest(Library *library, Playlist *emptyPlaylist) {
    printTestHeader("playNextTest");
    fillPlaylist(library, emptyPlaylist);
    printTestCase("each next played song in library");
    Song *playedSong, *libSong;
    for (int i = 0; i < library->getLength(); i++) {
        playedSong = emptyPlaylist->playNext();
        libSong = library->getSongAt(i);
        printAssert(playedSong, libSong);
    }

    printTestCase("song playcounts=1");
    for (int i = 0; i < library->getLength(); i++)
        printAssert(library->getSongAt(i)->getPlayCount(), 1);

    printTestCase("songs played again, playcounts=2");
    fillPlaylist(library, emptyPlaylist);
    for (int i = 0; i < library->getLength(); i++) playedSong = emptyPlaylist->playNext();
    for (int i = 0; i < library->getLength(); i++)
        printAssert(library->getSongAt(i)->getPlayCount(), 2);

    printTestCase("playlist length=0");
    printAssert(emptyPlaylist->isEmpty(), true);

    printTestCase("playlist duration=0");
    printAssert(emptyPlaylist->getDuration(), 0.0f);

    printTestCase("can't play 'next song' on empty playlist");
    try {
        emptyPlaylist->playNext();
        printExceptionFail("playNext");
    } catch(std::out_of_range &e) {
        printAssert(*"playlist is empty", *(e.what()));
    }
    printTestFooter();
}

void clearTest(Playlist *filledPlaylist) {
    printTestHeader("clearTest");

    filledPlaylist->clear();

    printTestCase("playlist is empty");
    printAssert(filledPlaylist->isEmpty(), true);

    printTestCase("playlist length=0");
    printAssert(filledPlaylist->getLength(), 0);

    printTestCase("playlist duration=0");
    printAssert(filledPlaylist->getDuration(), 0.0f);

    printTestFooter();
}

void findTest(Library *library, Playlist *filledPlaylist) {
    printTestHeader("findTest");

    int length = filledPlaylist->getLength();
    printTestCase("find non-existent songs");
    for (int i = 0; i < filledPlaylist->getLength(); i++) 
        printAssert(filledPlaylist->find(""+i, ""+i+1), -1);

    printTestCase("find existing songs");
    std::string currTitle, currArtist;
    Song *libSong;
    for (int i = 0; i < length; i++) {
        libSong = library->getSongAt(i);
        currTitle = libSong->getTitle();
        currArtist = libSong->getArtist();
        printAssert(filledPlaylist->find(currTitle, currArtist), i);
    } 

    printTestFooter();
}

void randomPlaylistTest(Library *library) {
    printTestHeader("randomPlaylistTest");

    Playlist *randPlaylistA, *randPlaylistB;
    float duration = 0.0f;

    printTestCase("desired duration <= new playlist");
    for (int i = 1; i < 10; i++) {
        duration = (float)(i*i);
        randPlaylistA = new Playlist("playlist a", duration, *library);
        printAssert(randPlaylistA->getDuration() <= duration, true);
        delete randPlaylistA;
    }

    printTestCase("songs uniquely ordered between two playlists");
    int repeatCount = 0;
    int lengthB;
    Song *songA, *songB;
    for (int i = 5; i < 15; i++) {
        duration = (float)(i*i);
        randPlaylistA = new Playlist("playlist a", duration, *library);
        randPlaylistB = new Playlist("playlist b", duration, *library);
        lengthB = randPlaylistB->getLength();

        while (!randPlaylistA->isEmpty() && !randPlaylistB->isEmpty()) {
            songA = randPlaylistA->playNext();
            songB = randPlaylistB->playNext();
            if (songA == songB) repeatCount++;
        }
        repeatCount = 0;
        printAssert(repeatCount < lengthB/3, true);
        delete randPlaylistA;
        delete randPlaylistB;
    }

    printTestFooter();
}

void runAllPlaylistTests() {
    Library *library = generateLibrary(5, 1, 5);
    Playlist *emptyPlaylist = generateEmptyPlaylist(), 
             *filledPlaylist = generateEmptyPlaylist();

    fillPlaylist(library, filledPlaylist);
    getLengthAndDurationTest(library, filledPlaylist);
    delete library;
    delete filledPlaylist;


    library = generateLibrary(15, 2, 5);
    emptyPlaylist = generateEmptyPlaylist();
    addAndRemoveTest(library, emptyPlaylist);
    delete library;
    delete emptyPlaylist;

    library = generateLibrary(15, 2, 5);
    emptyPlaylist = generateEmptyPlaylist();
    playNextTest(library, emptyPlaylist);
    delete library;
    delete emptyPlaylist;

    library = generateLibrary(20, 3, 8);
    filledPlaylist = generateEmptyPlaylist();
    fillPlaylist(library, filledPlaylist);
    clearTest(filledPlaylist);
    delete library;
    delete filledPlaylist;
    
    library = generateLibrary(10, 3, 8);
    filledPlaylist = generateEmptyPlaylist();
    fillPlaylist(library, filledPlaylist);
    findTest(library, filledPlaylist);
    delete library;
    delete filledPlaylist;

    library  = generateLibrary(50, 1, 10);
    randomPlaylistTest(library);
    delete library;
    library = nullptr;
    emptyPlaylist = filledPlaylist = nullptr;

}

int main() {
    printTestTitle("Playlist Tests");
    runAllPlaylistTests();
    return 0;
}
