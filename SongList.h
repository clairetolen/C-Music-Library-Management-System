#pragma once
#include "BST.h"
#include "Song.h"

class SongList {
public:
    bool song(unsigned int SongId, const std::string& ArtistName, unsigned int Duration, const std::string& SongTitle);

private:
    unsigned int size = 0;
    std::vector <Song> songs; ///stores all the song objects
};
