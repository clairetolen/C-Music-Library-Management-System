#pragma once
#include "Song.h"
#include "DLLNode.h"

class DLL {
public:
    DLL();
    ~DLL();
    // no copying allowed
    DLL(const DLL& other) = delete;
    DLL& operator=(const DLL& other) = delete;

    bool insert(Song* song); // Insert In Order
    bool remove(Song* song);
    void printAllSongs() const;

private:
    DLLNode* head;
    DLLNode* tail;
};
