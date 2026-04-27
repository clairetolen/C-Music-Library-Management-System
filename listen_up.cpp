#include "SongManager.h"
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <vector>

bool isValidUInt(const std::string& input);
std::vector<std::string> parser(const std::string& inputLine);

int main() {
    SongManager songLib;
    std::string lineString;
    bool quitStatus = false;

    // TODO: test the following codes and remove this
    while (!quitStatus) {
        std::cout << ": ";
        getline(std::cin, lineString);

        auto strList = parser(lineString);

        if (strList.empty()) {
            std::cout << "error flag: empty input" << std::endl;
            continue;
        }

        std::string action = strList.at(0);

        if (action == "quit") {
            songLib.quit();
            quitStatus = true;
        }
        else if (action == "song") {
            std::string songId, duration;
            std::string artist, title;
            if (strList.size() < 5) {
                std::cout << "error flag: missing parameters" << std::endl;
                continue;
            }

            songId = strList.at(1);
            artist = strList.at(2);
            duration = strList.at(3);
            title = strList.at(4);
            // songId & duration must be unsigned int
            if (!isValidUInt(songId)) {
                std::cout << "Song id " << songId << " is not an integer" << std::endl;
                continue;
            }
            if (!isValidUInt(duration)) {
                std::cout << "Duration " << duration << " is not an integer" << std::endl;
                continue;
            }
            songLib.song(std::stoul(songId), artist, std::stoul(duration), title);
        }
        else if (action == "remove") {
            std::string title;
            if (strList.size() < 2) {
                std::cout << "error flag: missing parameters" << std::endl;
                continue;
            }

            title = strList.at(1);
            songLib.remove(title);
        }
        else if (action == "listen") {
            std::string title;
            std::string seconds;
            if (strList.size() < 3) {
                std::cout << "error flag: missing parameters" << std::endl;
                continue;
            }

            title = strList.at(1);
            seconds = strList.at(2);
            if (!isValidUInt(seconds)) {
                std::cout << "Seconds " << seconds << " is not an integer" << std::endl;
                continue;
            }
            songLib.listen(title, std::stoul(seconds));
        }
        else if (action == "favorite") {
            songLib.favorite();
        }
        else if (action == "show_listen_time") {
            songLib.show_listen_time();
        }
        else if (action == "help") {
            std::cout << "\nCommands:\n";
            std::cout << std::endl;

            std::cout << "\tsong <song_id> <artist> <duration> <song_title>\n";
            std::cout << "\t\tAdd a song to the library.\n";
            std::cout << "\t\tsong_id\t: non-negative integer ID\n";
            std::cout << "\t\tartist\t: artist name; use double quotes if it contains spaces\n";
            std::cout << "\t\tduration\t: length in seconds\n";
            std::cout << "\t\ttitle\t: song title; use double quotes if it contains spaces\n";
            std::cout << std::endl;

            std::cout << "\tremove <song_title>\n";
            std::cout << "\t\tRemove a song from the library by title.\n";
            std::cout << "\t\ttitle\t: use double quotes if the title contains spaces\n";
            std::cout << std::endl;

            std::cout << "\tlisten <song_title> <seconds>\n";
            std::cout << "\t\tIncrease seconds listened for a song.\n";
            std::cout << "\t\ttitle\t: use double quotes if the title contains spaces\n";
            std::cout << "\t\tseconds\t: non-negative integer\n";
            std::cout << "\t\tNote\t: listens to favorited songs are ignored.\n";
            std::cout << std::endl;

            std::cout << "\tfavorite\n";
            std::cout << "\t\tPromotes your most-listened song (excluding already-favorited songs)\n";
            std::cout << "\t\tto your favorites list. Once added, a song stays in favorites\n";
            std::cout << "\t\tand its future listens are ignored.\n";
            std::cout << std::endl;

            std::cout << "\tshow_listen_time\n";
            std::cout << "\t\tDisplay all songs ordered by song ID, with their total listen time.\n";
            std::cout << std::endl;

            std::cout << "\tquit\n";
            std::cout << "\t\tExit the program.\n";
            std::cout << std::endl;

            std::cout << "\thelp\n";
            std::cout << "\t\tShow this help page.\n";
            std::cout << std::endl;
        }
        else {
            std::cout << "Unknown Input Format." << std::endl;
        }
    }

    return 0;
}

bool isValidUInt(const std::string& input) {
    try {
        int n = std::stoi(input);
        if (n < 0) {
            return false;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> parser(const std::string& inputLine) {
    std::vector<std::string> result;
    std::istringstream inputSS(inputLine);
    std::string str;
    char c;

    while (inputSS.get(c)) {
        // skip white spaces
        if (c == ' ') continue;
        // extract quoted contents
        if (c == '\"') {
            str.clear();
            std::getline(inputSS, str, '\"');
            result.push_back(str);
        }
        // extract strings spread by space
        else {
            str = c;
            while (inputSS.get(c) && c != ' ')
                str += c;
            result.push_back(str);
        }
    }
    return result;
}
