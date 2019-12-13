#include "AutoDJ.h"
#include <fstream>
using namespace std;

AutoDJ::AutoDJ() {
    _library = nullptr;
    _playlists = nullptr;
    _fileManager = new FileManager();

    readSongsFile("library.txt", "initialize");
}

AutoDJ::~AutoDJ() {
    delete _library;
    delete _playlists;
    delete _fileManager;
}

void AutoDJ::readSongsFile(std::string filename, std::string operation) { 
    std::string songsString = _fileManager->readFromFile(filename);
    int songCount = 0;
    std::string **songArgs = songsStringToArray(songsString, songCount), 
        duplicates = "",
        notFound = "";

    if (operation == "import") {
        addNewSongsToLibraryFile(songArgs, songsString, songCount, duplicates);
        if (duplicates.length()) std::cout << "the following duplicates were found: \n" << duplicates << endl;
        else loadSongsToLibrary(songArgs, songCount);
    } 
    else if (operation == "discontinue") {
        removeSongsFromLibraryAndRewrite(songArgs, songsString, songCount, notFound);
        if (notFound.length()) std::cout << "the following songs do not exist: \n" << notFound << endl;
    } 
    else if (operation == "initialize") {
        _library = new Library(songCount);
        loadSongsToLibrary(songArgs, songCount);
    }
}

void AutoDJ::loadSongsToLibrary(std::string **songArgs, int songCount) {
        std::cout << "loading " << songCount << " songs..." << std::endl;
        std::string *currArgs;
        Song *song;
        for (int i = 0; i < songCount; i++) {
            currArgs = songArgs[i];
            song = new Song(currArgs[0], currArgs[1], std::stof(currArgs[2]));
            std::cout << song->getTitle() << endl;
            _library->add(song);
        }
        currArgs = nullptr;
        std::cout << "\ndone\n\n";
}
void AutoDJ::addNewSongsToLibraryFile(std::string **songArgs, std::string &songsString, int songCount, std::string &duplicates) {
    std::cout << "checking for duplicate songs..." << std::endl;
    std::string *currArgs;
    for (int i = 0; i < songCount; i++) {
        currArgs = songArgs[i];
        if (_library->find(currArgs[0], currArgs[1]) >= 0) {
           duplicates += currArgs[0]+"\n"+currArgs[1]+"\n\n";
        }
    } 
    currArgs = nullptr;
    if (duplicates.length()) return;
    _fileManager->appendToFile("library.txt", songsString);  
}

void AutoDJ::removeSongsFromLibraryAndRewrite(std::string **songArgs, std::string &songsString, int songCount, std::string &notFound) {
    std::cout << "checking that songs exist..." << std::endl;
    std::string *currArgs;
    for (int i = 0; i < songCount; i++) {
        currArgs = songArgs[i];
        if (_library->find(currArgs[0], currArgs[1]) < 0) {
           notFound += currArgs[0]+"\n"+currArgs[1]+"\n\n";
        }
    } 
    if (notFound.length()) return;

    std::cout << "removing " << songCount << " songs..." << std::endl;
    Song *song;
    for (int i = 0; i < songCount; i++) {
        currArgs = songArgs[i];
        song = _library->remove(currArgs[0], currArgs[1]);
        std::cout << song->getTitle() << endl;
        delete song;
    }
    song = nullptr;
    currArgs = nullptr;
    std::cout << "\ndone\n\n";

    _fileManager->writeToFile("library.txt", _library->toFileString());
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

void AutoDJ::import(std::string filename) {
    readSongsFile(filename, "import");
}

void AutoDJ::discontinue(std::string filename) {
    readSongsFile(filename, "discontinue");
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
void AutoDJ::playNext(std::string playlistName) {

}

void AutoDJ::newRandom(std::string title, float duration) {
    _playlists->add(new Playlist(title, duration, *_library));
}
