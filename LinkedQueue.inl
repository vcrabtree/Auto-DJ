#include "LinkedQueue.h"

template <class T>
LinkedQueue<T>::LinkedQueue() {
    head = tail = nullptr;
}

template <class T>
LinkedQueue<T>::~LinkedQueue() { empty(); }

template <class T>
void LinkedQueue<T>::enqueue(T *item) {
    LinkedNode<T>* newNode = new LinkedNode<T>(*item);

    if (!head) head = tail = newNode;
    else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <class T>
T* LinkedQueue<T>::dequeue() {
    if (isEmpty()) throw std::out_of_range("queue is empty");

    T *item = head->getItem();

    if (head == tail) head = tail = nullptr;
    else head = head->getNext();

    return item;
}

template <class T>
T* LinkedQueue<T>::remove(std::string title, std::string artist) {
    if (isEmpty()) throw std::out_of_range("playlist is empty");

    T *headItem = head->getItem(), *tailItem = tail->getItem();
    T *item;

    if (matches(headItem, title, artist)) item = dequeue();
    else if (matches(tailItem, title, artist)) item  = removeFromEnd();
    else {
        LinkedNode<T> *currNode = head, *nextNode = head->getNext();
        while (nextNode) {
            item = nextNode->getItem();
            if (matches(item, title, artist)) break;

            currNode = nextNode;
            nextNode = nextNode->getNext();
        }

        if (nextNode) {
            currNode->setNext(nextNode->getNext());
            delete nextNode;
        } else item = nullptr;
    }
    return item;
}

template <class T>
T* LinkedQueue<T>::removeFromEnd() {
    LinkedNode<T> *currNode = head, *nextNode = head->getNext();
    T *t = tail->getItem();

    while (currNode->getNext() && nextNode->getNext()) {
        currNode = currNode->getNext();
        nextNode = nextNode->getNext();
    }
    delete nextNode;
    currNode->setNext(nullptr);
    tail = currNode;
    return t;
}

template <class T>
bool LinkedQueue<T>::matches(T *item, std::string title, std::string artist) {
    return (!artist.length() && title == item->getTitle()) || 
    (title == item->getTitle() && artist == item->getArtist());
}

template <class T>
void LinkedQueue<T>::empty() {
    while(!isEmpty()) dequeue(); 
}


template <class T>
bool LinkedQueue<T>::isEmpty() { return !head; }

