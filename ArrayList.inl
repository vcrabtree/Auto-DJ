//
// Created by vcrab on 12/4/2019.
//

#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    if (initialCapacity >= 1) {
        this->arrayList = new T*[initialCapacity];
        this->currItemCount = 0;
        this->currCapacity = initialCapacity;
        int duration = 0;
    }
    else {
        throw std::invalid_argument("Array list capacity cannot be less than 1");
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    for (int i = 0; i < currItemCount; i++) delete arrayList[i];
    delete[] arrayList;
}

template <class T>
void ArrayList<T>::doubleCapacity() {
    int newCapacity = currCapacity * 2;
    T **newArray = new T*[newCapacity];
    for (int i = 0; i < currCapacity; i ++) {
        newArray[i] = arrayList[i];
    }
    delete[] arrayList;
    arrayList = newArray;
    currCapacity = newCapacity;
}


template <class T>
void ArrayList<T>::add(T* item) { //Currently inserts at the end
    if (currItemCount < currCapacity) {
        arrayList[currItemCount] = item;
        currItemCount++;
    }
    else {
        doubleCapacity();
        arrayList[currItemCount] = item;
        currItemCount++;
    }
}

template <class T>
T* ArrayList<T>::remove(std::string title, std::string artist) {
    int itemToRemoveIndex = find(title, artist);
    if (currItemCount == 0) {
        throw std::out_of_range ("There are no items in this array list");
    } else if (itemToRemoveIndex > -1) {
        T* itemToRemove = arrayList[itemToRemoveIndex];
        for (int i = itemToRemoveIndex; i <= currItemCount; i++) {
            arrayList[i] = arrayList[i + 1];
        }
        currItemCount--;
        return itemToRemove;
    } else throw std::out_of_range ("There is no item at this index");
}

template <class T>
T* ArrayList<T>::getItemAt(int index) {
    if (index < 0 || index > currItemCount) {
        throw std::out_of_range ("There is no item at this index");
    }
    else if (index < currItemCount) {
        return arrayList[index];
    }
    else {
        throw std::out_of_range ("There is no item at this index");
    }
}

template <class T>
bool ArrayList<T>::isEmpty() {
    if (currItemCount == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
void ArrayList<T>::clear() {
    currItemCount = 0;
}

template <class T>
int ArrayList<T>::getLength() {
    return currItemCount;
}

template <class T>
int ArrayList<T>::find(std::string title, std::string artist) {
    for (int i = 0; i < currItemCount; i++) {
        if (matches(arrayList[i], title, artist)) return i;
    }
    return -1;
}

template <class T>
int ArrayList<T>::getItem(std::string title, std::string artist) {
    for (int i = 0; i < currItemCount; i++) {
        if (matches(arrayList[i], title, artist)) return arrayList[i];
    }
    return nullptr;
}

template <class T>
bool ArrayList<T>::matches(T *item, std::string title, std::string artist) {
    return (!artist.length() && title == item->getTitle()) || 
    (title == item->getTitle() && artist == item->getArtist());
}

