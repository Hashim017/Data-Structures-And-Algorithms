#pragma once
#include <iostream>
#include <list>
#include "currentFile.cpp"
using namespace std;
class File
{
    friend class Folder;
    friend class Dos;
    private:
        string name;
        string path;
        string time;
        currentFile* currFile;
    public:
        File(string name = "", string path ="")
        {
            this -> name = name;
            this -> path = path;
            this -> time = getTime();
            currFile = new currentFile(name);
        }
        string getTime()
        {
            string time = "";
            auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            tm* localTime = localtime(&currentTime);
            string year = to_string(localTime -> tm_year + 1900);
            string month = to_string(localTime -> tm_mon + 1);
            string days = to_string(localTime -> tm_mday);
            string hours = to_string(localTime -> tm_hour);
            string minutes = to_string(localTime -> tm_min);
            time = days + "/" + month + "/" + year + " " + hours + ":" + minutes;
            return time;
        }

};