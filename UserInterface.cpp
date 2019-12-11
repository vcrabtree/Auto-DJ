//
// Created by dxuma on 11/29/2019.
//
#include "UserInterface.h"
#include "Library.h"
#include "Song.h"
#include <fstream>
#include <iostream>
#include "AutoDJ.h"

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

void UserInterface::library() {
    int length = libraryList->getLength;
    for(int i = 0; i < length; i++){
        std::string songString = (libraryList->getSongAt(i))->toString;
        readFromFile("library.txt", songString);
    }
}

void UserInterface::artist(std::string artist) {
    std::string listOfSongs = libraryList->findByArtist(artist);
    std::cout << listOfSongs << std::endl;
}

void UserInterface::song(std::string artist, std::string title) {
    int songIndex = libraryList->find(title, artist);
    std::string songString = (libraryList.getSongAt(songIndex)).toString;
    std::cout << songString << std::endl;
}

void UserInterface::import(std::string fileName) {
    std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            std::string stringToRead;
            getline(infile, stringToRead);
            writeToFile("library.txt", stringToRead);
        }
    }
}

void UserInterface::discontinue(std::string fileName) {
    std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            std::string stringTitle;
            getline(infile, stringTitle);
            std::string stringArtist;
            getline(infile, stringArtist);
            try{
                _library->remove(stringTitle, stringArtist);
            }
            catch(std::out_of_range &e){
                printAssert(*"There is no item at this index", *e.what());
            }
        }
    }
    for (int i = 0; i < _library->getLength; i++){
        writeToFile("library.txt", _library->getSongAt(i));
    }
}

void UserInterface::playlists() {
    int length = playlistList->getLength();
    for(int i = 0; i < length; i++){
        readFromFile("playlists.txt");
    }
}

void UserInterface::playlist(std::string playlistName){
    //as each song is being played in a given playlist subtract that song duration form the total play duration
    //loop through the playlist past the current song playing to display all the remaining songs using readFromFile
}

void UserInterface::newPlaylist(std::string name) {
    Playlist playlist = new Playlist(name);
}

void UserInterface::add(float duration, std::string artist, std::string title) {
    Song newSong = new Song(title, artist, duration);
    libraryList->add(newSong);
}

void UserInterface::remove(float duration, std::string artist, std::string title) {
    libraryList->remove(tile, artist);
}

void UserInterface::playNext(std::string playlistName) {
    //get the next index of the song that needs to be played and print out the information of the song
    //call remove on that song
    //increment the play count of that song in library
    //If playlist isEmpty delete the playlist
}

void UserInterface::newRandom(std::string playlistName, float duration) {
    Playlist randomPlaylist = new Playlist(playlistName, duration);
    //call the newRandom function in playlist
}

void UserInterface::quit() {

    //delete the file for songs to add and songs to remove
    //keep the library and playlist file
}

void main(){
    std::cout << "Welcome to AutoDJ!" << std::endl;
    std::cout << "List of Commands: " << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << i << ": ";
        std::cout << arrayOfCommands[i];
    }
    std::cout << "Please enter the number corresponding to the command you want to use." << std::endl
    int commandToUse;
    std::cin << commandToUse;
    bool inUse = true;
    bool start == true;
    while (inUse == true){
        if (start != true){
            std::cout << "What else would you like to do?"
        }
        if (commandToUse == 0){
            help();
            start = false;
        }
        else if (commandToUse == 1){
            library();
            start = false;
        }
        else if (commandToUse == 13){
            std::cout << "Saving files..." << std::endl;
            quit();
            std::cout << "Thank You for using AutoDJ" << std::endl;
            inUse == false;
        }
    }
}