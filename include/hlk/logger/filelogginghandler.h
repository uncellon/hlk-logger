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

#ifndef HLK_FILE_LOGGING_HANDLER_H
#define HLK_FILE_LOGGING_HANDLER_H

#include "abstractlogginghandler.h"

#include <fstream>

namespace Hlk {

class FileLoggingHandler : public AbstractLoggingHandler {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual void write(const std::string &message) override {
        std::ofstream fout(m_logFilename, std::ios_base::app);        
        fout << message << std::endl;
        fout.close();
    }

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    std::string logFilename() const;
    void setLogFilename(const std::string &filename);

protected:
    std::string m_logFilename = "common.log";
};

/******************************************************************************
 * Inline definition: Accessors / Mutators
 *****************************************************************************/

inline std::string FileLoggingHandler::logFilename() const { return m_logFilename; }
inline void FileLoggingHandler::setLogFilename(const std::string &filename) { m_logFilename = filename; }

} // namespace Hlk

#endif // HLK_FILE_LOGGING_HANDLER_H