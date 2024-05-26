#include <iostream>
#include <list>
#include <string>
#include <chrono>
#include <ctime>
#include "File.cpp"
#pragma once
using namespace std;
class Folder
{
    friend class Dos;
    friend class Tree;

private:
    string name;
    string time;
    list<Folder *> subFolders;
    list<File *> files;
    Folder *parent;
    string path;

public:
    Folder(string name = "", Folder *parent = nullptr, string path = " ")
    {
        this->name = name;
        this->parent = parent;
        this->path = path;
        this->time = getTime();
        subFolders = list<Folder *>();
        files = list<File *>();
    }
    string getTime()
    {
        string time = "";
        auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        tm *localTime = localtime(&currentTime);
        string year = to_string(localTime->tm_year + 1900);
        string month = to_string(localTime->tm_mon + 1);
        string days = to_string(localTime->tm_mday);
        string hours = to_string(localTime->tm_hour);
        string minutes = to_string(localTime->tm_min);
        time = days + "/" + month + "/" + year + " " + hours + ":" + minutes;
        return time;
    }
    void insertSubFolder(string name)
    {
        char slash = '\0';
        if (name == "V:")
        {
            return;
        }
        if (path[path.length() - 1] != '\\')
        {
            slash = 92;
            Folder *temp = new Folder(name, this, path + slash + name);
            subFolders.push_back(temp);
        }
        else
        {
            Folder *temp = new Folder(name, this, path + name);
            subFolders.push_back(temp);
        }
    }
    Folder *findFolder(string folderName)
    {
        list<Folder *>::iterator it;
        for (it = subFolders.begin(); it != subFolders.end(); it++)
        {
            if ((*it)->name == folderName)
            {
                return (*it);
            }
        }
        return nullptr;
    }
    void insertFile(string name)
    {
        File *temp = new File(name);
        files.push_back(temp);
    }
    void printCurrentPath()
    {
        cout << this->path << endl;
    }
    void printCurrentDir()
    {

        cout << " Volume in drive " << path[0] << " is System" << endl;
        cout << " Volume Serial Number is "
             << "795238" << endl
             << endl;
        cout << " Directory of " << path << endl
             << endl;
             int dir_s = 0;
             int file_s = 0;
        list<Folder *>::iterator it;
        for (it = subFolders.begin(); it != subFolders.end(); it++,dir_s++)
        {
            
            cout << time << "\t"
                 << "<DIR>"
                 << "\t" << (*it)->name << endl;
        }
        list<File *>::iterator fi;
        for (fi = files.begin(); fi != files.end(); fi++,file_s++)
        {
            cout << time << "\t\t" << (*fi)->name << endl;
        }
       
        cout << "\t\t" << file_s << " File(s)"<< endl;
        cout << "\t\t" << dir_s << " Dir(s)"<< endl;
    }
    void removeDir(Folder *folder)
    {
        while (!folder->subFolders.empty())
        {
            Folder *f = folder->subFolders.front();
            folder->subFolders.pop_front();
            removeDir(f);
        }
        for (auto i : folder->files)
        {
            delete i;
        }
        folder->files.clear();
        if (folder->parent != nullptr)
        {
            folder->parent->subFolders.remove(folder);
            delete folder;
        }
    }
    File *findFile(string name)
    {
        list<File *>::iterator it;
        for (it = files.begin(); it != files.end(); it++)
        {
            if ((*it)->name == name)
            {
                return (*it);
            }
        }
        return nullptr;
    }
    void renameFile(File *file, string newName)
    {
        if (file != nullptr)
        {
            file->name = newName;
        }
    }
    Folder *findPath(string location, Folder *curr)
    {
        if (location == curr->path)
        {
            return curr;
        }
        for (Folder *f : curr->subFolders)
        {
            Folder *result = findPath(location, f);
            if (result != nullptr)
            {
                return result;
            }
        }
        return nullptr;
    }
    void deleteFile(File *f)
    {
        this->files.remove(f);
    }

    void printTreeHelper(Folder *folder, int level, bool isLastChild)
    {
        if (folder == nullptr)
        {
            return;
        }

        // Print the current folder
        for (int i = 0; i < level - 1; ++i)
        {
            cout << "  "; // Adjust the indentation level
            cout << (i == level - 2 ? "|_______" : "     ");
        }

        if (level > 0)
        {
            if (isLastChild)
            {
                cout << "`_______";
            }
            else
            {
                cout << "|_______";
            }
        }
        cout << folder->name << endl;

        // Print files in the current folder
        for (const auto &file : folder->files)
        {
            for (int i = 0; i < level; ++i)
            {
                cout << "  "; // Adjust the indentation level for files
                cout << (i == level - 1 ? "|_______" : "     ");
            }
            cout << file->name << endl;
        }

        // Recursively print subfolders
        for (const auto &subfolder : folder->subFolders)
        {
            printTreeHelper(subfolder, level + 1, &subfolder == &folder->subFolders.back());
        }
    }
    void PrintTree(Folder *root)
    {
        cout << "Directory Tree:" << endl;
        printTreeHelper(root, 0, true);
    }
};
