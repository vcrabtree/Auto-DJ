//
// Created by dxuma on 11/24/2019.
//
#include <fstream>
#include <iostream>
#include "FileManager.h"

std::string FileManager::readFromFile(std::string fileName){
    std::ifstream infile(fileName);
    std::string stringToWrite = "";
    if (infile) {
        while (infile) {
            std::string stringToRead;
            getline(infile, stringToRead);
            stringToWrite += stringToRead+"\n";
        }
        infile.close();
        return stringToWrite;
    } else {
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

void FileManager::appendToFile(std::string fileName, std::string stringToWrite){
    std::ofstream outf;
    outf.open(fileName, std::ios_base::app);
    if (outf){
        outf << stringToWrite;
        outf.close();
    }
    else{
        std::cerr << "Can't write to file" << std::endl;
    }
}
