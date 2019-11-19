//
// Created by dxuma on 11/19/2019.
//

#ifndef AUTO_DJ_USERINTERFACE_H
#define AUTO_DJ_USERINTERFACE_H

class UserInterface{
private:
    /**
     * array with functions of commands
     */
    int* arrayOfCommands;

public:
    /**
     * constructor
     * @param there are only 14 given commands
     */
    UserInterface(14);

    /**
     * destructor
     */
    ~UserInterface();

    /**
     * Provide a summary of all available commands
     */
    void help();

    /**
     * Display all songs in alphabetical order by artist (within artist alphabetical by song)
     */
    void library();

    /**
     * Display all songs for the given artist
     * @param artist to search for
     */
    void artist(std::string artist);

    /**
     * Display all information for the given song
     * @param artist name of the person
     * @param title name of the song
     */
    void song(std::string artist, std::string title);

    /**
     * Add all songs from the given file to the library. Print message to the user of any songs that already existed (do not add duplicates)
     * @param fileName name of the file with the songs to add to the library file
     */
    void import(std::string fileName);

    /**
     * Display the names of all playlists and their durations
     */
    void playlists();

    /**
     * Display all songs left in the given playlist, and the duration (time it will take to play the remaining songs)
     * @param playlistName name of the playlist to display
     */
    void playlist(std::string playlistName);

    /**
     * Display all songs left in the given playlist, and the duration (time it will take to play the remaining songs)
     * @param name new name of the newly added playlist
     */
    void newPlaylist(std::string name);

    /**
     * Add the given song to the end of the given playlist
     * @param name of the song
     * @param artist of the song
     * @param title of the song
     */
    void add(std::string name, std::string artist, std::string title);

    /**
     * Remove the given song from the playlist
     * @param name of the song
     * @param artist of the song
     * @param title of the song
     */
    void remove(std::string name, std::string artist, std::string title);

    /**
     * Print all information about the next song to be played from the given playlist to the screen. Remove that song from the given playlist.
     * Add to the playCount for that song in the library. If the playlist is now empty, it should be removed.
     * @param playlistName name of the playlist
     */
    void playNext(std::string playlistName);

    /**
     * Make a new playlist with the given name, and populate it with a random group of songs that do not repeat (within this playlist) and are in some shuffled order
     * (i.e., if the same random songs were chosen for another playlist, they should not play in the same order each time).
     * The playlist should have as many songs as can fit without going over the the given duration.
     * @param playlistName name of the given playlist
     * @param duration total play time of the playlist
     */
    void newRandom(std::string playlistName, float duration);

    /**
     * Save the library and all playlists and terminate execution.
     */
    void quit();

};
#endif //AUTO_DJ_USERINTERFACE_H
