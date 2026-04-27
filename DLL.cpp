#include "DLL.h"
#include <iostream>

DLL::DLL() : head(nullptr), tail(nullptr) {
}

DLL::~DLL() {
    DLLNode* current = head;
    while (current != nullptr) {
        DLLNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

// insert by id in increasing order
bool DLL::insert(Song* song) {
    if (song == nullptr) { return false; }

    // case 1: list is empty
    if (head == nullptr) {
        DLLNode* node = new DLLNode(song);
        song->setDllNodePtr(node);
        head = node;
        tail = node;
        std::cout << "New song " << song->getSongId() << " " << song->getSongTitle() << " by " << song->
            getArtistName() << " " << song->getDuration() / 60 << ":" << song->getDuration() % 60 << "." << std::endl;
        return true;
    }

    // case 2: id is greater than all element in list
    if (song->getSongId() > tail->data->getSongId()) {
        DLLNode* node = new DLLNode(song);
        song->setDllNodePtr(node);
        node->prev = tail;
        tail->next = node;
        tail = node;
        std::cout << "New song " << song->getSongId() << " " << song->getSongTitle() << " by " << song->
            getArtistName() << " " << song->getDuration() / 60 << ":" << song->getDuration() % 60 << "." << std::endl;
        return true;
    }

    DLLNode* current = head;
    while (current != nullptr) {
        // case 3: duplicate id
        if (song->getSongId() == current->data->getSongId()) {
            std::cout << "Song id " << current->data->getSongId() << " already used for " << current->data->
                getSongTitle() <<
                " by " << current->data->getArtistName() << "." << std::endl;
            return false;
        }
        // case 4: found the spot to insert
        if (song->getSongId() < current->data->getSongId()) {
            DLLNode* node = new DLLNode(song);
            song->setDllNodePtr(node);

            node->prev = current->prev;
            node->next = current;
            if (current == head) {
                // insert before head
                head = node;
            }
            else {
                current->prev->next = node;
            }
            current->prev = node;

            std::cout << "New song " << song->getSongId() << " " << song->getSongTitle() << " by " << song->
                getArtistName() << " " << song->getDuration() / 60 << ":" << song->getDuration() % 60 << "." <<
                std::endl;
            return true;
        }
        current = current->next;
    }

    return false;
}

bool DLL::remove(Song* song) {
    if (song == nullptr) { return false; }

    DLLNode* nodeToDelete = song->getDllNodePtr();

    if (nodeToDelete == nullptr) { return false; }

    std::cout << "Removed song " << song->getSongId() << " " << song->getSongTitle() << " from your songs." <<
        std::endl;

    DLLNode* prevNode = nodeToDelete->prev;
    DLLNode* nextNode = nodeToDelete->next;

    if (prevNode != nullptr) {
        prevNode->next = nextNode;
    }
    else {
        // nodeToDelete was the head
        head = nextNode;
    }

    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }
    else {
        // nodeToDelete was the tail
        tail = prevNode;
    }

    delete nodeToDelete;
    return true;
}

void DLL::printAllSongs() const {
    DLLNode* current = head;
    while (current != nullptr) {
        std::cout << current->data->getSongId() << " " <<
            current->data->getSongTitle() << " has been listened to for " <<
            current->data->getDuration() << " seconds."
            << std::endl;
        current = current->next;
    }
}
