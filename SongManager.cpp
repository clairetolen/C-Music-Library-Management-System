#include "SongManager.h"

SongManager::SongManager() : songBST(), songMH(), songDLL() {
}

// TODO: add check input formats
bool SongManager::song(unsigned int songId, const std::string& artistName, unsigned int duration,
                       const std::string& songTitle) {
    if (songBST.BSTContainsKey(songTitle)) { return false; }
    Song* songObj = new Song(songId, artistName, duration, songTitle);
    songDLL.insert(songObj);
    songMH.insert(songObj);
    songBST.BSTInsertKey(songObj);
    return true;
}

// TODO:
bool SongManager::listen(const std::string& songTitle, unsigned int seconds) {
    if (!songBST.BSTContainsKey(songTitle)) { return false; }

    return true;
}

// TODO:
void SongManager::show_listen_time() {
    songDLL.printAllSongs();
}

bool SongManager::favorite() {
    songMH.extractMax()->setFavorite(true);
}

// TODO:
bool SongManager::remove(const std::string& songTitle) {
}

// TODO:
void SongManager::quit() {
}
