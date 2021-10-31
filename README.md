# Homebrew Libraries Kit - Logger

- [Features](#features)
- [Examples](#examples)
    - [Setting log path](#setting-log-path)
    - [Setting log size limit](#setting-log-size-limit)
    - [Setting old logs limit](#setting-old-logs-limit)
    - [Write to stdout only](#write-to-stdout-only)
    - [Write to stdout and log file](#write-to-stdout-and-log-file)

## <a name="features"></a> Features
- Message printing to stdout
- Message writing to file
- Log rotate

## <a name="examples"></a> Examples

### <a name="setting-log-path"></a> Setting log path
```cpp
Hlk::Logger::setPath("log");
```

### <a name="setting-log-size-limit"></a> Setting log size limit
```cpp
Hlk::Logger::setSizeLimit(10485760); // 10 MiB
```

### <a name="setting-old-logs-limit"></a> Setting old logs limit
```cpp
Hlk::Logger::setOldLogsLimit(5);
```

### <a name="write-to-stdout-only"></a> Write to stdout only
```cpp
Hlk::Logger::write("info", "My message");
```

### <a name="write-to-stdout-and-log-file"></a> Write to stdout and log file
```cpp
Hlk::Logger::write("info", "My message", "common.log");
```

## License
<img align="right" src="https://www.gnu.org/graphics/lgplv3-with-text-154x68.png">

The library is licensed under [GNU Lesser General Public License 3.0](https://www.gnu.org/licenses/lgpl-3.0.txt):

Copyright © 2021 Dmitry Plastinin

Hlk Logger is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as pubblished by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Hlk Logger is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more details