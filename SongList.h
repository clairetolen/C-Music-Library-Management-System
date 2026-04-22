#pragma once
#include <string>
#include "Song.h"
#include "BST.h"
#include "MH.h"
#include "DLL.h"

class SongList {
public:
    SongList();

    bool song(unsigned int songId, const std::string& artistName, unsigned int duration, const std::string& songTitle);
    bool listen(const std::string& songTitle, unsigned int seconds);
    void show_listen_time();
    bool favorite();
    bool remove(const std::string& songTitle);
    void quit();

private:
    BST songBST;
    MH songMH;
    DLL songDLL;
};
