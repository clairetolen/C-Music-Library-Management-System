#pragma once
#include "Song.h"

class BST {
public:
    BST();

    ~BST();
    BST(const BST& other) = delete;
    BST& operator=(const BST& other) = delete;

    void BSTInsertKey(Song* song);
    void BSTRemoveKey(Song* song);
    bool BSTContainsKey(const std::string& title) const;
    Song* BSTGetKey(const std::string& title) const;

private:
    class SongNode {
    public:
        SongNode(Song* song) : data(song), left(nullptr), right(nullptr), parent(nullptr) {
        }

        Song* data;
        SongNode* left;
        SongNode* right;
        SongNode* parent;
    };

    SongNode* root;
    unsigned int size;

    void BSTInsertNode(SongNode* node);
    void BSTRemoveNode(SongNode* node);
    SongNode* BSTSearchKey(const std::string& title) const;
    void BSTDeleteTree(SongNode* node);
};
