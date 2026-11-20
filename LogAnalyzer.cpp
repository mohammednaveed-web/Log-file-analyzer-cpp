#include<iostream>
#include<fstream>
#include<algorithm>
#include "LogAnalyzer.h"
using namespace std;
void LogAnalyzer::readFile(string filename)
{
        ifstream fin(filename);
        if(!fin)
        {
                cout<<"failed to open the file:"<<endl;
                return;
        }
        struct LogEntry entry;
        while(fin >> entry.date >> entry.time >> entry.level >> entry.ip)
        {
                getline(fin, entry.message);
                logs.push_back(entry);
                levelFreq[entry.level]++;
                ipCount[entry.ip]++;
        }
        fin.close();
}
void LogAnalyzer::showTotal()
{
        cout<<"Total entries are:"<<logs.size()<<endl;
}
void LogAnalyzer::showLevelFrequency()
{
        cout<<"Log level Frequency:"<<endl;
        for(auto p:levelFreq)
                cout<<p.first<<":"<<p.second<<endl;
}
void LogAnalyzer::showErrorLogs()
{
        cout<<"Error Logs:"<<endl;
        for(auto entry:logs)
                if(entry.level=="ERROR")
                        cout<<entry.date<<" "<<entry.time<<" "<<entry.level<<" "
                                <<entry.ip<<" "<<entry.message<<endl;
}
void LogAnalyzer::searchKeyword(string keyword)
{
        cout<<"search results for "<<keyword<<" :"<<endl;
        for(auto entry:logs)
                if(entry.message.find(keyword) !=string::npos)
                        cout<<entry.date<<" "<<entry.time<<" "<<entry.level<<" "
                                <<entry.ip<<" "<<entry.message<<endl;
}
void LogAnalyzer::showTopIPs()
{
    vector<pair<string,int>> ipvec(ipCount.begin(), ipCount.end());

    sort(ipvec.begin(), ipvec.end(), [](auto a, auto b){
        return a.second > b.second;
    });

    cout << "Top 3 IP Addresses:" << endl;
    int limit = min(3, (int)ipvec.size());
    for(int i=0; i<limit; i++)
        cout << ipvec[i].first << " -> " << ipvec[i].second << " requests" << endl;
}

