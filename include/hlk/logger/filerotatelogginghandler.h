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

#ifndef HLK_FILE_ROTATE_LOGGING_HANDLER
#define HLK_FILE_ROTATE_LOGGING_HANDLER

#include "filelogginghandler.h"

#include <fstream>
#include <filesystem>

namespace Hlk {

class FileRotateLoggingHandler : public FileLoggingHandler {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual void write(const std::string &message) override {
        std::ofstream fout(m_logFilename, std::ios_base::app);

        // Rotate log file
        if (message.size() + fout.tellp() > m_logSizeLimit) {
            fout.close();
            
            std::filesystem::remove(m_logFilename + "." + std::to_string(m_logsCountLimit - 1));
            if (m_logsCountLimit == 1) {
                std::filesystem::remove(m_logFilename);
                return;
            }
            for (int i = m_logsCountLimit - 1; i > 0; --i) {
                if (!std::filesystem::exists(m_logFilename + "." + std::to_string(i))) {
                    continue;
                }        
                std::filesystem::rename(m_logFilename + "." + std::to_string(i),
                                        m_logFilename + "." + std::to_string(i + 1));
            }
            std::filesystem::rename(m_logFilename, m_logFilename + "." + std::to_string(1));

            fout.open(m_logFilename, std::ios_base::app);
        }
        
        fout << message << std::endl;
        fout.close();
    }

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    unsigned int logSizeLimit() const;
    void setLogSizeLimit(unsigned int bytes);

    unsigned int logsCountLimit() const;
    void setLogsCountLimit(unsigned int limit);

protected:
    unsigned int m_logSizeLimit = 0;
    unsigned int m_logsCountLimit = 0;
};

/******************************************************************************
 * Inline definition: Accessors / Mutators
 *****************************************************************************/

inline unsigned int FileRotateLoggingHandler::logSizeLimit() const { return m_logSizeLimit; }
inline void FileRotateLoggingHandler::setLogSizeLimit(unsigned int bytes) { m_logSizeLimit = bytes; }

inline unsigned int FileRotateLoggingHandler::logsCountLimit() const { return m_logsCountLimit; }
inline void FileRotateLoggingHandler::setLogsCountLimit(unsigned int limit) { m_logsCountLimit = limit; }

} // namespace Hlk

#endif // HLK_FILE_ROTATE_LOGGING_HANDLER