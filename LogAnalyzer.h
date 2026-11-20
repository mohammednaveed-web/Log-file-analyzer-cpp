#ifndef LOGANALYZER_H
#define LOGANALYZER_H

#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include "LogEntry.h"
using namespace std;

class LogAnalyzer {
    vector<LogEntry> logs;
    map<string, int> levelFreq;
    unordered_map<string, int> ipCount;
public:
    void readFile(string filename);
    void showTotal();
    void showLevelFrequency();
    void showTopIPs();
    void showErrorLogs();
    void searchKeyword(string keyword);
};
#endif
