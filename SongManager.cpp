#include "SongManager.h"

SongManager::SongManager() {

}

bool SongManager::song(unsigned int songId, const std::string& artistName, unsigned int duration,
                       const std::string& songTitle) {
    Song* songObj = new Song(songId, artistName, duration, songTitle);
    if (!songDLL.insert(songObj) || songBST.contain(songTitle)) {
        // id have been used for other song
        delete songObj;
        return false;
    }
    songMH.insert(songObj);
    songBST.insert(songObj);
    return true;
}

bool SongManager::listen(const std::string& songTitle, unsigned int seconds) {
    if (!songBST.contain(songTitle)) {
        std::cout << "Song title \"" << songTitle << "\" not found." << std::endl;
        return false;
    }
    Song* song = songBST.get(songTitle);
    if (song->isFavorite()) {
        std::cout << "Song " << songTitle << " is already a favorite." << std::endl;
        return false;
    }
    std::cout << "Listened to " << songTitle << " for " << seconds << " seconds." << std::endl;
    song->incListenTime(seconds);
    songMH.update(song);
    return true;
}

void SongManager::show_listen_time() const{
    songDLL.printAllSongsListenTime();
}

bool SongManager::favorite() {
    Song* song = songMH.extractMax();
    if (song == nullptr) {
        std::cout << "No songs can be favorited." << std::endl;
        return false;
    }
    song->setFavorite(true);
    std::cout << "Song " << song->getSongTitle() << " added to list of favorites (Listened for " << song->getTimeListened() << " seconds)" << std::endl;
    return true;
}

bool SongManager::remove(const std::string& songTitle) {
    if (!songBST.contain(songTitle)) {
        std::cout << "Song title \"" << songTitle << "\" not found." << std::endl;
        return false;
    }
    Song* key = songBST.get(songTitle);
    songBST.remove(key);
    songMH.remove(key);
    songDLL.remove(key);
    return true;
}

void SongManager::quit() {
    std::cout << "Exiting ..." << std::endl;
}

void SongManager::showAllSongsInfo() const {
    songDLL.printAllSongsInfo();
}
