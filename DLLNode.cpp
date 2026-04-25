#include "DLLNode.h"
#include "Song.h"

DLLNode::DLLNode() : data(nullptr), prev(nullptr), next(nullptr) {
}

DLLNode::DLLNode(Song* song) : data(song), prev(nullptr), next(nullptr) {
}

DLLNode::~DLLNode() {
    delete data;
}
