#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>

void printTestTitle(std::string title);

void printTestHeader(std::string title);

void printTestCase(std::string _case);

void printTestFooter();

void printExceptionFail(std::string name, bool shouldCatch=true);

template <typename T>
void printAssert(T value, T expected);

void printPass();

void printFail();

Library* generateLibrary(int size, int minSongMinute, int maxSongMinute);

Playlist* generateEmptyPlaylist(std::string title="");

Playlists* generateEmptyPlaylists(int initialCapacity);

void fillPlaylist(Library *library, Playlist *emptyPlaylist);

void fillPlaylists(Library *library, Playlists *emptyPlaylists, int size, std::string *titles=nullptr);

#include "TestLib.inl"

#endif
