#ifndef HLK_LOGGER_MANAGER_H
#define HLK_LOGGER_MANAGER_H

#include "logger.h"

#include <map>

namespace Hlk {

class LoggerManager {
public:
    static Hlk::Logger *getInstance(const std::string &name) {
        return m_loggersByNames[name];
    }

    static Hlk::Logger *createInstance(const std::string &name) {
        m_loggersByNames[name] = new Hlk::Logger();
        return m_loggersByNames[name];
    }

protected:
    static std::map<std::string, Hlk::Logger *> m_loggersByNames;
};

} // namespace Hlk

#endif // HLK_LOGGER_MANAGER_H