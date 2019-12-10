#include "AutoDJ.h"

AutoDJ::AutoDJ() {
    _library = nullptr;
    _playlists = nullptr;
    _fileManager = new FileManager();
}

AutoDJ::~AutoDJ() {
    delete _library;
    delete _playlists;
    delete _fileManager;
}

// TODO:
void AutoDJ::readLibraryFile() { 
    _fileManager->readFromFile("library.txt"); 
}

// TODO:
void AutoDJ::readPlaylistsFile() { 
    _fileManager->readFromFile("playlists.txt"); 
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

void AutoDJ::import(std::string fileName) {
    if (fileName == "library.txt") readLibraryFile();
    else if (fileName == "playlists.txt") readPlaylistsFile();
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
