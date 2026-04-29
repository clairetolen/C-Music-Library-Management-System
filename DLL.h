#pragma once
#include "DLLNode.h"

class DLL {
public:
    DLL();
    ~DLL();
    DLL(const DLL& other) = delete;
    DLL& operator=(const DLL& other) = delete;

    bool insert(Song* song); // Insert In Order
    bool remove(Song* song);
    void printAllSongsListenTime() const;

    void printAllSongsInfo() const;

private:
    DLLNode* head;
    DLLNode* tail;
};
