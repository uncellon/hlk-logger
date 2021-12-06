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

#ifndef HLK_LOGGER_H
#define HLK_LOGGER_H

#include "abstractmessagebuilder.h"
#include "abstractlogginghandler.h"

#include <vector>
#include <memory>

namespace Hlk {

class Logger {
public:
    /**************************************************************************
     * Constructors / Destructors
     *************************************************************************/

    ~Logger();

    /**************************************************************************
     * Methods
     *************************************************************************/

    void write(const std::string &message);    
    void pushHandler(std::shared_ptr<AbstractLoggingHandler> handler);

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    std::shared_ptr<AbstractMessageBuilder> messageBuilder() const;
    void setMessageBuilder(std::shared_ptr<AbstractMessageBuilder> builder);

    /**************************************************************************
     * Helpers
     *************************************************************************/

    void write(const char *message);

protected:
    /**************************************************************************
     * Members
     *************************************************************************/

    std::shared_ptr<AbstractMessageBuilder> m_messageBuilder = nullptr;
    std::vector<std::shared_ptr<AbstractLoggingHandler>> m_handlers;

}; // class Logger

/******************************************************************************
 * Inline definition: Methods
 *****************************************************************************/

inline void Logger::pushHandler(std::shared_ptr<AbstractLoggingHandler> handler) {
    m_handlers.emplace_back(handler);
}

/******************************************************************************
 * Inline definition: Accessors / Mutators
 *****************************************************************************/ 

inline std::shared_ptr<AbstractMessageBuilder> Logger::messageBuilder() const {
    return m_messageBuilder;
}

inline void Logger::setMessageBuilder(std::shared_ptr<AbstractMessageBuilder> builder) { 
    m_messageBuilder = builder;
}

/******************************************************************************
 * Inline definition: Helpers
 *****************************************************************************/

inline void Logger::write(const char *message) { write(std::string(message)); }

} // namespace Hlk

#endif // HLK_LOGGER_H