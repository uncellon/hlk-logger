#include <hlk/logger/logger.h>

int main(int argc, char* argv[]) {
    Hlk::Logger::setPath("log");
    Hlk::Logger::setLogsCountLimit(3);
    Hlk::Logger::setLogSizeLimit(100);

    Hlk::Logger::write("Info message");
    Hlk::Logger::write("Warn message", Hlk::Logger::kWarn);
    Hlk::Logger::write("Error message", Hlk::Logger::kErr);

    Hlk::Logger::write("Info message", Hlk::Logger::kInfo, "custom.log");
    return 0;
}