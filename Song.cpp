#include "Song.h"

Song::Song(unsigned int SongId, const std::string& ArtistName, unsigned int Duration, const std::string& SongTitle)
    : song_id(SongId),
      artist_name(ArtistName),
      duration(Duration),
      song_title(SongTitle) {
}

bool Song::isInFavList() const {
    return is_in_fav_list;
}

unsigned int Song::getTimeListened() const {
    return time_listened;
}

void Song::setIsInFavList(bool IsInFavList) {
    is_in_fav_list = IsInFavList;
}

void Song::setTimeListened(unsigned int TimeListened) {
    time_listened = TimeListened;
}

std::string Song::getSongTitle() const {
    return song_title;
}

unsigned int Song::getSongId() const {
    return song_id;
}

unsigned int Song::getDuration() const {
    return duration;
}

std::string Song::getArtistName() const {
    return artist_name;
}