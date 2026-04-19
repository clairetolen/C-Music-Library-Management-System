#pragma once
#include <string>

class Song {
public:
    Song();
    Song(unsigned int SongId, const std::string& ArtistName, unsigned int Duration, const std::string& SongTitle);

    int getSongId() const;
    std::string getArtistName() const;
    unsigned int getDuration() const;
    std::string getSongTitle() const;
    bool isFavorite() const;
    unsigned int getTimeListened() const;

    void setFavorite(bool Favorite);
    void setTimeListened(unsigned int TimeListened);

private:
    int songId;
    std::string artistName;
    unsigned int duration;
    std::string songTitle;
    bool favorite;
    unsigned int timeListened;
};
