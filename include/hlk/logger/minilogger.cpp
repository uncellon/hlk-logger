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

#include "minilogger.h"
#include "commonmessagebuilder.h"

#include <fstream>
#include <iostream>
#include <filesystem>

namespace Hlk {

unsigned int MiniLogger::m_logSizeLimit = 1000000;
unsigned int MiniLogger::m_logsCountLimit = 5;

/******************************************************************************
 * Methods
 *****************************************************************************/

void MiniLogger::write(const std::string &level, const std::string &path, const std::string &message) {
    std::string currentDate = CommonMessageBuilder::formatCurrentDate();
    std::string currentTime = CommonMessageBuilder::formatCurrentTime();
    std::string formattedMessage = currentDate + " " + currentTime + " [" + level + "] - " + message;

    std::cout << formattedMessage << std::endl;

    std::ofstream fout(path, std::ios_base::app);

    // Rotate log file
    if (formattedMessage.size() + fout.tellp() > m_logSizeLimit) {
        fout.close();
        
        std::filesystem::remove(path + "." + std::to_string(m_logsCountLimit - 1));
        if (m_logsCountLimit == 1) {
            std::filesystem::remove(path);
            return;
        }
        for (int i = m_logsCountLimit - 1; i > 0; --i) {
            if (!std::filesystem::exists(path + "." + std::to_string(i))) {
                continue;
            }        
            std::filesystem::rename(path + "." + std::to_string(i),
                                    path + "." + std::to_string(i + 1));
        }
        std::filesystem::rename(path, path + "." + std::to_string(1));

        fout.open(path, std::ios_base::app);
    }
    
    fout << formattedMessage << std::endl;
    fout.close();
}

/******************************************************************************
 * Accessors / Mutators
 *****************************************************************************/

unsigned int MiniLogger::logSizeLimit() {
    return m_logSizeLimit;
}

void MiniLogger::setLogSizeLimit(unsigned int bytes) {
    m_logSizeLimit = bytes;
}

unsigned int MiniLogger::logsCountLimit() {
    return m_logsCountLimit;
}

void MiniLogger::setLogsCountLimit(unsigned int count) {
    m_logsCountLimit = count;
}

} // namespace Hlk