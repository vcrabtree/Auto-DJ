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

#include "TestLib.inl"

#endif
