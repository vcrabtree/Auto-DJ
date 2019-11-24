//
// Created by vcrab on 11/19/2019.
//

#include "Library.h"

Library::Library() {
    front = nullptr;
    end = nullptr;
}

Library::~Library() {
    while (front != end) {
        LinkedNode<Song*> tempNode = front;
        front = front->getNext();
        delete tempNode;
    }
    front = nullptr;
    end = nullptr;
}

Library::Library(const Library& libraryToCopy) {
    LinkedNode<Song*> currPtr = libraryToCopy.front;
    LinkedNode<Song*> newCurrPtr;
    if (currPtr == nullptr) {
        this->front = nullptr;
        this->end = nullptr;
    }
    while (currPtr->getNext() != nullptr) {
        if (currPtr == libraryToCopy.front) {
            LinkedNode<Song*> newNode = new LinkedNode<Song>(currPtr->getItem());
            this->front = newNode;
            currPtr = currPtr->getNext();
            newCurrPtr = newNode;
        }
        else {
            LinkedNode<Song*> newNode = new LinkedNode<Song>(currPtr->getItem());
            newCurrPtr->setNext(newNode);
            currPtr = currPtr->getNext();
            newCurrPtr = newNode;
        }
    }
    LinkedNode<Song*> newNode = new LinkedNode<Song>(currPtr->getItem());
    newCurrPtr->setNext(newNode);
    newCurrPtr = newNode;
    this->end = newCurrPtr;
    currPtr = nullptr;
    newCurrPtr= nullptr;
}

Library& Library::operator=(const Library& libraryToCopy) {
    if (this != &libraryToCopy) {
        while (front != end) {
            LinkedNode<Song*> tempNode = front;
            front = front->getNext();
            delete tempNode;
        }
        delete front;
        delete end;
        LinkedNode<Song*> currPtr = libraryToCopy.front;
        LinkedNode<Song*> newCurrPtr;
        if (currPtr == nullptr) {
            this->front = nullptr;
            this->end = nullptr;
        }
        while (currPtr->getNext() != nullptr) {
            if (currPtr == libraryToCopy.front) {
                LinkedNode<Song*> newNode = new LinkedNode<Song>(currPtr->getItem());
                this->front = newNode;
                currPtr = currPtr->getNext();
                newCurrPtr = newNode;
            } else {
                LinkedNode<Song*> newNode = new LinkedNode<Song>(currPtr->getItem());
                newCurrPtr->setNext(newNode);
                currPtr = currPtr->getNext();
                newCurrPtr = newNode;
            }
        }
        LinkedNode<Song*> newNode = new LinkedNode<Song>(currPtr->getItem());
        newCurrPtr->setNext(newNode);
        newCurrPtr = newNode;
        this->end = newCurrPtr;
        currPtr = nullptr;
        newCurrPtr = nullptr;
    }
    return *this;
}

void Library::add(Song* song, int index) {
    //TODO
}

Song Library::remove(std::string, int index) {
    //TODO
}

bool Library::isEmpty() {
    if (front == nullptr && end == nullptr) {
        return true;
    }
    return false;
}

void Library::clear() {
    while (front != end) {
        LinkedNode<Song*> tempNode = front;
        front = front->getNext();
        delete tempNode;
    }
    front = nullptr;
    end = nullptr;
}

int Library::getLength() {
    //TODO
}

int Library::find(std::string songTitle) {
    if (front == nullptr) {
        return -1;
    }
    int count = 0;
    LinkedNode<Song*> currPtr = front;
    while (currPtr->getNext() != nullptr) {
        if (currPtr->getItem() == songTitle) {
            currPtr = nullptr;
            return count;
        }
        else {
            currPtr = currPtr->getNext();
            count += 1;
        }
    }
    currPtr = nullptr;
    if (end->getItem() == songTitle) {
        return count;
    }
    return -1;
}

