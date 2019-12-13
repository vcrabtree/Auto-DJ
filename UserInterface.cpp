//
// Created by dxuma on 11/29/2019.
//
#include "UserInterface.h"
#include "Library.h"
#include "Song.h"
#include <fstream>
#include <iostream>
#include "AutoDJ.h"
#include <limits>

UserInterface::UserInterface(){
    this->arrayOfCommands = new ["help", "library", "artist", "song", "import", "discontinue", "playlists", "playlist", "newPlaylist", "add", "remove", "playNext", "newRandom", "quit"];

}

UserInterface::~UserInterface(){
    delete[] arrayOfCommands;
}

void help(){
    std::string summaryArray[14] = {"displays the summary of the given commands", "displays all songs in the library", "displays all the songs of the given artist", "displays all information of the given song", "add all songs from the given file to the library",
                                                           "remove all songs from the given file from the library", "display the names of all playlists and their durations", "display all songs left in the given playlist, and the duration",
                                                           "make a new empty playlist with the given name", "add the given song to the end of the given playlist", "remove the given song from the playlist", "print all information about the next song to be played from the given playlist to the screen",
                                                           "make a new playlist with the given name, and populate it with a random group of songs that do not repeat", "save the library and all playlists and terminate execution"};
    for(int i = 0; i < 14; i++){
        std::cout << i << ": ";
        std::cout << arrayOfCommands[i];
        std::cout << " - ";
        std::cout << summaryArray[i] std::endl;
    }
}

void main() {
    std::cout << "Welcome to AutoDJ!" << std::endl;
    std::cout << "List of Commands: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << ": ";
        std::cout << arrayOfCommands[i];
    }
    std::cout << "Please enter the number corresponding to the command you want to use." << std::endl
    AutoDJ *dj = new AutoDJ;
    int commandToUse;
    std::cin << commandToUse;

    bool inUse = true;
    bool start == true;
    while (inUse == true) {
        std::string title;
        std::string artist;
        std::string fileName;
        std::string playlistName;
        std::string output;
        if (start != true) {
            std::cout << "What else would you like to do?" << std::endl;
            std::cin >> commandToUse;
        }
        while(!(std::cin >> commandToUse)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, try again." << std::endl;
        }
        switch (commandToUse) {
            case 0:
                help();
                start = false;
                inUse = true;
                break;
            case 1:
                output = dj->library();
                std::cout << output << std::endl;
                start = false;
                break;
            case 2:
                std::cout << "What is the name of the artist?" << std::endl;
                std::cin >> artist;
                output = dj->artist(artist);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 3:
                std::cout << "What is the name of the artist?" << std::endl;
                std::cin >> artist;
                std::cout << "What is the title of the song?" << std::endl;
                std::cin >> title;
                output = dj->song(title, artist);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 4:
                std::cout << "What is the name of the file?" << std::endl;
                std::cin >> fileName;
                dj->import(fileName);
                start = false;
                inUse = true;
                break;
            case 5:
                std::cout << "What is the name of the file?" << std::endl;
                std::cin >> fileName;
                dj->discontinue(fileName);
                start = false;
                inUse = true;
                break;
            case 6:
                output = dj->playlists();
                std::cout << output << std::endl;
                inUse = true;
                break;
            case 7:
                std::cout << "What is the playlists name?" << std::endl;
                std::cin >> playlistName;
                output = dj->playlist(playlistName);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 8:
                std::cout << "What is the name of this new playlist?" << std::endl;
                std::cin >> playlistName;
                output = dj->newPlaylist(playlistName);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 9:
                std::cout << "What name of the playlist that you would like to add the song to?" << std::endl;
                std::cin >> playlistName;
                std::cout << "What is the artist of the song?" << std::endl;
                std::cin >> artist;
                std::cout << "What is the title of the song?" << std::endl;
                std::cin >> title;
                dj->add(playlistName, title, artist);
                start = false;
                inUse = true;
                break;
            case 10:
                std::cout << "What is the playlist that you would like to remove a song from?" << std::endl;
                std::cin >> playlistName;
                std::cout << "What is the artist of the song?" << std::endl;
                std::cin >> artist;
                std::cout << "What is the title of the song?" << std::endl;
                std::cin >> title;
                dj->remove(playlistName, title, artist);
                start = false;
                inUse = true;
                break;
            case 11:
                std::cout << "What is the name of the playlist?" << std::endl;
                std::cin >> playlistName;
                output = dj->playNext(playlistName);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 12:
                std::cout << "What is the name of this new random playlist?" << std::endl;
                std::cin >> playlistName;
                dj->newRandom(playlistName);
                start = false;
                inUse = true;
                break;
            case 13:
                std::cout << "Saving..." << std::endl;
                delete dj;
                std::cout << "Thank you for using AutoDJ!" << std::endl;
                start = false;
                inUse = false;
                break;
            default:
                std::cout << "Invalid input. Please try again" << std::endl;
                start = false;
                inUse = true;
                break;
        }
    }
    return 0;
}