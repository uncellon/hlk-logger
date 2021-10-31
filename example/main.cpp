#include <hlk/logger/logger.h>

int main(int argc, char* argv[]) {
    Hlk::Logger::setPath("log");
    Hlk::Logger::setOldLogsLimit(3);
    Hlk::Logger::setSizeLimit(300);

    Hlk::Logger::write("info", "Program started", "common.log");
    Hlk::Logger::write("warn", "Some file not exists, created", "common.log");
    Hlk::Logger::write("err", "Resource not found", "common.log");
    
    return 0;
}