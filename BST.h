#pragma once
#include "Song.h"

class BST {
public:
    BST();

    ~BST();
    BST(const BST& other) = delete;
    BST& operator=(const BST& other) = delete;

    bool insert(Song* song);
    bool remove(Song* song);
    bool contain(const std::string& title) const;
    Song* get(const std::string& title) const;

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

    void insertNode(SongNode* node);
    void removeNode(SongNode* node);
    bool replaceChild(SongNode* node, SongNode* newChild);
    SongNode* getNode(const std::string& title) const;
    void deleteTree(SongNode* node);
};
