
#ifndef tree_h 
#define tree_h
#include <iostream>
#include "Folder.cpp"
// #include "Dos.cpp"

#pragma once
using namespace std;

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


class Tree
{
    friend class Dos;
    private:
        Folder* current;
        Folder* root;
    public:
        Tree()
        {
            root = current = new Folder("V:", nullptr, "V:\\");
        }
        void goToSubFolder(string folderName)
        {
            Folder* temp = current->findFolder(folderName);
            if (temp != nullptr)
            {
                current = temp;
            }
            else
            {
                color(4);
                cout << "The system cannot find the path specified.\n";
                color(7);
            }
        }
        void saveTree()
        {
            ofstream write("tree.txt");
            list<Folder*> saveList;
            Folder* temp;
            saveList.push_back(root);
            list<Folder*>::iterator saveIt;
            for (saveIt = saveList.begin(); saveIt != saveList.end(); saveIt++)
            {
                temp = *saveIt;
                write << temp -> name << " ";
                list<Folder*>::iterator it;
                for (it = temp -> subFolders.begin(); it != temp -> subFolders.end(); it++)
                {
                    saveList.push_back(*it);
                    write << (*it) -> name << ",";
                }
                write << "\n";
            }


        }
        void loadTree()
        {
            // ifstream read("tree.txt");
            // while (read)
            // {
            //     if (read >> h1)
            // }
        }
};
#endif