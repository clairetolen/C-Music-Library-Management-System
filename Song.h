#pragma once
#include <string>

class Song {
public:
    Song(unsigned int SongId, const std::string& ArtistName, unsigned int Duration, const std::string& SongTitle);

    unsigned int getSongId() const;
    std::string getArtistName() const;
    unsigned int getDuration() const;
    std::string getSongTitle() const;
    bool isInFavList() const;
    unsigned int getTimeListened() const;

    void setIsInFavList(bool IsInFavList);
    void setTimeListened(unsigned int TimeListened);

private:
    unsigned int song_id;
    std::string artist_name;
    unsigned int duration;
    std::string song_title;
    bool is_in_fav_list = false;
    unsigned int time_listened = 0;
};
