#include "BST.h"

BST::BST() : root(nullptr), size(0) {
}

BST::~BST() {
    deleteTree(root);
}

void BST::insert(Song* song) {
    SongNode* key = new SongNode(song);
    insertNode(key);
}

void BST::insertNode(SongNode* node) {
    //check if root =null ptr --> insert at root

    if (root == nullptr) {
        root = node;
        root->parent = nullptr;
        size++;
        return;
    }
    SongNode* curr = root;

    if (getNode(node->data->getSongTitle()) != nullptr) {
        //break
        return;
    }
    while (curr != nullptr) {
        // some kind of loop
        //check if curr node > node (being inserted)
        if (node->data->getSongTitle() < curr->data->getSongTitle()) {
            //go left by changing curr
            if (curr->left == nullptr) {
                curr->left = node;
                node->parent = curr;
                size++;
                return;
            }
            else {
                curr = curr->left;
            }
        }
        else if (node->data->getSongTitle() > curr->data->getSongTitle()) {
            //go right
            if (curr->right == nullptr) {
                curr->right = node;
                node->parent = curr;
                size++;
                return;
            }
            else {
                curr = curr->right;
            }
        }
    }
}

void BST::remove(Song* song) {
    SongNode* key = getNode(song->getSongTitle());
    if (key == nullptr) {
        return;
    }
    removeNode(key);
    size--;
}

void BST::removeNode(SongNode* node) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) {
        // leaf node
        if (node == root) {
            root = nullptr;
        }
        else if (node->parent->left == node) {
            node->parent->left = nullptr;
        }
        else {
            node->parent->right = nullptr;
        }
        delete node;
    }
    else if (node->left == nullptr ^ node->right == nullptr) {
        // 1 child
        if (node == root) {
            if (node->right != nullptr) {
                node->right->parent = nullptr;
                root = node->right;
            }
            else {
                node->left->parent = nullptr;
                root = node->left;
            }
        }
        else {
            if (node->right != nullptr) {
                node->right->parent = node->parent;
                if (node->parent->right == node) {
                    node->parent->right = node->right;
                }
                else {
                    node->parent->left = node->right;
                }
            }
            else {
                node->left->parent = node->parent;
                if (node->parent->right == node) {
                    node->parent->right = node->left;
                }
                else {
                    node->parent->left = node->left;
                }
            }
        }
        delete node;
    }
    else {
        // 2 children
        SongNode* succsesor = node->right;
        while (succsesor->left != nullptr) {
            succsesor = succsesor->left;
        }
        node->data = succsesor->data;
        removeNode(succsesor);
    }
}

BST::SongNode* BST::getNode(const std::string& title) const {
    SongNode* curr = root;
    while (curr != nullptr) {
        if (title == curr->data->getSongTitle()) {
            return curr;
        }
        if (title < curr->data->getSongTitle()) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    // if not found return nullptr
    return nullptr;
}

bool BST::contain(const std::string& title) const {
    return getNode(title) != nullptr;
}

Song* BST::get(const std::string& title) const {
    SongNode* curr = getNode(title);
    if (curr == nullptr) {
        return nullptr;
    }
    else {
        return curr->data;
    }
}

void BST::deleteTree(SongNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
