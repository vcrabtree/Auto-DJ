//
// Created by dxuma on 11/29/2019.
//
#include "UserInterface.h"
#include "Library.h"
#include "Song.h"
#include <fstream>
#include <iostream>

UserInterface::UserInterface(){
    this->arrayOfCommands = new ["library", "artist", "song", "import", "discontinue", "playlists", "playlist", "newPlaylist", "add", "remove", "playNext", "newRandom", "quit"];

}

UserInterface::~UserInterface(){
    delete[] arrayOfCommands;
}

void UserInterface::help(){
    std::string summaryArray[13] = {"displays all songs in the library", "displays all the songs of the given artist", "displays all information of the given song", "add all songs from the given file to the library",
                                                           "remove all songs from the given file from the library", "display the names of all playlists and their durations", "display all songs left in the given playlist, and the duration",
                                                           "make a new empty playlist with the given name", "add the given song to the end of the given playlist", "remove the given song from the playlist", "print all information about the next song to be played from the given playlist to the screen",
                                                           "make a new playlist with the given name, and populate it with a random group of songs that do not repeat", "save the library and all playlists and terminate execution"};
    for(int i = 0; i < 13; i++){
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
            writeToFile("library", stringToRead);
        }
    }
}

void UserInterface::discontinue(std::string fileName) {
    //loop through the file of songs to remove
    //use the remove function in library to remove the songs
    //using writeToFile rewrite an updated library file
    //if any songs are not in the library for songs to be removed display a message with the song that couldn't be removed
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