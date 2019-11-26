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
        LinkedNode<Song> *tempNode = front;
        front = front->getNext();
        delete tempNode;
    }
    front = nullptr;
    end = nullptr;
}

Library::Library(const Library& libraryToCopy) {
    LinkedNode<Song> *currPtr = libraryToCopy.front;
    LinkedNode<Song> *newCurrPtr;
    if (currPtr == nullptr) {
        this->front = nullptr;
        this->end = nullptr;
    }
    while (currPtr->getNext() != nullptr) {
        if (currPtr == libraryToCopy.front) {
            LinkedNode<Song> *newNode = new LinkedNode<Song>(currPtr->getItem());
            this->front = newNode;
            currPtr = currPtr->getNext();
            newCurrPtr = newNode;
        }
        else {
            LinkedNode<Song> *newNode = new LinkedNode<Song>(currPtr->getItem());
            newCurrPtr->setNext(newNode);
            currPtr = currPtr->getNext();
            newCurrPtr = newNode;
        }
    }
    LinkedNode<Song> *newNode = new LinkedNode<Song>(currPtr->getItem());
    newCurrPtr->setNext(newNode);
    newCurrPtr = newNode;
    this->end = newCurrPtr;
    currPtr = nullptr;
    newCurrPtr= nullptr;
}

Library& Library::operator=(const Library& libraryToCopy) {
    if (this != &libraryToCopy) {
        while (front != end) {
            LinkedNode<Song> *tempNode = front;
            front = front->getNext();
            delete tempNode;
        }
        delete front;
        delete end;
        LinkedNode<Song> *currPtr = libraryToCopy.front;
        LinkedNode<Song> *newCurrPtr;
        if (currPtr == nullptr) {
            this->front = nullptr;
            this->end = nullptr;
        }
        while (currPtr->getNext() != nullptr) {
            if (currPtr == libraryToCopy.front) {
                LinkedNode<Song> *newNode = new LinkedNode<Song>(currPtr->getItem());
                this->front = newNode;
                currPtr = currPtr->getNext();
                newCurrPtr = newNode;
            } else {
                LinkedNode<Song> *newNode = new LinkedNode<Song>(currPtr->getItem());
                newCurrPtr->setNext(newNode);
                currPtr = currPtr->getNext();
                newCurrPtr = newNode;
            }
        }
        LinkedNode<Song> *newNode = new LinkedNode<Song>(currPtr->getItem());
        newCurrPtr->setNext(newNode);
        newCurrPtr = newNode;
        this->end = newCurrPtr;
        currPtr = nullptr;
        newCurrPtr = nullptr;
    }
    return *this;
}

void Library::add(Song* song, int index) {
    if (index < 0) {
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }
    if (front == nullptr) {
        LinkedNode<Song> *newNode = new LinkedNode(song);
        start = newNode;
        end = newNode;
        newNode = nullptr;
    }
    int count = 0;
    LinkedNode<Song> *currPtr = front;
    while (currPtr != nullptr && count <= index) {
        count += 1;
        if (index == 0) {
            LinkedNode<Song> *newNode = new LinkedNode(song);
            newNode->setNext(front);
            front = newNode;
            newNode = nullptr;
        }
        else if (currPtr->getNext() == nullptr && index == count + 1) {
            LinkedNode<Song> *newNode = new LinkedNode(song);
            end->setNext(newNode);
            end = newNode;
            newNode = nullptr;
        }
        else if (count == index) {
            LinkedNode<Song> *newNode = new LinkedNode(song);
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
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }
    currPtr = nullptr;
}

Song Library::remove(int index) {
    if (index < 0) {
        throw std::out_of_range("std::out_of_range: " + std::to_string(index));
    }
    LinkedNode<Song> *currPtr = front;
    int count = 0;
    int songToRemove;
    while (currPtr != nullptr && count <= index) {
        count += 1;
        if (index == 0) {
            songToRemove = front->getItem();
            LinkedNode<Song> *currPtr = front;
            currPtr = currPtr->getNext();
            front = currPtr;
            currPtr = nullptr;
            return songToRemove;
        }
        else if (currPtr->getNext() == nullptr and index == count + 1) {
            songToRemove = end->getItem();
            int newCount = 0;
            LinkedNode<Song> *currPtr = front;
            LinkedNode<Song> *currPtrBefore = front;
            while (currPtr->getNext() != nullptr) {
                currPtrBefore = currPtr;
                currPtr = currPtr->getNext();
                newCount += 1;
            }
            if (newCount != 0) {
                currPtrBefore->setNext(nullptr);
            }
            else {
                front = nullptr;
            }
            currPtrBefore = nullptr;
            currPtr = nullptr;
            return songToRemove;
        }
        else if (count == index) {
            LinkedNode<Song> *beforeNodeToRemove = currPtr;
            LinkedNode<Song> *nodeToRemove = beforeNodeToRemove->getNext();
            LinkedNode<Song> *afterNodeToRemove  = nodeToRemove->getNext();
            beforeNodeToRemove->setNext(afterNodeToRemove);
            songToRemove = nodeToRemove->getItem();
            delete nodeToRemove;
            beforeNodeToRemove = nullptr;
            afterNodeToRemove = nullptr;
            currPtr = nullptr;
            return songToRemove;
        }
        else {
            currPtr = currPtr->getNext();
        }
    }
    if (index > count && currPtr == nullptr) {
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }
    currPtr = nullptr;
    return songToRemove;
}

Song Library::getSongAt(int index) {
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
    Song songToGet = currPtr->getItem();
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
    while (front != end) {
        LinkedNode<Song> *tempNode = front;
        front = front->getNext();
        delete tempNode;
    }
    front = nullptr;
    end = nullptr;
}

int Library::getLength() {
    if (front == nullptr) {
        return 0;
    }
    int count = 0;
    LinkedNode* currPtr = front;
    while (currPtr != nullptr) {
        count += 1;
        currPtr = currPtr->getNext();
    }
    currPtr = nullptr;
    return count;
}

int Library::find(Song song) {
    if (front == nullptr) {
        return -1;
    }
    int count = 0;
    LinkedNode<Song> *currPtr = front;
    while (currPtr != nullptr) {
        if (currPtr->getItem() == song) {
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

