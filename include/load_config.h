#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

map<string, string> load_config(string path)
{
    ifstream configfile;
    map<string, string> cfg;
    configfile.open(path, ios::in);
    string line;
    cfg = map<string, string>();
    while (getline(configfile, line))
    {
        int flag = line.find("=");
        if (flag != string::npos)
        {
            cfg[line.substr(0, flag)] = line.substr(flag + 1);
        }
    }
    configfile.close();
    return cfg;
}