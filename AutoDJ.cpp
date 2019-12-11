#include "AutoDJ.h"
#include <fstream>
using namespace std;

AutoDJ::AutoDJ() {
    _library = nullptr;
    _playlists = nullptr;
    _fileManager = new FileManager();

    readSongsFile("library.txt");
}

AutoDJ::~AutoDJ() {
    delete _library;
    delete _playlists;
    delete _fileManager;
}

void AutoDJ::readSongsFile(std::string filename) { 
    std::string songsString = _fileManager->readFromFile(filename);
    int songCount = 0;
    std::string **songArgs = songsStringToArray(songsString, songCount),
                *currArgs,
                duplicates = "";

    if (filename == "new_songs.txt") {
        std::cout << "checking for duplicate songs.." << std::endl;
        for (int i = 0; i < songCount; i++) {
            currArgs = songArgs[i];
            if (_library->find(currArgs[0], currArgs[1]) >= 0) {
               duplicates += currArgs[0]+"\n"+currArgs[1]+"\n\n";
            }
        } 
        if (!duplicates.length()) _fileManager->appendToFile("library.txt", songsString);  
    } else if (filename == "library.txt") _library = new Library(songCount);

    if (duplicates.length()) {
        std::cout << "the following duplicates were found: \n" << duplicates << endl;
    } else {
        std::cout << "loading " << songCount << " songs..." << std::endl;
        Song *song;
        for (int i = 0; i < songCount; i++) {
            currArgs = songArgs[i];
            song = new Song(currArgs[0], currArgs[1], std::stof(currArgs[2]));
            std::cout << song->getTitle() << endl;
            _library->add(song);
        }
        std::cout << "\ndone\n\n";
    }
}

std::string** AutoDJ::songsStringToArray(std::string songsString, int &songCount) {
    std::string **songArgs,
        currBlock = "",
        currChar = "";
    int argSep = 0, 
        songArgsIdx = 0;

    for (int i = 0; i < songsString.length(); i++) {
        if (songsString[i] == *";") songCount++;
    }
    songArgs = new std::string*[songCount];

    for (int i = 0; i < songsString.length(); i++) {
        currChar = songsString[i];
        // build block to ;
        if (currChar != ";" && currChar != "\n") currBlock += currChar;
        else if (currChar == ";") {
            std::string *args = new std::string[3],
                currArg = "";
            for (int j = 0; argSep < 3; j++) {
                if (currBlock[j] != *"~") currArg += currBlock[j];
                else {
                    args[argSep++] = currArg;
                    currArg = "";
                }
            }
            songArgs[songArgsIdx++] = args;
            currBlock = "";
            argSep = 0;
        }
    }
    return songArgs;
}

// TODO:
void AutoDJ::readPlaylistsFile() { 
    //_fileManager->readFromFile("playlists.txt"); 
}

std::string AutoDJ::library() { 
    return _library->toString(); 
}

std::string AutoDJ::artist(std::string artist) {
    return _library->findByArtist(artist);
}

std::string AutoDJ::song(std::string title, std::string artist) {
    return _library->findBySong(title, artist);
}

std::string AutoDJ::playlists() { 
    return _playlists->allPlaylistsString(); 
}

std::string AutoDJ::playlist(std::string title) {
    return _playlists->playlistString(title);
}

void AutoDJ::import() {
    readSongsFile("new_songs.txt");
}

void AutoDJ::discontinue(std::string fileName) {
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
                //"There is no item at this index";
            }
        }
    }
    _fileManager->writeToFile("library.txt", _library->toFileString());
}
void AutoDJ::newPlaylist(std::string name) { 
    _playlists->add(new Playlist(name)); 
}

void AutoDJ::add(std::string name, std::string artist, std::string title) {
    Song *song = _library->getSong(title, artist);
    Playlist *playlistFound = _playlists->getPlaylist(name);
    if (song && playlistFound) playlistFound->add(song);
}

void AutoDJ::remove(std::string name, std::string artist, std::string title) {
    Playlist *playlistFound = _playlists->getPlaylist(name);
    if (playlistFound) playlistFound->remove(title, artist);
}

// TODO
void AutoDJ::playNext(std::string playlistName) {}

void AutoDJ::newRandom(std::string title, float duration) {
    _playlists->add(new Playlist(title, duration, *_library));
}
