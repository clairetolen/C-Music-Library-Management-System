#pragma once
#include "Song.h"

class DLL {
public:
    DLL();

    void insert(Song* song); // Insert In Order
    void remove();
    void traverse();

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
    DLLNode* tail;

    friend class Song;
};
