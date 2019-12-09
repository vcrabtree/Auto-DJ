#ifndef AUTO_DJ_AUTO_DJ
#define AUTO_DJ_AUTO_DJ

#include "Library.h"
#include "Playlists.h"
#include "FileManager.h"

class AutoDJ {
    private:
        Library *library;
        Playlists *playlists;
        FileManager *fileManager;

    public:
        AutoDJ();

        ~AutoDJ();

        void library();

        void artist(std::string artist);

        void song(std::string artist, std::string title);

        void import(std::string fileName);

        void playlists();

        void playlist(std::string playlistName);

        void newPlaylist(std::string name);

        void add(std::string name, std::string artist, std::string title);

        void remove(std::string name, std::string artist, std::string title);

        void playNext(std::string playlistName);

        void newRandom(std::string playlistName, float duration);
}

#endif
