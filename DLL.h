#pragma once
#include "Song.h"

class DLL {
public:
    DLL();
    ~DLL();

    void insert(Song* song); // Insert In Order
    void remove(Song* song);
    void printAllSongs();

private:
    class DLLNode {
    public:
        DLLNode(Song* song) : data(song), prev(nullptr), next(nullptr) {
        }
        Song* data;
        DLLNode* prev;
        DLLNode* next;
    };

    DLLNode* head;

    friend class Song;
};
