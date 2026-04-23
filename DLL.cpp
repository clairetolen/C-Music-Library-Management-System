#include "DLL.h"
#include <iostream>

DLL::DLL() : head(nullptr) {
}

// TODO:
DLL::~DLL() {
}

// TODO:
void DLL::insert(Song* song){
    if (song == nullptr) {return;}
    if (head == nullptr) {
        head = new DLLNode(song);
        song->setDllNodePtr(head);
    }
}

// TODO:
void DLL::remove(Song* song) {
    if (song == nullptr) {return;}
    DLLNode* tmp = song->getDllNodePtr();
    
}

void DLL::printAllSongs() {
    DLLNode* current = head;
    while (current != nullptr) {
        std::cout << current->data->getSongId() << " " <<
            current->data->getSongTitle() << " has been listened to for " <<
            current->data->getDuration() << " seconds"
            << std::endl;
        current = current->next;
    }
}
