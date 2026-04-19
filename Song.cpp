#include "Song.h"

Song::Song() : songId(-1), artistName(""), duration(0), songTitle(""), favorite(false),
               timeListened(0) {
}

Song::Song(unsigned int SongId, const std::string& ArtistName, unsigned int Duration, const std::string& SongTitle)
    : songId(SongId),
      artistName(ArtistName),
      duration(Duration),
      songTitle(SongTitle),
      favorite(false),
      timeListened(0) {
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

void Song::setTimeListened(unsigned int TimeListened) {
    timeListened = TimeListened;
}
