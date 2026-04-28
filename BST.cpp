#include "BST.h"

BST::BST() : root(nullptr) {
}

BST::~BST() {
    deleteTree(root);
    root = nullptr;
}

bool BST::insert(Song* song) {
    if (song == nullptr) { return false; }
    SongNode* key = new SongNode(song);
    insertNode(key);
    return true;
}

void BST::insertNode(SongNode* node) {
    if (node == nullptr) { return; }
    // check if root =null ptr --> insert at root
    if (root == nullptr) {
        root = node;
        root->parent = nullptr;
        return;
    }

    // assume no duplicate title
    SongNode* curr = root;
    while (curr != nullptr) {
        // check if curr node > node (being inserted)
        if (node->data->getSongTitle() < curr->data->getSongTitle()) {
            //go left by changing curr
            if (curr->left == nullptr) {
                curr->left = node;
                node->parent = curr;
                return;
            }
            curr = curr->left;
        }
        else {
            //go right
            if (curr->right == nullptr) {
                curr->right = node;
                node->parent = curr;
                return;
            }
            curr = curr->right;
        }
    }
}

bool BST::remove(Song* song) {
    SongNode* key = getNode(song->getSongTitle());
    if (key == nullptr) {
        return false;
    }
    removeNode(key);
    return true;
}

void BST::removeNode(SongNode* node) {
    if (node == nullptr) { return; }

    // Case 1: Internal node with 2 children
    if (node->left != nullptr && node->right != nullptr) {
        // Find successor
        SongNode* successorNode = node->right;
        while (successorNode->left) {
            successorNode = successorNode->left;
        }

        // Copy value/data from successorNode to node
        node->data = successorNode->data;

        // Recursively remove successorNode
        removeNode(successorNode);
        return;
    }

    // Case 2: Root node (with 1 or 0 children)
    if (node == root) {
        SongNode* child = node->left != nullptr ? node->left : node->right;
        replaceChild(node, child);
    }

    // Case 3: Internal with left child only
    else if (node->left != nullptr) {
        replaceChild(node, node->left);
    }

    // Case 4: Internal with right child only OR leaf
    else {
        replaceChild(node, node->right);
    }

    delete node;
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
    return curr->data;
}

void BST::deleteTree(SongNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

bool BST::replaceChild(SongNode* currentChild, SongNode* newChild) {
    SongNode* parentNode = currentChild->parent;
    if (parentNode != nullptr) {
        if (parentNode->left == currentChild) {
            parentNode->left = newChild;
        }
        else {
            parentNode->right = newChild;
        }
    }
    else {
        root = newChild;
    }

    if (newChild != nullptr) {
        newChild->parent = parentNode;
    }
    return true;
}
