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

void printExceptionFail(std::string name) {
    std::cout << "FAIL: '" << name << "' did not throw exception" << std::endl;
}

template <typename T>
void printAssert(T value, T expected) {
    std::string result = value != expected ? "fail" : "pass";
    std::cout << result << std::endl;
}

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

void fillPlaylist(Library *library, Playlist *emptyPlaylist) {
    for (int i = 0; i < library->getLength(); i++)
        emptyPlaylist->add( library->getSongAt(i) );
}

