# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Unreleased

## 3.0.2 - 2021-12-08
### Added
- MiniLog to simple write message into cout and file.

## 3.0.1 - 2021-12-08
### Added
- LoggerManager for static allocate loggers. This should make it easier to instantiate the logging class in another class.

## 3.0.0 - 2021-12-06

### Added
- Support for custom log handlers.
- TerminalLoggerHandler for print in terminal.
- FileLoggingHandler for writting messages to file.
- FileRotateLoggingHandler for writting messages to file with log rotate support.
- Support for custom message builders.
- CommonMessageBuilder for writting messages in format: "2021-12-06 09:59:45 [info] - My message".

## 2.0.0 - 2021-10-29
### Added
- Ability to specify a name for the log file.

### Changed
- Class name renamed from "Log" to "Logger".
- CMake project renamed from "HlkLog" to "HlkLogger". Aliases renamed too from "Hlk::Log" to "Hlk::Logger".

### Removed
- "Prefix" system. Now all available prefixes of logs are "info", "warn", "err".

### Fixed
- Log rotate file names. Now primary log used original log name, all old logs are named with postfix like custom.log.1, custom.log.2, etc.
- Log size limit. Now limit based on final log message instead a raw.

## 1.0.1 - 2021-10-12
### Added

- Log rotate.