#include <hlk/logger/logger.h>
#include <hlk/logger/basicmessagelayout.h>
#include <hlk/logger/terminallogginghandler.h>
#include <hlk/logger/filerotatelogginghandler.h>
#include <hlk/logger/minilogger.h>

int main(int argc, char* argv[]) {
    // Configure handlers
    auto fileRotateLoggingHandler = std::shared_ptr<Hlk::FileRotateLoggingHandler>(new Hlk::FileRotateLoggingHandler());
    fileRotateLoggingHandler->setLogFilename("log/common.log");
    fileRotateLoggingHandler->setLogSizeLimit(300);
    fileRotateLoggingHandler->setLogsCountLimit(3);

    auto terminalLoggingHandler = std::shared_ptr<Hlk::TerminalLoggingHandler>(new Hlk::TerminalLoggingHandler());

    // Configure loggers

    Hlk::Logger<Hlk::BasicMessageLayout> commonInfoLogger;
    Hlk::Logger<Hlk::BasicMessageLayout> commonErrorLogger;
    
    commonInfoLogger.pushHandler(terminalLoggingHandler);
    commonInfoLogger.pushHandler(fileRotateLoggingHandler);

    commonErrorLogger.pushHandler(terminalLoggingHandler);
    commonErrorLogger.pushHandler(fileRotateLoggingHandler);

    // Write logs
    commonInfoLogger.write("INFO", "My info message");
    commonErrorLogger.write("ERROR", "My error message");
    
    auto log = Hlk::Logger<Hlk::BasicMessageLayout>::getInstance("my-log");
    log->pushHandler(terminalLoggingHandler);
    log->write("CUSTOM", "My error from registered log");

    Hlk::MiniLogger::write("info", "log/mini.log", "My message from MiniLog");

    return 0;
}