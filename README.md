# Auto-DJ
This program is an automated DJ program. There is a user interface that allows the user to perform tasks such as adding songs to a library, creating a random playlist of songs, and saving any library and playlists to a text file created once the user quits the program. This was all done using C++ and was created for my Introduction to Data Strcutures course at Ithaca College.
## Interface Commands
- `help`: Provides a summary of all available commands
- `library`: Displays all songs in alphabetical order by artist (within artist alphabetical by song)
- `artist<artist>`: Displays all songs for the given artist
- `song <artist, title>`: Displays all information for the given song
- `import <filename>`: Adds all songs from the given file to the library, prints message to the user of any songs that already exist (does not add duplicates)
- `discontinue <filename>`: Removes all songs from the given file from the library, removes these songs from any playlist in which they occur, prints a message to the user of any songs that were not present (could not be removed)
- `playlists`: Displays the names of all playlists and their durations
- `playlist <name>`: Displays all songs left in the given playlist and the duration (time it will take to play the remaining songs)
- `new <name>`: Makes a new empty playlist with the given name
- `add <name, artist, title>`: Adds the given song to the end of the given playlist
- `remove <name, artist, title>`: Removes the given song from the playlist
- `playnext <name>`: Prints all information about the next song to be played from the given playlist to the screen, removes that song from the given playlist adds to the playcount for that song in the library if the playlist is now empty, it will be removed
- `newrandom <name, duration>`: Makes a new playlist with the given name, and populate it with a random group of songs that do not repeat (within this playlist) and are in some shuffled order (ex. if the same random songs were chosen for another playlist, they will not play in the same order each time), the playlist will have as many songs as can fit without going over the the given duration
- `quit`: Save the library and all playlists and terminate execution
