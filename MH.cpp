#include "MH.h"

MH::MH() {
}

bool MH::insert(Song* song) {
    if (song == nullptr) return false;

    songs.push_back(song);
    int index = songs.size() - 1;
    song->setHeapIndex(index);

    percolateUp(index);
    return true;
}

bool MH::remove(Song* song) {
    if (song == nullptr) return false;

    int index = song->getHeapIndex();
    if (!isIndexInRange(index)) { return false; }

    swap(index, songs.size() - 1);
    songs.pop_back();
    song->setHeapIndex(-1);

    percolateUp(index);
    percolateDown(index);
    return true;
}

bool MH::update(Song* song) {
    if (song == nullptr) return false;

    int index = song->getHeapIndex();
    percolateUp(index);
    return true;
}

Song* MH::extractMax() {
    if (songs.empty()) { return nullptr; }

    Song* max = songs[0];
    remove(max);
    return max;
}

void MH::percolateUp(int index) {
    if (!isIndexInRange(index)) {
        return;
    }

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (songs[index]->getTimeListened() <= songs[parentIndex]->getTimeListened())
            return;

        swap(index, parentIndex);
        index = parentIndex;
    }
}

void MH::percolateDown(int index) {
    if (!isIndexInRange(index)) {
        return;
    }

    int childIndex = 2 * index + 1;
    unsigned int value = songs[index]->getTimeListened();

    while (childIndex < songs.size()) {
        // Find the max among the node and all the node's children
        unsigned int maxValue = value;
        int maxIndex = -1;
        // check left then right child
        for (int i = 0; i < 2 && i + childIndex < songs.size(); i++) {
            if (songs[i + childIndex]->getTimeListened() > maxValue) {
                maxValue = songs[i + childIndex]->getTimeListened();
                maxIndex = i + childIndex;
            }
        }

        if (maxValue == value) {
            return;
        }

        swap(index, maxIndex);
        index = maxIndex;
        childIndex = 2 * index + 1;
    }
}

void MH::swap(int index1, int index2) {
    songs[index1]->setHeapIndex(index2);
    songs[index2]->setHeapIndex(index1);

    Song* tmp = songs[index1];
    songs[index1] = songs[index2];
    songs[index2] = tmp;
}

bool MH::isIndexInRange(int index) const {
    return index >= 0 && index < songs.size();
}
