//
// Created by vcrab on 11/19/2019.
//

#include "Library.h"

Library::Library() {
    front = nullptr;
    end = nullptr;
    int duration = 0;
}

Library::~Library() {
    while (front && front != end) {
        LinkedNode<Song> *tempNode = front;
        front = front->getNext();
        delete tempNode;
    }
    front = nullptr;
    end = nullptr;
}

void Library::add(Song* song, int index) {
    if (index < 0) {
        throw std::out_of_range("You cannot add a song at this index: " + std::to_string(index));
    }
    if (find(song->getTitle(), song->getArtist()) == -1) {
        if (front == nullptr) {
            LinkedNode<Song> *newNode = new LinkedNode<Song>(*song);
            front = newNode;
            end = newNode;
            newNode = nullptr;
        }
        int count = 0;
        LinkedNode<Song> *currPtr = front;
        while (currPtr != nullptr && count <= index) {
            count += 1;
            if (index == 0) {
                LinkedNode<Song> *newNode = new LinkedNode<Song>(*song);
                newNode->setNext(front);
                front = newNode;
                newNode = nullptr;
            }
            else if (currPtr->getNext() == nullptr && index == count + 1) {
                LinkedNode<Song> *newNode = new LinkedNode<Song>(*song);
                end->setNext(newNode);
                end = newNode;
                newNode = nullptr;
            }
            else if (count == index) {
                LinkedNode<Song> *newNode = new LinkedNode<Song>(*song);
                LinkedNode<Song> *tempNode = currPtr->getNext();
                currPtr->setNext(newNode);
                currPtr = newNode;
                currPtr->setNext(tempNode);
                newNode = nullptr;
                tempNode = nullptr;
            }
            else {
                currPtr = currPtr->getNext();
            }
        }
        if (index > count && currPtr == nullptr) {
            throw std::out_of_range("You cannot add a song at this index: " + std::to_string(index));
        }
        currPtr = nullptr;
        duration = duration + song->getDuration();
    }
    else {
        throw std::invalid_argument("This song already exists in this library");
    }
}

Song* Library::remove(std::string title, std::string artist) {
    if (front == nullptr) {
        throw std::out_of_range("Library is empty");
    }
    LinkedNode<Song> *currPtr = front;
//    LinkedNode<Song> *currPtrBefore = front;
    int count = 0;
    Song* songToRemove;
    if (front->getItem()->getTitle() == title) {
        songToRemove = front->getItem();
        LinkedNode<Song> *currPtr = front;
        currPtr = currPtr->getNext();
        front = currPtr;
        currPtr = nullptr;
        return songToRemove;
    }
    if (end->getItem()->getTitle() == title) {
        int count = 0;
        LinkedNode<Song> *currPtr = front;
        LinkedNode<Song> *currPtrBefore = front;
        while (currPtr->getNext() != nullptr) {
            currPtrBefore = currPtr;
            currPtr = currPtr->getNext();
            count += 1;
        }
        if (count != 0) {
            songToRemove = currPtr->getItem();
            currPtrBefore->setNext(nullptr);
        }
        else {
            songToRemove = currPtr->getItem();
            front = nullptr;
        }
        currPtrBefore = nullptr;
        currPtr = nullptr;
        return songToRemove;
    }
    while (currPtr != nullptr) {
        count += 1;
        if (currPtr->getItem()->getTitle() == title && currPtr->getItem()->getArtist() == artist) {
//            LinkedNode<Song> *beforeNodeToRemove = currPtrBefore;
//            LinkedNode<Song> *nodeToRemove = currPtr;
//            LinkedNode<Song> *afterNodeToRemove  = currPtr->getNext();
            LinkedNode<Song> *beforeNodeToRemove = currPtr;
            LinkedNode<Song> *nodeToRemove = beforeNodeToRemove->getNext();
            LinkedNode<Song> *afterNodeToRemove  = nodeToRemove->getNext();
            beforeNodeToRemove->setNext(afterNodeToRemove);
            songToRemove = nodeToRemove->getItem();
            delete nodeToRemove;
            beforeNodeToRemove = nullptr;
            afterNodeToRemove = nullptr;
            currPtr = nullptr;
            //currPtrBefore = nullptr;
            duration = duration - songToRemove->getDuration();
            return songToRemove;
        }
        else {
            currPtr = currPtr->getNext();
//            if (currPtr == front) {
//                currPtr = currPtr->getNext();
//            }
//            else {
//                currPtr = currPtr->getNext();
//                currPtrBefore = currPtr->getNext();
//            }
        }
    }
    currPtr = nullptr;
    throw std::invalid_argument("Song Not in List");
}

Song* Library::getSongAt(int index) {
    if (index < 0 || front == nullptr) {
        throw std::out_of_range("Invalid Index");
    }
    int count = 0;
    LinkedNode<Song> *currPtr = front;
    while (count != index) {
        if (currPtr->getNext() != nullptr) {
            currPtr = currPtr->getNext();
            count += 1;
        }
        else {
            throw std::out_of_range("Invalid Index");
        }
    }
    Song* songToGet = currPtr->getItem();
    currPtr = nullptr;
    return songToGet;
}

bool Library::isEmpty() {
    if (front == nullptr && end == nullptr) {
        return true;
    }
    return false;
}

void Library::clear() {
    while (front && front != end) {
        LinkedNode<Song> *tempNode = front;
        front = front->getNext();
        delete tempNode;
    }
    duration = 0;
    front = nullptr;
    end = nullptr;
}

int Library::getLength() {
    if (front == nullptr) {
        return 0;
    }
    int count = 0;
    LinkedNode<Song> *currPtr = front;
    while (currPtr->getNext() != nullptr) {
        currPtr = currPtr->getNext();
        count += 1;
    }
    currPtr = nullptr;
    return count;
}

float Library::getDuration() {
    return duration;
}

int Library::find(std::string title, std::string artist) {
    if (front == nullptr) {
        return -1;
    }
    int count = 0;
    LinkedNode<Song> *currPtr = front;
    while (currPtr != nullptr) {
        if (currPtr->getItem()->getTitle() == title && currPtr->getItem()->getArtist() == artist) {
            currPtr = nullptr;
            return count;
        }
        else {
            currPtr = currPtr->getNext();
            count += 1;
        }
    }
    currPtr = nullptr;
    return -1;
}

