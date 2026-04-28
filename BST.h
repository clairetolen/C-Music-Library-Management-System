#pragma once
#include "Song.h"

class BST {
public:
    BST();

    ~BST();
    BST(const BST& other) = delete;
    BST& operator=(const BST& other) = delete;

    void insert(Song* song);
    void remove(Song* song);
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
    unsigned int size;

    void insertNode(SongNode* node);
    void removeNode(SongNode* node);
    SongNode* getNode(const std::string& title) const;
    void deleteTree(SongNode* node);
};
