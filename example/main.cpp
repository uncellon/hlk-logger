#include <hlk/logger/logger.h>
#include <hlk/logger/commonmessagebuilder.h>
#include <hlk/logger/terminallogginghandler.h>
#include <hlk/logger/filerotatelogginghandler.h>
#include <hlk/logger/loggermanager.h>
#include <hlk/logger/minilogger.h>

int main(int argc, char* argv[]) {
    // Configure builder
    auto commonInfoMessageBuilder = std::shared_ptr<Hlk::CommonMessageBuilder>(new Hlk::CommonMessageBuilder());
    auto commonErrMessageBuilder = std::shared_ptr<Hlk::CommonMessageBuilder>(new Hlk::CommonMessageBuilder());
    commonErrMessageBuilder->setLoggingLevel(Hlk::CommonMessageBuilder::kError);

    // Configure handlers
    auto fileRotateLoggingHandler = std::shared_ptr<Hlk::FileRotateLoggingHandler>(new Hlk::FileRotateLoggingHandler());
    fileRotateLoggingHandler->setLogFilename("log/common.log");
    fileRotateLoggingHandler->setLogSizeLimit(300);
    fileRotateLoggingHandler->setLogsCountLimit(3);

    auto terminalLoggingHandler = std::shared_ptr<Hlk::TerminalLoggingHandler>(new Hlk::TerminalLoggingHandler());

    // Configure loggers

    Hlk::Logger commonInfoLogger;
    Hlk::Logger commonErrorLogger;
    
    commonInfoLogger.setMessageBuilder(commonInfoMessageBuilder);
    commonInfoLogger.pushHandler(terminalLoggingHandler);
    commonInfoLogger.pushHandler(fileRotateLoggingHandler);

    commonErrorLogger.setMessageBuilder(commonErrMessageBuilder);
    commonErrorLogger.pushHandler(terminalLoggingHandler);
    commonErrorLogger.pushHandler(fileRotateLoggingHandler);

    // Write logs
    commonInfoLogger.write("My info message");
    commonErrorLogger.write("My error message");
    
    auto log = Hlk::LoggerManager::createInstance("my-log");
    log->setMessageBuilder(commonErrMessageBuilder);
    log->pushHandler(terminalLoggingHandler);
    log->write("My error from registered log");

    Hlk::MiniLogger::write("info", "log/mini.log", "My message from MiniLog");

    return 0;
}