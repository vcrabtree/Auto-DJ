//
// Created by dxuma on 11/24/2019.
//
#include <string>
#include <iostream>
#include "FileManager.h"


void writeTest(std::string file){
    std::cout << "\nWrite to Text File Test: ";
    for (int i = 0; i < 10; i++){
        writeToFile(file, std::to_string(i));
    }
}

void readTest(std::string file){

}




void runAllFileManagerTests(){
    std::string testFile = "testFile.txt";
    writeTest(testFile);
    readTest(testFile);
}

int main(){
    std::cout << "\n\n======================= FileManager Tests ===========================\n\n" << std::endl;
    runAllFileManagerTests();
    return 0;
}
