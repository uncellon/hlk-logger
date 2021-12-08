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

#include "commonmessagebuilder.h"

namespace Hlk {

/******************************************************************************
 * Methods
 *****************************************************************************/

std::string CommonMessageBuilder::formatCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char hour[3], min[3], sec[3]; // Two digits and null-terminator
    sprintf(hour, "%02d", ltm->tm_hour);
    sprintf(min, "%02d", ltm->tm_min);
    sprintf(sec, "%02d", ltm->tm_sec);
    return std::string(hour) + ":" + min + ":" + sec;
}

std::string CommonMessageBuilder::formatCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char day[3], month[3]; // Two digits and null-terminator
    sprintf(day, "%02hhu", ltm->tm_mday);
    sprintf(month, "%02hhu", ltm->tm_mon + 1);
    return std::to_string(1900 + ltm->tm_year) + "-" + month + "-" + day;
}

/******************************************************************************
 * Accessors / Mutators
 *****************************************************************************/

void CommonMessageBuilder::setLoggingLevel(LoggingLevel loggingLevel) {
    switch (loggingLevel) {
    case kDebug:
        m_loggingLevel = "[debug]";
        break;
    case kError:
        m_loggingLevel = "[err]";
        break;
    case kWarning:
        m_loggingLevel = "[warn]";
        break;
    case kInfo:
        m_loggingLevel = "[info]";
        break;
    }
}

void CommonMessageBuilder::setLoggingLevel(const std::string &loggingLevel) {
    m_loggingLevel = "[" + loggingLevel + "]";
}

} // namespace Hlk