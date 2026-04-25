#pragma once

class Song;

class DLLNode {
public:
    DLLNode();
    ~DLLNode();
    // no copying allowed
    DLLNode(const DLLNode* other) = delete;
    DLLNode& operator=(const DLLNode& other) = delete;
    DLLNode(Song* song);

    Song* data;
    DLLNode* prev;
    DLLNode* next;
};
