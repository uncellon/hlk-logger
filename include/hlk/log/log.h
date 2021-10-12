#ifndef HLK_LOG_H
#define HLK_LOG_H

#include <string>

namespace Hlk {

class Log {
public:
    static void write(const std::string &prefix, const std::string &msg);
    static void setPath(const std::string &path);
    static void setLogSizeLimit(unsigned int bytes);
    static void setLogsCountLimit(unsigned int count);

    // Helpers
    static void write(const char *prefix, const char *msg);
    static void setPath(const char *path);

protected:
    static std::string formatTime();
    static std::string formatDate();
    static void rotate(const std::string &prefix);

    static std::string m_path;
    static unsigned int m_logSizeLimit;
    static unsigned int m_logsCountLimit;
};

/*******************************************************************************
 * Inline
 ******************************************************************************/

inline void Log::setPath(const char *path) { setPath(std::string(path)); }
inline void Log::write(const char *prefix, const char *msg) { write(std::string(prefix), std::string(msg)); }

} // namespace Hlk

#endif // HLK_LOG_H