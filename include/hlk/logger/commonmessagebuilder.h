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

#ifndef HLK_COMMON_MESSAGE_BUILDER_H
#define HLK_COMMON_MESSAGE_BUILDER_H

#include "abstractmessagebuilder.h"

namespace Hlk {

class CommonMessageBuilder : public AbstractMessageBuilder {
public:
    enum LoggingLevel {
        kDebug,
        kInfo,
        kWarning,
        kError
    };

    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual std::string build(const std::string &message) override {
        std::string currentDate = formatDate(), currentTime = formatTime();
        return currentDate + " " + currentTime + " " + m_loggingLevel + " - " + message;
    }

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    void setLoggingLevel(LoggingLevel loggingLevel);
    void setLoggingLevel(const std::string &loggingLevel);

protected:
    /**************************************************************************
     * Protected methods
     *************************************************************************/

    std::string formatTime();
    std::string formatDate();

    /**************************************************************************
     * Members
     *************************************************************************/

    std::string m_loggingLevel = "[info]";
};

} // namespace Hlk

#endif // HLK_COMMON_MESSAGE_BUILDER_H