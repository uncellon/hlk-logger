#include <hlk/log/log.h>

int main(int argc, char* argv[]) {
    Hlk::Log::setPath("logs");
    Hlk::Log::setLogsCountLimit(3);
    Hlk::Log::setLogSizeLimit(100);
    Hlk::Log::write("weight", "Measured weight: 138g");
    return 0;
}