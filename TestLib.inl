#include "Library.h"
#include "TestLib.h"

void printTestTitle(std::string title) {
    std::cout << "\n======================="+title+"===========================\n" << std::endl;
}
void printTestHeader(std::string title) {
    std::cout << "----------" << title << "----------" << std::endl;
}

void printTestCase(std::string _case) {
    std::cout << "---" << _case << "---" << std::endl;
}

void printTestFooter() {
    std::cout << "----done----\n" << std::endl;
}

void printExceptionFail(std::string name, bool shouldCatch) {
    std::string status = "' threw exception'";
    if (shouldCatch) status = "' did not throw exception'";
    std::cout << "FAIL: '" << name << status << std::endl;
}

template <typename T>
void printAssert(T value, T expected) {
    std::string result = value != expected ? "fail" : "pass";
    std::cout << result << std::endl;
}

void printPass() { std:: cout << "pass" << std::endl; }

void printFail() { std:: cout << "fail" << std::endl; }

Library* generateLibrary(int size, int minSongMinute, int maxSongMinute) {
    Library *library = new Library(size);
    std::string title, artist;

    float minute = (float)minSongMinute, seconds = 0.0f, currDuration = 0.0f;
    for (int i = 0, s = 1, m = minSongMinute; i < size; i++, m++, s++) {
        if (currDuration >= maxSongMinute) {
            minute = minSongMinute;
            m = s = 0;
        } 
        seconds = (float)(s*s)/10;
        currDuration = minute+seconds;

        title = "title "+std::to_string(i);
        artist = "artist "+std::to_string(i);
        library->add(new Song(title, artist, currDuration));
    }
    return library;
}

Playlist* generateEmptyPlaylist(std::string title) {
    title = title.length() ? title : "playlist";
    return new Playlist(title);
}

Playlists* generateEmptyPlaylists(int initialCapacity) {
    return new Playlists(initialCapacity);
}

void fillPlaylist(Library *library, Playlist *emptyPlaylist) {
    for (int i = 0; i < library->getLength(); i++)
        emptyPlaylist->add( library->getSongAt(i) );
}

void fillPlaylists(Library *library, Playlists *emptyPlaylists, int size, std::string *titles) {
    Playlist *playlist;
    std::string title;
    for (int i = 1; i <= size; i++) {
        title = "title "+std::to_string(i);
        playlist = new Playlist(title, (float)(i*i), *library);
        emptyPlaylists->add(playlist);
        if (titles) titles[i-1] = title;
    }
}


