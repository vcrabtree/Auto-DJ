#include <iostream>
#include "Song.h"
#include "Library.h"
#include "Playlist.h"
#include "TestLib.h"

Playlist* generateRandomPlaylist(std::string title, float duration, int libSize ) {
    Library *library = new Library();
    Playlist *randomPlaylist;

    float currDuration;
    for (int i = 0; i < libSize; i++) {
        currDuration = 2.0f+(float)i/10;
        if (currDuration > 2.59) currDuration = 3.0f;
        library->add(
         new Song("title "+std::to_string(i), 
                 "artist "+std::to_string(i), 
                 currDuration
         ), i);
    }
    randomPlaylist = new Playlist(title, duration, *library);
    delete library;
    library = nullptr;

    return randomPlaylist;
}

Playlist* generateEmptyPlaylist() { 
    return new Playlist("empty playlist"); 
}

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
    printTestCase("protect against duplicate songs");
    for (int i = 0; i < songsToAdd; i++) {
        try {
            playlist->add(
                new Song("title "+std::to_string(i+1), 
                         "artist "+std::to_string(i+1),
                         i+1
            ));
            printExceptionFail("able to add duplicate song");
        } catch(std::invalid_argument e) {
            printAssert(*("duplicate songs are not allowed"), *e.what());
        }
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

void randomPlaylistTest() {
    printTestHeader("randomPlaylistTest");
 
    printTestCase("random generated playlist doesn't exceed desired duration");
    Playlist *randPlaylist;
    float desiredDuration;
    int desiredLibSongCount;
    for (int i = 1; i < 5; i++){
        desiredDuration = i+1;
        randPlaylist = generateRandomPlaylist("rand-pl"+std::to_string(i), i+1, i*i);
        printAssert(randPlaylist->getDuration() <= desiredDuration, true);
        delete randPlaylist;
    }

    printTestCase("random playlist doesn't generate for invalid durations");
    for (int i = 0; i > -4; i--){
        desiredDuration = i+1;
        try {
            randPlaylist = generateRandomPlaylist("rand-pl"+std::to_string(i), i, 5);
            delete randPlaylist;
            printExceptionFail("random playlist generated with duration <= 0");
        } catch(std::invalid_argument e) {
            printAssert(*("invalid duration"), *e.what());
        }
    }
    randPlaylist = nullptr;

    printTestFooter();
}

void findTest(Playlist* playlist) {
    printTestHeader("findTest");

    int length = playlist->getLength();
    Song *songs[length] = {};
    for (int i = 0; i < length; i++) songs[i] = playlist->getSongAt(i);

    printTestCase("find non-existent songs");
    for (int i = 0; i < length; i++) printAssert(playlist->find(""+i, ""+i+1), -1);

    printTestCase("find existing songs");
    std::string currTitle, currArtist;
    for (int i = 0; i < length; i++) {
        currTitle = songs[i]->getTitle();
        currArtist = songs[i]->getArtist();
        printAssert(playlist->find(currTitle, currArtist), i);
    } 

    printTestFooter();
}

void playNextTest(Playlist* playlist) {
    printTestHeader("playNextTest");

    int length = playlist->getLength();
    float durations[length] = {};
    Song *songs[length] = {}, *currSong;
    for (int i = 0; i < length; i++) {
        currSong = playlist->getSongAt(i);
        songs[i] = currSong;
        durations[i] = currSong->getDuration();
    } 

    printTestCase("next song was current first song in playlist");
    Song* nextSong;
    for (int i = 0; i < length; i++) {
        nextSong = playlist->playNext(); 
        printAssert(nextSong, songs[i]);
    }

    printTestCase("each next songs play count is now 1");
    for (int i = 0; i < length; i++) printAssert(songs[i]->getPlayCount(), 1);

    printTestCase("playlist is now empty");
    printAssert(playlist->getLength(), 0);

    printTestCase("playlist duration is now 0");
    printAssert(playlist->getDuration(), 0.0f);

    printTestCase("re-add songs, replay, songs play counts are now 2 ");
    for (int i = 0; i < length; i++) playlist->add(songs[i]);
    for (int i = 0; i < length; i++) playlist->playNext();
    for (int i = 0; i < length; i++) printAssert(songs[i]->getPlayCount(), 2);

    printTestFooter();
}

void runAllPlaylistTests() {
    Playlist *emptyPlaylist = generateEmptyPlaylist(),
             *randomPlaylist = generateRandomPlaylist("random playlist", 15.5, 10);
    
    emptyPlaylistTest(emptyPlaylist);
    delete emptyPlaylist;

    emptyPlaylist = generateEmptyPlaylist();
    addAndGetSongAtTest(emptyPlaylist);
    delete emptyPlaylist;

    removeTest(randomPlaylist);
    delete randomPlaylist;

    randomPlaylistTest();

    randomPlaylist = generateRandomPlaylist("random playlist", 12.5, 10);
    findTest(randomPlaylist);
    delete randomPlaylist;

    randomPlaylist = generateRandomPlaylist("random playlist", 11.5, 10);
    playNextTest(randomPlaylist);
    delete randomPlaylist;

    emptyPlaylist = nullptr;
    randomPlaylist = nullptr;
}

int main() {
    printTestTitle("Playlist Tests");
    runAllPlaylistTests();
    return 0;
}
