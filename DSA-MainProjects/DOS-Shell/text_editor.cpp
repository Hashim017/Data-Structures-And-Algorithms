#include <stack>
#include <deque>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <list>
#include <algorithm>
using namespace std;

void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void Hide_Cursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void color1(int color1)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
}

void Choice(int current)
{
	string menu[3] = {
		"New File",
		"Previous File",
		"Exit"};
	color1(6);
	gotoxy(72, 9);
	cout << "|| Main Menu ||" << endl;
	color1(7);
	for (int i = 0; i < 3; i++)
	{
		if (current == i)
		{
			color1(9);
		}
		gotoxy(71, 12 + i);
		cout << "--> " << menu[i];
		color1(7);
	}
}
list<string> fileNames;

struct state
{
	list<list<char>> txt;
	list<list<char>>::iterator ri;
	list<char>::iterator ci;
	int r, c;
};
class CFile
{
public:
	int curR, curC;
	list<list<char>> txt;
	list<list<char>>::iterator ri;
	list<char>::iterator ci;
	deque<state> undo;
	stack<state> redo;

	CFile()
	{
		txt.push_back(list<char>());
		ri = txt.begin();
		(*ri).push_back(' ');
		ci = (*ri).begin();
		curR = 0;
		curC = 0;
	}
	void Create()
	{
		system("cls");
		string fn;
		cout << "File name: ";
		cin >> fn;
		system("cls");
		Edit(fn);
		system("cls");
		system("color 09");
	}
	void Edit(string fn)
	{
		system("Color F0");
		char c;
		c = _getch();
		gotoxy(curR, curC);
		cout << c;
		(*ci) = c;
		curC++;

		while (true)
		{
			if (curR == 0)
				gotoxy(curR, curC);
			else
				gotoxy(curR, curC + 1);
			c = _getch();

			if (c == -32)
			{
			A:
				c = _getch();
				if (c == 72) // up
				{
					if (curR == 0)
						continue;
					ri--;
					ci = (*ri).begin();
					curR--;
					curC = 0;
				}
				else if (c == 80) // down
				{
					ri++;
					ci = (*ri).begin();
					curR++;
					curC = 0;
				}
				else if (c == 75) // l
				{
					if (curC - 1 > 0)
					{
						ci--;
						curC--;
					}
				}
				else if (c == 77) // r
				{
					if (curC == 159)
						continue;
					ci++;
					curC++;
				}
				else if (c == 71) // home
				{
					txt.insert(ri, list<char>());
					ci = (*ri).begin();
					curR = 0;
					curC = 0;

					system("cls");
					print();
					UpdateUndo();
					continue;
				}
				else if (c == 83) // del
				{
					auto t = ci;
					ci++;
					(*ri).erase(ci);
					ci = t;
					system("cls");
					print();
					UpdateUndo();
				}
				if (curC == 0)
				{
					gotoxy(curR, 0);
					c = _getch();
					if (c == -32)
						goto A;
					(*ri).push_front(c);
					ci = (*ri).begin();
					curC = 1;
					system("cls");
					print();
					UpdateUndo();
				}
				continue;
			}
			else if (c == 13) // enter
			{
				auto t = ri;
				ri++;
				txt.insert(ri, list<char>());
				ri = ++t;
				curR++;
				curC = 0;
				gotoxy(curR, curC);
				c = _getch();
				if (c == -32)
					goto A;
				(*ri).push_back(c);
				ci = (*ri).begin();
				system("cls");
				print();
				UpdateUndo();
				continue;
			}
			else if (c == 8) // bckspc
			{
				if (curC == 0)
				{
					gotoxy(curR, 0);
					c = _getch();
					if (c == -32)
						goto A;
					if (c == 8)
						continue;
					(*ci) = c;
					ci = (*ri).begin();
					curC = 1;
					continue;
				}
				auto t = --ci;
				ci++;
				(*ri).erase(ci);
				ci = t;
				curC--;
				system("cls");
				print();
				UpdateUndo();
				continue;
			}
			else if (c == 26) // undo
			{
				if (!undo.empty())
				{
					state st = undo.back();
					LoadState(st);

					redo.push(undo.back());
					undo.pop_back();
					system("cls");
					print();
				}
				continue;
			}
			else if (c == 25) // redo
			{
				if (!redo.empty())
				{
					undo.push_back(redo.top());
					state st = redo.top();
					redo.pop();
					LoadState(st);
					system("cls");
					print();
				}
				continue;
			}
			else if (c == 27) // close editor "esc"
			{
				Write(fn);
				break;
			}
			if (curC == 100)
			{
				txt.push_back(list<char>());
				ri++;
				curC = 0;
				curR++;
				(*ri).push_back(c);
				ci = (*ri).begin();
			}
			auto t = ci;
			ci++;
			(*ri).insert(ci, c);
			ci = ++t;
			curC++;

			system("cls");
			print();
			UpdateUndo();
		}
		system("color 07");
	}
	void print()
	{
		for (auto i = txt.begin(); i != txt.end(); i++)
		{
			for (auto j = (*i).begin(); j != (*i).end(); j++)
				cout << *j;
			cout << endl;
		}
	}
	void UpdateUndo()
	{
		if (undo.size() > 5)
			undo.erase(undo.begin());
		state st = SaveState();
		undo.push_back(st);
	}
	void Write(string filename)
	{
		ofstream wrt(filename);
		for (auto i = txt.begin(); i != txt.end(); i++)
			for (auto j = (*i).begin(); j != (*i).end(); j++)
				wrt << *j;
		wrt << endl;
	}
	state SaveState()
	{
		state *st = new state;
		st->txt.push_back(list<char>());
		auto ri = st->txt.begin();
		for (auto row = txt.begin(); row != txt.end(); row++, ri++)
		{
			st->txt.push_back(list<char>());
			for (auto col = (*row).begin(); col != (*row).end(); col++)
			{
				char chr = *col;
				(*ri).push_back(chr);
			}
		}
		st->ri = st->txt.begin();
		st->ci = (*st->ri).begin();
		st->c = curC;
		st->r = curR;

		return *st;
	}
	void LoadState(state st)
	{
		txt = st.txt;
		ri = txt.begin();
		curR = st.r;
		curC = st.c;

		for (int i = 0; i < st.r; i++)
			ri++;
		ci = (*ri).begin();
		for (int i = 0; i < st.c; i++)
			ci++;
	}

	
	void OpenSaved(string name)
	{
		char ch;
		ifstream rdr(name);
		   if (!rdr.is_open()) {
        cout << "File does not exist or cannot be opened." << std::endl;
        return;
    }
		while (!rdr.eof())
		{
			rdr.get(ch);
			if (ch != '\n')
				(*ri).push_back(ch);
			else
			{
				txt.push_back(list<char>());
				ri++;
			}
		}

		if (txt.back().empty())
			txt.pop_back();
		else
			txt.push_back(list<char>());

		ri = txt.begin();
		ci = (*ri).begin();
		curR = 0;
		curC = 0;
		gotoxy(curR, curC);
		rdr.close();
	}

	void Open()
	{
		system("cls");
		string fn;
		cout << "File name? ";
		cin >> fn;
		OpenSaved(fn);
		system("cls");
		print();
		gotoxy(curR, curC);
		Edit(fn);
		system("cls");
		system("color 09");
	}
};

int main()
{
	int value = 0;
	system("cls");
	while (true)
	{
		Hide_Cursor();
		Choice(value);
		if (GetAsyncKeyState(VK_UP) & 0x8001)
		{
			if (value == 0)
			{
				value = 2;
			}
			else
			{
				value--;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		{
			if (value == 2)
			{
				value = 0;
			}
			else
			{
				value++;
			}
			Sleep(300);
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8001)
		{
				CFile f;
			if (value == 0 && GetAsyncKeyState(VK_RETURN))
			{
				system("cls");
				f.Create();
			}
			  if (value == 1 && GetAsyncKeyState(VK_RETURN)& 0x8001)
			  {
			    system("cls");
			    f.Open();
			  }
		
			if (value == 2 && GetAsyncKeyState(VK_RETURN) & 0x8001)
			{
				break;
				
			}
		}
	}
}