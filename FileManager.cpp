//
// Created by dxuma on 11/24/2019.
//
#include <fstream>
#include <iostream>
#include "FileManager.h"

void FileManager::readToFile(std::string fileName, std::string stringToRead){
    std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            std::string stringToCheck;
            getline(infile, stringToCheck);
            if (stringToCheck == stringToRead){
                std::cout << stringToCheck << std::endl;
            }
        }
    }
    else {
        std::cout << "File not found" << std::endl;
    }
}

void FileManager::writeToFile(std::string fileName, std::string stringToWrite){
    std::ofstream outf(fileName);
    if (outf){
        outf << stringToWrite;
        outf.close();
    }
    else{
        std::cerr << "Can't write to file" << std::endl;
    }
}

