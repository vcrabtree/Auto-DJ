//
// Created by dxuma on 11/29/2019.
//
#include "UserInterface.h"

UserInterface::UserInterface(){
    this->arrayOfCommands = new ["library", "artist". "song", "import", "playlists", "playlist", "newPlaylist", "add", "remove", "playNext", "newRandom", "quit"];

}

UserInterface::~UserInterface(){
    delete[] arrayOfCommands;
}

void UserInterface::help(){
    for(int i = 0; i < 14; i++){
        std::cout << i << ": ";
        std::cout << arrayOfCommands[i] << cout::endl;
        //another array that holds onto the summary of the commands
        //print it along side the name of the command
    }
}

void UserInterface::library() {
    //call getLength from library class
    //create a for loop of length library
    //call readFromFile on "library.txt" in the for loop
}

void UserInterface::artist(std::string artist) {
    //create a for loop the size of the library length
    //use the find function in library to search for the artist
    //use the readFromFile to print the songs for that given artist
}

void UserInterface::song(std::string artist, std::string title) {
    //use the find function in library to find the song index
    //use the index to turn the song into a string
    //print the song
}

void UserInterface::import(std::string fileName) {
    //loop through the file of songs to add
    //Use the writeToFile function
    //using the strings taken from the file of songs to add
    //add to the library file
}

void UserInterface::discontinue(std::string fileName) {
    //loop through the file of songs to remove
    //use the remove function in library to remove the songs
    //using writeToFile rewrite an updated library file
    //if any songs are not in he library for songs to be removed display a message with the song that couldn't be removed
}

void UserInterface::playlists() {
    //loop through the playlists file
    //use readFromFile to display all the names of the playlists and print the duration
}

void UserInterface::playlist(std::string playlistName){
    //as each song is being played in a given playlist subtract that song duration form the total play duration
    //loop through the playlist past the current song playing to display all the remaining songs using readFromFile
}

void UserInterface::newPlaylist(std::string name) {
    //call the constructor of Playlist.cpp
}

void UserInterface::add(std::string name, std::string artist, std::string title) {
    //call the add function in playlist to add the song given by the user
}

void UserInterface::remove(std::string name, std::string artist, std::string title) {
    //call the remove function from playlist to remove the song given by the user
}

void UserInterface::playNext(std::string playlistName) {
    //get the next index of the song that needs to be played and print out the information of the song
    //call remove on that song
    //increment the play count of that song in library
    //If playlist isEmpty delete the playlist
}

void UserInterface::newRandom(std::string playlistName, float duration) {
    //call the newRandom function in playlist
}

void UserInterface::quit() {
    //delete the file for songs to add and songs to remove
    //keep the library and playlist file
}