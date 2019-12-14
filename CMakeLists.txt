cmake_minimum_required(VERSION 3.10)
project(auto-dj)

set(CMAKE_CXX_STANDARD 11)

add_executable(
    auto-dj
    UserInterface.cpp
    UserInterface.h
    AutoDJ.cpp
    AutoDJ.h
    FileManager.cpp
    FileManager.h
    Playlists.cpp
    Playlists.h
    Playlist.cpp
    Playlist.h
    Library.cpp
    Library.h
    Song.cpp
    Song.h
    LinkedNode.inl
    LinkedNode.h
    LinkedQueue.inl
    LinkedQueue.h
    ArrayList.inl
    ArrayList.h
    List.h
    Queue.h
)
