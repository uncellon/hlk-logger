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
    enum Level {
        kInfo,
        kWarn,
        kErr
    };

    static void write(const std::string &msg, Level level = kInfo, const std::string &logfile = m_logfile);
    static void setPath(const std::string &path);
    static void setLogSizeLimit(unsigned int bytes);
    static void setLogsCountLimit(unsigned int count);
    static void setDefaultLogfile(const std::string &logfile);

    // Helpers
    static void write(const char *msg, Level level = kInfo, const char *logfile = m_logfile.c_str());
    static void setPath(const char *path);
    static void setDefaultLogfile(const char *logfile);

protected:
    static std::string formatTime();
    static std::string formatDate();
    static void rotate(const std::string &logfile);

    static std::string m_levels[];
    static std::string m_path;
    static std::string m_logfile;
    static unsigned int m_logSizeLimit;
    static unsigned int m_logsCountLimit;

}; // class Logger

/*******************************************************************************
 * Inline
 ******************************************************************************/

inline void Logger::setLogSizeLimit(unsigned int bytes) { m_logSizeLimit = bytes; }

inline void Logger::setDefaultLogfile(const std::string &logfile) { m_logfile = logfile; }

inline void Logger::setPath(const char *path) { setPath(std::string(path)); }

inline void Logger::write(const char *msg, Level level, const char *logfile) { 
    write(std::string(msg), level, std::string(logfile)); 
}

inline void Logger::setDefaultLogfile(const char *logfile) { setDefaultLogfile(std::string(logfile)); }

} // namespace Hlk

#endif // HLK_LOG_H