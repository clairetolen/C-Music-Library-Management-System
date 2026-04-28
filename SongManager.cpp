#include "SongManager.h"

SongManager::SongManager() {

}

bool SongManager::song(unsigned int songId, const std::string& artistName, unsigned int duration,
                       const std::string& songTitle) {
    Song* songObj = new Song(songId, artistName, duration, songTitle);
    if (!songDLL.insert(songObj)) {
        // id have been used for other song
        delete songObj;
        return false;
    }
    songMH.insert(songObj);
    songBST.BSTInsertKey(songObj);
    return true;
}

// TODO: getKey()
bool SongManager::listen(const std::string& songTitle, unsigned int seconds) {
    if (!songBST.BSTContainsKey(songTitle)) {
        std::cout << "Song title \"" << songTitle << "\" not found." << std::endl;
        return false;
    }
    Song* song = songBST.BSTGetKey(songTitle);
    if (song->isFavorite()) {
        std::cout << "Song " << songTitle << " is already a favorite." << std::endl;
        return false;
    }
    std::cout << "Listened to " << songTitle << " for " << seconds << " seconds." << std::endl;
    song->incListenTime(seconds);
    return true;
}

void SongManager::show_listen_time() const{
    songDLL.printAllSongs();
}

bool SongManager::favorite() {
    Song* song = songMH.extractMax();
    if (song == nullptr) {
        std::cout << "No song found." << std::endl;
        return false;
    }
    song->setFavorite(true);
    return true;
}

// TODO: getKey()
bool SongManager::remove(const std::string& songTitle) {
    if (!songBST.BSTContainsKey(songTitle)) {
        std::cout << "Song title \"" << songTitle << "\" not found." << std::endl;
        return false;
    }
    Song* key = songBST.BSTGetKey(songTitle);
    songBST.BSTRemoveKey(key);
    songMH.remove(key);
    songDLL.remove(key);
    return true;
}

// TODO: make sure the container that uses heap free have a destructor
void SongManager::quit() {
    std::cout << "Exiting ..." << std::endl;
}
