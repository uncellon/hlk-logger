# Homebrew Libraries Kit - Log
## Usage:
1. Include *log.h* file in your main file and link it with your executable;
2. Set the log path once to output your messages to files.

### Code example:

```cpp
#include "hlk/log/log.h"
#include <iostream>
#include ...

int main(int argc, char *argv[]) {
    try {
        Hlk::Log::setPath("logs");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl
    }
    ...
}
```

## Library usage:

```cpp
...
Hlk::Log::write("prefix", "My message");
...
```

It will create the [log-path]/prefix.log file if it doesn't exist, or just add your message to it:
```
2021-04-22 16:27:34 - My message
```

And will also display a message on the screen:
```
2021-04-22 16:27:34 [prefix] - My message
```

## Tips and tricks
* This library supports the following output formats:
    1. const char *
    2. const std::string &
