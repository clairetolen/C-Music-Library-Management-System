#pragma once
#include "Song.h"

class SongList {
public:
    bool song(unsigned int SongId, const std::string& ArtistName, unsigned int Duration, const std::string& SongTitle);

private:
    unsigned int size = 0;
};
