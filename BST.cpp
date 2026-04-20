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
    SongNode* key = BSTSearchKey(song->getSongTitle());
    if (key == nullptr){
        std::cout<<"";
        return;
    }
    BSTRemoveNode(key);
    size--;
}

void BST::BSTRemoveNode(SongNode* node) {
    if(node == nullptr) return;
    if(node->left == nullptr && node->right == nullptr){ // leaf node
        if (node==root){
            root = nullptr;
        }
        else if(node->parent->left == node) {  
            node->parent->left = nullptr;
        }else{
            node->parent->right = nullptr;
        }
        delete node; 
    }
    else if (node->left == nullptr ^ node->right == nullptr){ // 1 child
        if(node==root){
            if(node->right!=nullptr){
                node->right->parent = nullptr;
                root = node->right;
            }else{
                node->left->parent =nullptr;
                root= node->left;
            }
        }else{
            if(node->right!=nullptr){
                node->right->parent = node->parent;
                if(node->parent->right==node){
                    node->parent->right = node->right;
                }else{
                    node->parent->left = node->right;
                }
            }else{
                node->left->parent = node->parent;
                if(node->parent->right==node){
                    node->parent->right = node->left;
                }else{
                    node->parent->left = node->left;
                }
            }
        }
        delete node;
    }
    else{ // 2 childeren 

    }
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
