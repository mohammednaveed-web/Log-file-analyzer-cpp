#include<iostream>
#include "LogAnalyzer.h"
using namespace std;

int main() 
{
    LogAnalyzer l1;
    l1.readFile("logfile.txt");
    l1.showTotal();
    l1.showLevelFrequency();
    l1.showErrorLogs();
    string keyword;
    cout << "Enter keyword: ";
    cin >> keyword;
    l1.searchKeyword(keyword);
    l1.showTopIPs();
}
