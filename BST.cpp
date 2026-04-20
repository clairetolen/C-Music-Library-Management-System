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
        root -> parent = nullptr;
        size++;
        return;
    }
    SongNode* curr = root;

    if (BSTSearchKey(node->data->getSongTitle()) != nullptr){
        //break
        std::cout << "Song already in song List"<< std::endl;
        return;
    }
    while (curr != nullptr){
    // some kind of loop 
    //check if curr node > node (being inserted)
    if (node->data->getSongTitle() < curr->data->getSongTitle()){
        //go left by changing curr
      if (curr -> left == nullptr){
        curr -> left = node;
        node -> parent = curr;
        size++;
        return;
      }else {
        curr = curr->left;

      }

    }else if (node->data->getSongTitle() > curr->data->getSongTitle()){
        //go right 
        if (curr -> right == nullptr){
            curr -> right = node;
            node-> parent = curr;
            size++;
            return;
        }else{
        curr = curr->right;
        }
    }
    }


}

void BST::BSTRemoveKey(Song* song) {

}

void BST::BSTRemoveNode(SongNode* node) {

}

SongNode* BST::BSTSearchKey(const std::string& title) const {
    SongNode* curr = root;
    while (curr != nullptr){
     
        if (title == curr ->data->getSongTitle()){
                return curr;
        }else if (title < curr->data->getSongTitle()){
            curr = curr->left;

        }else if (title > curr->data->getSongTitle()){
            curr = curr->right;
        }
//if not found return nullptr
       
}
return nullptr;
}
