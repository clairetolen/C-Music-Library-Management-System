#pragma once
#include "Song.h"

class BST {
public:
    BST();

    // ~BST();
    // BST(const BST& other);
    // BST& operator=(const BST& other);

    // recursively or iteratively
    void BSTInsertKey(Song* song);
    void BSTRemoveKey(Song* song);

private:
    class SongNode {
    public:
        SongNode(Song* song) : data(song), left(nullptr), right(nullptr) {
        }

        Song* data;
        SongNode* left;
        SongNode* right;
    };

    SongNode* root;
    unsigned int size;

    void BSTInsertNode(SongNode* node);
    void BSTRemoveNode(SongNode* node);
    SongNode* BSTSearchKey(Song* song) const;
};
