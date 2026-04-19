#pragma once
#include "Song.h"

class MaxHeap {
public:
    MaxHeap();

    void insert();

private:
    Song* heapArray;
    unsigned int capacity;
    unsigned int size;
    void percolateUp();
    void percolateDown();
    void extractMax();
    void swap();
    void heapify();

    int* hashTable; // song_id to index in heap
    int hash();
    void resize();
    unsigned int getIndex();
    bool HashInsert();
    bool HashRemove();
    Song* HashGet();
};
