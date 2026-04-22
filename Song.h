#pragma once
#include <string>

class Song {
public:
    Song();
    Song(unsigned int songId, const std::string& artistName, unsigned int duration, const std::string& songTitle);

    int getSongId() const;
    std::string getArtistName() const;
    unsigned int getDuration() const;
    std::string getSongTitle() const;
    bool isFavorite() const;
    unsigned int getTimeListened() const;

    void setFavorite(bool isFav);
    void setHeapIndex(int index);

    void incListenTime(unsigned int seconds);

private:
    int songId;
    std::string artistName;
    unsigned int duration;
    std::string songTitle;
    bool favorite;
    unsigned int timeListened;

    class DLLNode;
    int heapIndex;
    DLLNode* dllNodePtr;
};
