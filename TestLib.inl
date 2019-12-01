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

