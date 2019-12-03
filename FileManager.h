//
// Created by dxuma on 11/19/2019.
//

#ifndef AUTO_DJ_FILEMANAGER_H
#define AUTO_DJ_FILEMANAGER_H

#include <string>

class FileManager{
private:
    /**
     * name of the file
     */
    std::string fileName;

    /**
     * checks the string if its the same as the one to read
     */
    std::string stringToCheck;

public:
    /**
     * displays the string to read
     * @param fileName name of the file
     * @param stringToRead the given string to read
     */
    void readToFile(std::string fileName, std::string stringToRead);

    /**
     * writes the string into the file
     * @param fileName name of the file
     * @param stringToWrite the given string to write into the file
     */
    void writeToFile(std::string fileName, std::string stringToWrite);

};

#endif //AUTO_DJ_FILEMANAGER_H
