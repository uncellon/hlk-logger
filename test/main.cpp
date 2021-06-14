#include "log.h"

int main(int argc, char* argv[]) {
    rtl::Log::set_path("logs");
    rtl::Log::write("weight", "measured weight: 138g");
    return 0;
}