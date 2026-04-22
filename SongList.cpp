#include "SongList.h"

SongList::SongList() : songBST(), songMH(), songDLL() {
}

// TODO: add check input formats
bool SongList::song(unsigned int songId, const std::string& artistName, unsigned int duration,
                    const std::string& songTitle) {
    if (songBST.BSTContainsKey(songTitle)) { return false; }
    Song* songObj = new Song(songId, artistName, duration, songTitle);
    songDLL.insert(songObj);
    songMH.insert(songObj);
    songBST.BSTInsertKey(songObj);
    return true;
}

// TODO:
bool SongList::listen(const std::string& songTitle, unsigned int seconds) {
    if (!songBST.BSTContainsKey(songTitle)) { return false; }

    return true;
}

// TODO:
void SongList::show_listen_time() {
    songDLL.traverse();
}

// TODO:
bool SongList::favorite() {

}

// TODO:
bool SongList::remove(const std::string& songTitle) {
}

// TODO:
void SongList::quit() {
}
