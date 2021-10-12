#include "log.h"

#include <fstream>
#include <iostream>
#include <filesystem>

namespace Hlk {

std::string Log::m_path = "";
unsigned int Log::m_logSizeLimit = 0;
unsigned int Log::m_logsCountLimit = 1;

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

    m_path = path;
}

void Log::setLogSizeLimit(unsigned int bytes) {
    m_logSizeLimit = bytes;
}

void Log::setLogsCountLimit(unsigned int count) {
    if (count == 0) {
        std::cerr << "Hlk::Log - Logs limit must be greater than zero\n";
        return;
    }
    m_logsCountLimit = count;
}

void Log::write(const std::string &prefix, const std::string &msg) {
    // Get date and time
    std::string currentDate = formatDate(), currentTime = formatTime();

    /* Write message to stdout, example: 
       Message: "2021-04-22 16:12:20 [weight] - measured weight: 138g" */
    std::cout << currentDate << " " << currentTime << " [" << prefix << "] - " << msg << std::endl;

    // Skip writting if path is empty
    if (m_path.empty() || msg.size() > m_logSizeLimit) {
        return;
    }

    /* Write message to file, example:
       Filename: "weight.log"
       Message: "2021-04-22 16:12:20 - measured weight: 138g" */
    std::ofstream fout(m_path + "/" + prefix + ".log.0", std::ios_base::app);
    if (msg.size() + fout.tellp() > m_logSizeLimit) {
        fout.close();
        rotate(prefix);
        fout.open(m_path + "/" + prefix + ".log.0", std::ios_base::app);
    }
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

void Log::rotate(const std::string &prefix) {
    std::string logNameTemplate = m_path + "/" + prefix + ".log.";
    std::filesystem::remove(logNameTemplate + std::to_string(m_logsCountLimit - 1));
    if (m_logsCountLimit == 1) {
        return;
    }
    for (int i = m_logsCountLimit - 1; i >= 0; --i) {
        if (!std::filesystem::exists(logNameTemplate + std::to_string(i))) {
            continue;
        }        
        std::filesystem::rename(logNameTemplate + std::to_string(i),
                                logNameTemplate + std::to_string(i + 1));
    }
}

} // namespace Hlk