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

#ifndef HLK_LOG_H
#define HLK_LOG_H

#include <string>

namespace Hlk {

class Logger {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    /**
     * @brief Write formatted message to stdout and file
     * 
     * Formatted message sample: 
     * "2021-10-10 11:40:02 [info] - Measured weight: 138g."
     * 
     * If formatted message size bigger than sizeLimit(...), then message 
     * will not be saved into the file
     * 
     * @param prefix The message prefix, printed in square brackets before the 
     * message 
     * @param message Main message
     * @param logfile Log filename. If path(...) is empty, default path will be 
     * used
     */
    static void write(const std::string &prefix, const std::string &message, const std::string &logfile = "");

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    static std::string path();
    static void setPath(const std::string &path);

    static unsigned int sizeLimit();
    static void setSizeLimit(unsigned int bytes);

    static unsigned int oldLogsLimit();
    static void setOldLogsLimit(unsigned int count);

    /**************************************************************************
     * Helpers
     *************************************************************************/

    static void write(const char *prefix, const char *message, const char *logfile);

    static void path(const char *output);
    static void setPath(const char *path);

protected:
    /**************************************************************************
     * Methods
     *************************************************************************/

    static std::string formatTime();
    static std::string formatDate();
    static void rotate(const std::string &logfile);

    /**************************************************************************
     * Members
     *************************************************************************/

    static std::string m_path;
    static unsigned int m_sizeLimit;
    static unsigned int m_backupLimit;

}; // class Logger

/******************************************************************************
 * Inline definition: Accessors / Mutators
 *****************************************************************************/

inline std::string Logger::path() { return m_path; }

inline unsigned int Logger::sizeLimit() { return m_sizeLimit; }
inline void Logger::setSizeLimit(unsigned int bytes) { m_sizeLimit = bytes; }

inline unsigned int Logger::oldLogsLimit() { return m_backupLimit; }

/******************************************************************************
 * Inline definition: Helpers
 *****************************************************************************/

inline void Logger::write(const char *prefix, const char *message, const char *logfile) {
    write(std::string(prefix), std::string(message), std::string(logfile));
}

inline void Logger::path(const char *output) {
    output = path().c_str();
}
inline void Logger::setPath(const char *path) { setPath(std::string(path)); }

} // namespace Hlk

#endif // HLK_LOG_H