# Homebrew Libraries Kit - Logger

- [Features](#features)
- [Examples](#examples)
    - [Simple log write](#simple-log-write)

## <a name="features"></a> Features
- Message printing to stdout
- Message writing to logfile, if log path is setted
- Few log message levels:
    - information with *[info]* prefix
    - warning with *[warn]* prefix
    - error with *[err]* prefix

## <a name="examples"></a> Examples

### <a name="simple-log-write"></a> Simple log write
You can write message to the log simply by calling the static "write" method, as you can see below:

```cpp
Hlk::Logger::write("My log message");
```

The message that will be displayed on the screen may look like this:
```
2021-30-10 00:34 [info] - My log message
```


## License
<img align="right" src="https://www.gnu.org/graphics/lgplv3-with-text-154x68.png">

The library is licensed under [GNU Lesser General Public License 3.0](https://www.gnu.org/licenses/lgpl-3.0.txt):

Copyright © 2021 Dmitry Plastinin

Hlk Logger is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as pubblished by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Hlk Logger is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more details