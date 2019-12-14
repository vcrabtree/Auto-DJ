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

void help(){
    std::string arrayOfCommands[14] = {"help", "library", "artist", "song", "import", "discontinue", "playlists", "playlist", "newPlaylist", "add", "remove", "playNext", "newRandom", "quit"};
    std::string summaryArray[14] = {"displays the summary of the given commands", "displays all songs in the library", "displays all the songs of the given artist", "displays all information of the given song", "add all songs from the given file to the library",
                                    "remove all songs from the given file from the library", "display the names of all playlists and their durations", "display all songs left in the given playlist, and the duration",
                                    "make a new empty playlist with the given name", "add the given song to the end of the given playlist", "remove the given song from the playlist", "print all information about the next song to be played from the given playlist to the screen",
                                    "make a new playlist with the given name, and populate it with a random group of songs that do not repeat", "save the library and all playlists and terminate execution"};
    for(int i = 0; i < 14; i++){
        std::cout << i << ": ";
        std::cout << arrayOfCommands[i];
        std::cout << " - ";
        std::cout << summaryArray[i] << std::endl;
    }
}

void displayMenu() {
    std::string arrayOfCommands[14] = {"help", "library", "artist", "song", "import", "discontinue", "playlists", "playlist", "newPlaylist", "add", "remove", "playNext", "newRandom", "quit"},
        prompt = "\nPlease enter the number corresponding to the command you want to use.";
    for (int i = 0; i < prompt.length(); i++) std::cout << "-";
    std::cout << std::endl;
    for (int i = 0; i < 14; i++) {
        std::cout << i << ": ";
        std::cout << arrayOfCommands[i] << std::endl;
    }
    for (int i = 0; i < prompt.length(); i++) std::cout << "-";
    std::cout << prompt << std::endl;
}

int main(){
    AutoDJ* dj = new AutoDJ();
    std::cout << "Welcome to AutoDJ!" << std::endl;
    std::cout << "List of Commands: " << std::endl;
    int commandToUse;
    bool inUse = true;
    bool start = true;
    while (inUse == true) {
        std::string title;
        std::string artist;
        std::string fileName;
        std::string playlistName;
        std::string output;
        float duration;

        displayMenu();
        while(!(std::cin >> commandToUse)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "**Invalid input, try again.**" << std::endl << std::endl;
            displayMenu();
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
                std::cin.ignore();
                std::cout << "What is the name of the artist?" << std::endl;
                getline(std::cin, artist);
                output = dj->artist(artist);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 3:
                std::cin.ignore();
                std::cout << "What is the name of the artist?" << std::endl;
                getline(std::cin, artist);
                std::cout << "What is the title of the song?" << std::endl;
                getline(std::cin, title);
                output = dj->song(title, artist);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 4:
                std::cin.ignore();
                std::cout << "What is the name of the file?" << std::endl;
                getline(std::cin, fileName);
                dj->import(fileName);
                start = false;
                inUse = true;
                break;
            case 5:
                std::cin.ignore();
                std::cout << "What is the name of the file?" << std::endl;
                getline(std::cin, fileName);
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
                std::cin.ignore();
                std::cout << "What is the playlists name?" << std::endl;
                getline(std::cin, playlistName);
                output = dj->playlist(playlistName);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 8:
                std::cin.ignore();
                std::cout << "What is the name of this new playlist?" << std::endl;
                getline(std::cin, playlistName);
                output = dj->newPlaylist(playlistName);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 9:
                std::cin.ignore();
                std::cout << "What name of the playlist that you would like to add the song to?" << std::endl;
                getline(std::cin, playlistName);
                std::cout << "What is the artist of the song?" << std::endl;
                getline(std::cin, artist);
                std::cout << "What is the title of the song?" << std::endl;
                getline(std::cin, title);
                output = dj->add(playlistName, title, artist);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 10:
                std::cin.ignore();
                std::cout << "What is the playlist that you would like to remove a song from?" << std::endl;
                getline(std::cin, playlistName);
                std::cout << "What is the artist of the song?" << std::endl;
                getline(std::cin, artist);
                std::cout << "What is the title of the song?" << std::endl;
                getline(std::cin, title);
                output = dj->remove(playlistName, title, artist);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 11:
                std::cin.ignore();
                std::cout << "What is the name of the playlist?" << std::endl;
                getline(std::cin, playlistName);
                output = dj->playNext(playlistName);
                std::cout << output << std::endl;
                start = false;
                inUse = true;
                break;
            case 12:
                std::cin.ignore();
                std::cout << "What is the name of this new random playlist?" << std::endl;
                getline(std::cin, playlistName);
                std::cout << "What is the duration of this playlist?" << std::endl;
                std::cin >> duration;
                dj->newRandom(playlistName, duration);
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
        std::cout << "\n\n";
    }
    return 0;
}
