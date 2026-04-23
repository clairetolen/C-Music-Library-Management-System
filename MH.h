#pragma once
#include <vector>
#include "Song.h"

class MH {
public:
    MH();

    void insert(Song* song);
    void remove(Song* song);
    void update(Song* song);
    Song* extractMax();

private:
    std::vector<Song*> songs;

    void percolateUp(int index);
    void percolateDown(int index);
    void swap(int index1, int index2);
    bool isIndexInRange(int index) const;
};
