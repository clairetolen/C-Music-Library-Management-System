#pragma once
#include <string>

class Song {
public:
    Song();
    Song(unsigned int SongId, const std::string& ArtistName, unsigned int Duration, const std::string& SongTitle);

    bool isInFavList() const;


    unsigned int getTimeListened() const;
    std::string getSongTitle() const;
    unsigned int getSongId() const;



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
