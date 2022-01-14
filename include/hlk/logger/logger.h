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

#include "abstractlogginghandler.h"

#include <map>
#include <mutex>
#include <vector>
#include <memory>

namespace Hlk {

template<class TMessageLayout>
class Logger {
public:
    /**************************************************************************
     * Constructors / Destructors
     *************************************************************************/

    Logger() {
        m_layout = std::shared_ptr<TMessageLayout>(new TMessageLayout());
    }

    ~Logger() {
        m_handlers.clear();
    }

    /**************************************************************************
     * Methods
     *************************************************************************/

    template<class... TLayoutArgs>
    void write(TLayoutArgs... args) {
        auto formattedMessage = m_layout->build(args...);

        for (size_t i = 0; i < m_handlers.size(); ++i) {
            m_handlers[i]->write(formattedMessage);
        }
    }

    void pushHandler(std::shared_ptr<AbstractLoggingHandler> handler) {
        m_handlers.emplace_back(handler);
    }

    static Logger *getInstance(const std::string &name) {
        std::unique_lock lock(m_instanceMutex);
        if (m_loggersByNames.find(name) == m_loggersByNames.end()) {
            m_loggersByNames[name] = new Logger();
        }
        return m_loggersByNames[name];
    }

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    std::shared_ptr<TMessageLayout> layout() const {
        return m_layout;
    }

protected:
    /**************************************************************************
     * Members
     *************************************************************************/

    std::shared_ptr<TMessageLayout> m_layout = nullptr;
    std::vector<std::shared_ptr<AbstractLoggingHandler>> m_handlers;

    static std::mutex m_instanceMutex;
    static std::map<std::string, Logger<TMessageLayout> *> m_loggersByNames;

}; // class Logger

template<class TMessageLayout>
std::mutex Logger<TMessageLayout>::m_instanceMutex;

template<class TMessageLayout>
std::map<std::string, Logger<TMessageLayout> *> Logger<TMessageLayout>::m_loggersByNames;

} // namespace Hlk

#endif // HLK_LOGGER_H