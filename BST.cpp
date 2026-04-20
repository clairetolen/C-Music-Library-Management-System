#include "BST.h"

BST::BST() : root(nullptr), size(0) {
}

void BST::BSTInsertKey(Song* song) {
    SongNode* key = new SongNode(song);
    BSTInsertNode(key);
}

void BST::BSTInsertNode(SongNode* node) {
    //check if root =null ptr --> insert at root
    if (root == nullptr){
        root = node;
        return;
    }
    SongNode* curr = root
    
    // some kind of loop 
    //check if curr node > node (being inserted)

}

void BST::BSTRemoveKey(Song* song) {

}

void BST::BSTRemoveNode(SongNode* node) {

}

SongNode* BST::BSTSearchKey(Song* song) const {

}
