#ifndef AUTO_DJ_AUTO_DJ
#define AUTO_DJ_AUTO_DJ

#include "Library.h"
#include "Playlists.h"
#include "FileManager.h"

class AutoDJ {
    private:
        Library *_library;
        Playlists *_playlists;
        FileManager *_fileManager;

        void readSongsFile(std::string filename);

        void readPlaylistsFile();

        std::string** songsStringToArray(std::string songsString, int &songCount);

    public:
        AutoDJ();

        ~AutoDJ();

        std::string library();

        std::string playlists();

        std::string playlist(std::string playlistName);

        std::string artist(std::string artist);

        std::string song(std::string artist, std::string title);

        void import();

        void discontinue(std::string fileName);

        void newPlaylist(std::string name);

        void add(std::string name, std::string artist, std::string title);

        void remove(std::string name, std::string artist, std::string title);

        void playNext(std::string playlistName);

        void newRandom(std::string playlistName, float duration);
};

#endif
