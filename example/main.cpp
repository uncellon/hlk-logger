#include <hlk/log/log.h>

int main(int argc, char* argv[]) {
    Hlk::Log::setPath("logs");
    Hlk::Log::write("weight", "Measured weight: 138g");
    return 0;
}