#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cmath>
#include "Dos.cpp"
#include "currentFile.cpp"
#include "Folder.cpp"

using namespace std;


void SetConsoleCursor(bool visible)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = visible;

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
int main()
{
    Dos d;
    SetConsoleCursor(0);
    SetConsoleCursor(1);
    PrintVersion();
    while (d.takeInput())
    {
        cout << endl;
        // to take the input until true
    }
}
