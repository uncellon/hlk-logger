/******************************************************************************
 * 
 * Copyright (C) 2021 Dmitry Plastinin
 * Contact: uncellon@yandex.ru, uncellon@gmail.com, uncellon@mail.ru
 * 
 * This file is part of the Hlk Logger library.
 * 
 * Hlk Logger is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as pubblished by the
 * Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * Hlk Logger is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more
 * details
 * 
 * You should have received a copy of the GNU Lesset General Public License
 * along with Hlk Logger. If not, see <https://www.gnu.org/licenses/>.
 * 
 *****************************************************************************/

#include "logger.h"

#include <fstream>
#include <iostream>
#include <filesystem>

namespace Hlk {

std::string Logger::m_path = "";
unsigned int Logger::m_sizeLimit = 1000000; // Default limit - 1 MB
unsigned int Logger::m_backupLimit = 1;

void Logger::write(const std::string &prefix, const std::string &message, const std::string &logfile) {
    // Get current date and time
    std::string currentDate = formatDate(), currentTime = formatTime();

    /* 
        Sample message:
        2021-10-10 11:40:02 [info] - Measured weight: 138g.
    */
    auto logMessage = 
        currentDate + " " + currentTime + " [" + prefix + "] - " + message;

    // Write to stdout
    std::cout << logMessage << std::endl;

    // Skip writting to file if path is empty or message size is too long
    if (!logfile.size() || logMessage.size() > m_sizeLimit) {
        return;
    }

    // Write to file
    std::ofstream fout(m_path + "/" + logfile, std::ios_base::app);
    if (logMessage.size() + fout.tellp() > m_sizeLimit) { // Rotate log file
        fout.close();
        rotate(logfile);
        fout.open(m_path + "/" + logfile, std::ios_base::app);
    }
    fout << logMessage << std::endl;
    fout.close();
}

void Logger::setPath(const std::string &path) {
    // Check that directory exists
    bool pathExists = std::filesystem::exists(path);

    // Try to create
    if (!pathExists) {
        bool pathCreated = std::filesystem::create_directory(path);
        if (!pathCreated) {
            std::cerr << "Hlk::Logger - Failed to create log path\n";
            return;
        }
    }

    m_path = path;
}

void Logger::setOldLogsLimit(unsigned int count) { 
    if (count == 0) {
        std::cerr << "Hlk::Logger - Logs backup limit must be greater than zero\n";
        return;
    }
    m_backupLimit = count; 
}

std::string Logger::formatTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char hour[3], min[3], sec[3]; // Two digits and null-terminator
    sprintf(hour, "%02d", ltm->tm_hour);
    sprintf(min, "%02d", ltm->tm_min);
    sprintf(sec, "%02d", ltm->tm_sec);
    return std::string(hour) + ":" + min + ":" + sec;
}

std::string Logger::formatDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char day[3], month[3]; // Two digits and null-terminator
    sprintf(day, "%02hhu", ltm->tm_mday);
    sprintf(month, "%02hhu", ltm->tm_mon + 1);
    return std::to_string(1900 + ltm->tm_year) + "-" + month + "-" + day;
}

void Logger::rotate(const std::string &filename) {
    auto filepath = m_path + "/" + filename;
    std::filesystem::remove(filepath + "." + std::to_string(m_backupLimit - 1));
    if (m_backupLimit == 1) {
        std::filesystem::remove(filepath);
        return;
    }
    for (int i = m_backupLimit - 1; i > 0; --i) {
        if (!std::filesystem::exists(filepath + "." + std::to_string(i))) {
            continue;
        }        
        std::filesystem::rename(filepath + "." + std::to_string(i),
                                filepath + "." + std::to_string(i + 1));
    }
    std::filesystem::rename(filepath, filepath + "." + std::to_string(1));
}

} // namespace Hlk