#ifndef HLK_LOG_H
#define HLK_LOG_H

#include <string>

namespace Hlk {

class Log {
public:
    static void setPath(const std::string &path);
    static void write(const std::string &prefix, const std::string &msg);

    // Helpers
    static void setPath(const char *path);
    static void write(const char *prefix, const char *msg);

protected:
    static std::string formatTime();
    static std::string formatDate();

    static std::string path_;
};

/*******************************************************************************
 * Inline
 ******************************************************************************/

inline void Log::setPath(const char *path) { setPath(std::string(path)); }
inline void Log::write(const char *prefix, const char *msg) { write(std::string(prefix), std::string(msg)); }

} // namespace Hlk

#endif // HLK_LOG_H