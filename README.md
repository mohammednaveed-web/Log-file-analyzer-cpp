# Log File Analyzer — C++

A command-line log file analyzer built in C++ using STL containers.
Reads server log entries from a file and provides useful statistics.

## Features
- Total log count
- Log level frequency (INFO, WARN, ERROR)
- Top 3 most frequent IP addresses
- Filter and display ERROR logs
- Keyword-based log search

## STL Containers Used
- vector — store all log entries
- map — log level frequency (sorted)
- unordered_map — IP request count (fast lookup)
- algorithm (sort) — rank IPs by request count

## Project Structure
loganalyzer/
├── LogEntry.h        — struct for one log entry
├── LogAnalyzer.h     — class declaration
├── LogAnalyzer.cpp   — feature implementations
├── main.cpp          — entry point
├── logfile.txt       — sample log file
└── Makefile          — build configuration

## Build & Run
make
./loganalyzer

## Sample Output
Total entries: 10
Log Level Frequency: ERROR:3  INFO:5  WARN:2
Top 3 IPs: 192.168.0.1 → 4 requests
