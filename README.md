# Homebrew Libraries Kit - Logger

- [Description](#description)
- [Prerequisites](#prerequisites)
- [Examples](#examples)
    - [MiniLogger](#minilogger)
    - [Full example](#full-example)

## Description

Logging library for C++

## Prerequisites

- C++17 or higher
- CMake >= 3.16

## Examples

### MiniLogger

MiniLogger is helper class that provides quickly write messages to the std::cout and file (with rotation support).

```cpp
Hlk::MiniLogger::setLogSizeLimit(1000000); // 1 MB
Hlk::MiniLogger::setLogsCountLimit(5); // 5 logs max

Hlk::MiniLogger::write("WARN", "log/common.log", "Warn message");
```

### Full example

```cpp
auto logger = Hlk::Logger<Hlk::BasicMessageLayout>::getInstance("common");

// Configure handlers
auto tHandler = std::shared_ptr<Hlk::TerminalLoggingHandler>(new Hlk::TerminalLoggingHandler());

auto frlHandler = std::shared_ptr<Hlk::FileRotateLoggingHandler>(new Hlk::FileRotateLoggingHandler());
frlHandler->setLogFilename("log/common.log");
frlHandler->setLogSizeLimit(1000000); // 1 MB
frlHandler->setLogsCountLimit(5); // 5 logs max

logger->addHandler(tHandler);
logger->addHandler(frlHandler);

logger->write("INFO", "My info message"); // Will print "2022-01-14 15:04:30 [INFO] - My info message" on the console
```

## License
<img align="right" src="https://www.gnu.org/graphics/lgplv3-with-text-154x68.png">

The library is licensed under [GNU Lesser General Public License 3.0](https://www.gnu.org/licenses/lgpl-3.0.txt):

Copyright © 2021 Dmitry Plastinin

Hlk Logger is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as pubblished by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Hlk Logger is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more details