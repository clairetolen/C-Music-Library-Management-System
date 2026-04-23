#include "Song.h"

Song::Song() : songId(-1), artistName(""), duration(0), songTitle(""), favorite(false),
               timeListened(0), heapIndex(-1), dllNodePtr(nullptr) {
}

Song::Song(unsigned int songId, const std::string& artistName, unsigned int duration, const std::string& songTitle)
    : songId(songId),
      artistName(artistName),
      duration(duration),
      songTitle(songTitle),
      favorite(false),
      timeListened(0),
      heapIndex(-1),
      dllNodePtr(nullptr) {
}

int Song::getSongId() const {
    return songId;
}

std::string Song::getArtistName() const {
    return artistName;
}

unsigned int Song::getDuration() const {
    return duration;
}

std::string Song::getSongTitle() const {
    return songTitle;
}

bool Song::isFavorite() const {
    return favorite;
}

void Song::setFavorite(bool Favorite) {
    favorite = Favorite;
}

unsigned int Song::getTimeListened() const {
    return timeListened;
}

void Song::incListenTime(unsigned int seconds) {
    timeListened += seconds;
}

void Song::setHeapIndex(int index) {
    heapIndex = index;
}

int Song::getHeapIndex() const {
    return heapIndex;
}
