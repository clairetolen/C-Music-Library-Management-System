#include "SongManager.h"

SongManager::SongManager() {
}

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
    // songBST.getKey()->incListenTime(seconds);
    return true;
}

void SongManager::show_listen_time() {
    songDLL.printAllSongs();
}

bool SongManager::favorite() {
    songMH.extractMax()->setFavorite(true);
}

// TODO:
bool SongManager::remove(const std::string& songTitle) {
    if (songBST.BSTContainsKey(songTitle)) { return false; }
    /*
    Song* key = songBST.getKey(songTitle);
    songBST.remove(songTitle);
    songMH.remove(key);
    songDLL.remove(key);
    */
    return true;
}

// TODO: free all memory, destroy BST, MH, DLL
void SongManager::quit() {
    /*
    ~songMH();
    ~songBST();
    ~songDLL();
    */
}
