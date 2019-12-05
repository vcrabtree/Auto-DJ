#include "Playlists.h"

Playlists::Playlists(int initialCapacity) {
    playlistList = new ArrayList<Playlist>(initialCapacity);
}

Playlists::~Playlists() { clear(); }

void Playlists::add(Playlist* playlist) { playlistList->add(playlist); }

Playlist* Playlists::remove(std::string title) { return playlistList->remove(title); }

int Playlists::find(std::string title) { return playlistList->find(title); }

std::string Playlists::displayPlaylist(std::string title) { 
    int index = playlistList->find(title);
    return playlistList->getItemAt(index)->toString(); 
}

std::string Playlists::displayAllPlaylists() {
    std::string playlistsString = "";
    Playlist* playlist;
    for (int i = 0; i < playlistList->getLength(); i++) {
        playlist = playlistList->getItemAt(i);
        playlistsString += "title: "+playlist->getTitle()+
                           "\t("+std::to_string(playlist->getDuration())+")";
    }
    playlist = nullptr;
    return playlistsString;
};

void Playlists::clear() {  };

bool Playlists::isEmpty() { return playlistList->isEmpty(); }

int Playlists::getLength() { return playlistList->getLength(); }
