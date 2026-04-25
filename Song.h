#pragma once
#include <string>
#include "DLLNode.h"

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
    int getHeapIndex() const;
    DLLNode* getDllNodePtr() const;

    void setFavorite(bool isFav);
    void setHeapIndex(int index);
    void setDllNodePtr(DLLNode* ptr);

    void incListenTime(unsigned int seconds);

private:
    int songId;
    std::string artistName;
    unsigned int duration;
    std::string songTitle;
    bool favorite;
    unsigned int timeListened;

    int heapIndex;
    DLLNode* dllNodePtr;
};
