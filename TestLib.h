#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>

void printTestTitle(std::string title);

void printTestHeader(std::string title);

void printTestCase(std::string _case);

void printTestFooter();

void printExceptionFail(std::string name);

template <typename T>
void printAssert(T value, T expected);

Library* generateLibrary(int size, int minSongMinute, int maxSongMinute);

Playlist* generateEmptyPlaylist(std::string title="");

void fillPlaylist(Library *library, Playlist *emptyPlaylist);

#include "TestLib.inl"

#endif
