#include "log.h"

#include <fstream>
#include <iostream>
#include <filesystem>

namespace Hlk {

std::string Log::path_ = "";

void Log::setPath(const std::string &path) {
    // Check that directory exists
    bool pathExists = std::filesystem::exists(path);

    // Try to create
    if (!pathExists) {
        bool pathCreated = std::filesystem::create_directory(path);
        if (!pathCreated) {
            return;
        }
    }

    path_ = path;
}

void Log::write(const std::string &prefix, const std::string &msg) {
    // Get date and time
    std::string currentDate = formatDate(), currentTime = formatTime();

    /* Write message to stdout, example: 
       Message: "2021-04-22 16:12:20 [weight] - measured weight: 138g" */
    std::cout << currentDate << " " << currentTime << " [" << prefix << "] - " << msg << std::endl;

    // Skip writting if path is empty
    if (path_.empty()) {
        return;
    }

    /* Write message to file, example:
       Filename: "weight.log"
       Message: "2021-04-22 16:12:20 - measured weight: 138g" */
    std::ofstream fout(path_ + "/" + prefix + ".log", std::ios_base::app);
    fout << currentDate << " " << currentTime << " - " << msg << std::endl;
    fout.close();
}

std::string Log::formatTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char hour[3], min[3], sec[3]; // Two digits and null-terminator
    sprintf(hour, "%02d", ltm->tm_hour);
    sprintf(min, "%02d", ltm->tm_min);
    sprintf(sec, "%02d", ltm->tm_sec);
    return std::string(hour) + ":" + min + ":" + sec;
}

std::string Log::formatDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char day[3], month[3]; // Two digits and null-terminator
    sprintf(day, "%02hhu", ltm->tm_mday);
    sprintf(month, "%02hhu", ltm->tm_mon + 1);
    return std::to_string(1900 + ltm->tm_year) + "-" + month + "-" + day;
}

} // namespace Hlk