#pragma once
#include <vector>
#include "Song.h"

class MH {
public:
    MH();

    void insert(Song* song);
    void remove(Song* song);
    Song* extractMax();

private:
    unsigned int heapSize;
    std::vector<Song*> songs;

    void percolateUp(unsigned int nodeIndex);
    void percolateDown(unsigned int nodeIndex);
    void heapInsert();
};
