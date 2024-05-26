#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

struct Coordinates
{
	int row = 0;
	int col = 0;
};
class Excel
{
	class Cell
	{
		friend class Excel;
		string data;
		Cell *up;
		Cell *down;
		Cell *left;
		Cell *right;

	public:
		Cell(string input = " ", Cell *l = nullptr, Cell *r = nullptr, Cell *u = nullptr, Cell *d = nullptr)
		{
			data = input;
			left = l;
			right = r;
			up = u;
			down = d;
		}
	};

    Cell *head;
    Cell *current;
    int row_size, col_size;
    int c_row, c_col;
    int Cell_width = 10;
    int Cell_height = 4;
    Cell *RangeStart;
    vector<vector<string>> Clipboard;
    Coordinates Range_start{};
    Coordinates Range_end{};

    void color(int k)
    {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, k);
            if (k > 255)
            {
                k = 1;
            }
    }

    void gotoRowCol(int rpos, int cpos)
    {
            COORD scrn;
            HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
            scrn.X = cpos;
            scrn.Y = rpos;
            SetConsoleCursorPosition(hOuput, scrn);
    }

public:
	class iterator
	{
		Cell *t;
		friend class Excel;
		iterator() { t = nullptr; }
		iterator(Cell *data) { t = data; }
		iterator operator++()
		{
			if (t->right != nullptr)
				t = t->right;
			return *this;
		}
		iterator operator++(int)
		{
			if (t->down != nullptr)
				t = t->down;
			return *this;
		}
		iterator operator--()
		{
			if (t->left != nullptr)
				t = t->left;
			return *this;
		}
		iterator operator--(int)
		{
			if (t->right != nullptr)
				t = t->right;
			return *this;
		}
		bool operator==(iterator temp)
		{
			return (t == temp.t);
		}
		bool operator!=(iterator temp)
		{
			return (t != temp.t);
		}
		string &operator*()
		{
			return t->data;
		}
	};

	iterator Get_Head()
	{
		return iterator(head);
	}

	Excel()
	{
		head = nullptr;
		current = nullptr;
		row_size = col_size = 5;
		c_row = c_col = 0;
		head = New_row();
		current = head;
		for (int i = 0; i < row_size - 1; i++)
		{
			InsertRowBelow();
			row_size--;
			current = current->down;
		}
		current = head;
		PrintGrid();
		PrintGridData();
		display();
		system("pause");
		displayClear();
	}

	Cell *New_row()
	{
		Cell *temp = new Cell();
		Cell *curr = temp;
		for (int i = 0; i < col_size - 1; i++)
		{
			Cell *temp2 = new Cell();
			temp->right = temp2;
			temp2->left = temp;
			temp = temp2;
		}
		return curr;
	}

	Cell *New_col()
	{
		Cell *temp = new Cell();
		Cell *curr = temp;
		for (int i = 0; i < row_size - 1; i++)
		{
			Cell *temp2 = new Cell();
			temp->down = temp2;
			temp2->up = temp;
			temp = temp2;
		}
		return curr;
	}

	void InsertRowAbove()
	{
		Cell *temp = New_row();
		Cell *temp2 = current;
		while (temp2->left != nullptr)
		{
			temp2 = temp2->left;
		}
		if (temp2 == head)
		{
			head = temp;
		}
		if (temp2->up == nullptr)
		{
			while (temp2 != nullptr)
			{
				temp2->up = temp;
				temp->down = temp2;
				temp = temp->right;
				temp2 = temp2->right;
			}
		}
		else
		{
			while (temp2 != nullptr)
			{
				temp->up = temp2->up;
				temp2->up = temp;
				temp->down = temp2;
				temp->up->down = temp;
				temp = temp->right;
				temp2 = temp2->right;
			}
		}
		row_size++;
		PrintGrid();
		PrintGridData();
	}

    void InsertRowBelow()
	{
		Cell *temp = New_row();
		Cell *temp2 = current;
		while (temp2->left != nullptr)
		{
			temp2 = temp2->left;
		}
		if (temp2->down == nullptr)
		{
			while (temp2 != nullptr)
			{
				temp2->down = temp;
				temp->up = temp2;
				temp = temp->right;
				temp2 = temp2->right;
			}
		}
		else
		{
			while (temp2 != nullptr)
			{
				temp->down = temp2->down;
				temp2->down = temp;
				temp->up = temp2;
				temp->down->up = temp;
				temp = temp->right;
				temp2 = temp2->right;
			}
		}
		row_size++;
	}

    void InsertColumnToRight()
	{
		Cell *temp = New_col();
		Cell *temp2 = current;
		while (temp2->up != nullptr)
		{
			temp2 = temp2->up;
		}
		if (temp2->right == nullptr)
		{
			while (temp2 != nullptr)
			{
				temp2->right = temp;
				temp->left = temp2;
				temp2 = temp2->down;
				temp = temp->down;
			}
		}
		else
		{
			while (temp2 != nullptr)
			{
				temp->right = temp2->right;
				temp2->right = temp;
				temp->left = temp2;
				temp->right->left = temp;
				temp2 = temp2->down;
				temp = temp->down;
			}
		}
		col_size++;
	}

	void InsertColumnToLeft()
	{
		Cell *temp = New_col();
		Cell *temp2 = current;
		while (temp2->up != nullptr)
		{
			temp2 = temp2->up;
		}
		if (temp2 == head)
		{
			head = temp;
		}
		if (temp2->left == nullptr)
		{
			while (temp2 != nullptr)
			{
				temp2->left = temp;
				temp->right = temp2;
				temp2 = temp2->down;
				temp = temp->down;
			}
		}
		else
		{
			while (temp2 != nullptr)
			{
				temp->left = temp2->left;
				temp2->left = temp;
				temp->right = temp2;
				temp->left->right = temp;
				temp2 = temp2->down;
				temp = temp->down;
			}
		}
		col_size++;
		PrintGrid();
		PrintGridData();
	}

	void ShiftAndDelete()
	{
		char c = _getch();
		
		if (c == 70) // right cell shift(d)
		{
			InsertCellByRightShift();
			PrintGrid();
			PrintGridData();
		}
		else if (c == 97) // Delete shift left(a)
		{
			DeleteCellByLeftShift();
			PrintGrid();
			PrintGridData();
		}
		else if (c == 119) // Delete shift up(w)
		{
			DeleteCellByUpShift();
			PrintGrid();
			PrintGridData();
		}
		else if (c == 115) // down cell shift(s)
		{
			InsertCellByDownShift();
			PrintGrid();
			PrintGridData();
		}
		else if (c == 114) // delete (r)
		{
			DeleteRow();
			system("cls");
			PrintGrid();
			PrintGridData();
		}
		else if (c == 99) // delete (c)
		{
			DeleteColumn();
			system("cls");
			PrintGrid();
			PrintGridData();
		}
	}

	void InsertCellByRightShift()
	{
		Cell *temp = current;
		while (current->right != nullptr)
		{
			current = current->right;
		}
		InsertColumnToRight();
		current = current->right;
		while (current != temp)
		{
			current->data = current->left->data;
			current = current->left;
		}
		current->data = " ";
	}

	void InsertCellByLeftShift()
	{
		Cell *temp = current;
		while (current->left != nullptr)
		{
			current = current->left;
		}
		InsertColumnToLeft();
		current = current->left;
		while (current != temp)
		{
			current->data = current->right->data;
			current = current->right;
		}
		current->data = " ";
		c_col++;
	}

	void InsertCellByDownShift()
	{
		Cell *temp = current;
		while (current->down != nullptr)
		{
			current = current->down;
		}
		InsertRowBelow();
		current = current->down;
		while (current != temp)
		{
			current->data = current->up->data;
			current = current->up;
		}
		current->data = " ";
	}

	void InsertCellByUpShift()
	{
		Cell *temp = current;
		while (current->up != nullptr)
		{
			current = current->up;
		}
		InsertRowAbove();
		current = current->up;
		while (current != temp)
		{
			current->data = current->down->data;
			current = current->down;
		}
		current->data = " ";
		c_row++;
	}

	void DeleteCellByLeftShift()
	{
		Cell *temp = current;
		temp->data = "    ";
		while (temp->right != nullptr)
		{
			temp->data = temp->right->data;
			temp = temp->right;
		}
		temp->data = "    ";
	}

	void DeleteCellByUpShift()
	{
		Cell *temp = current;
		temp->data = " ";
		while (temp->down != nullptr)
		{
			temp->data = temp->down->data;
			temp = temp->down;
		}
		temp->data = " ";
	}

	void DeleteColumn()
	{
		if (col_size <= 1)
			return;
		Cell *temp = current;
		while (temp->up != nullptr)
		{
			temp = temp->up;
		}
		Cell *delete_cell;

		if (temp == head)
		{
			head = temp->right;
		}
		if (temp->left == nullptr)
		{
			current = current->right;
			while (temp != nullptr)
			{
				delete_cell = temp;
				temp->right->left = nullptr;
				temp = temp->down;
				delete delete_cell;
			}
		}
		else if (temp->right == nullptr)
		{
			c_col--;
			current = current->left;
			while (temp != nullptr)
			{
				delete_cell = temp;
				temp->left->right = nullptr;
				temp = temp->down;
				delete delete_cell;
			}
		}
		else
		{
			c_col--;
			current = current->left;
			while (temp != nullptr)
			{
				delete_cell = temp;
				temp->left->right = temp->right;
				temp->right->left = temp->left;
				temp = temp->down;
				delete delete_cell;
			}
		}
		col_size--;
	}

	void DeleteRow()
	{
		if (row_size <= 1)
			return;
		Cell *temp = current;
		while (temp->left != nullptr)
		{
			temp = temp->left;
		}
		Cell *delete_cell;
		if (temp == head)
		{
			head = temp->down;
		}
		if (temp->up == nullptr)
		{
			current = current->down;
			while (temp != nullptr)
			{
				delete_cell = temp;
				temp->down->up = nullptr;

				temp = temp->right;
				delete delete_cell;
			}
		}
		else if (temp->down == nullptr)
		{
			c_row--;
			current = current->up;
			while (temp != nullptr)
			{
				delete_cell = temp;
				temp->up->down = nullptr;
				temp = temp->right;
				delete delete_cell;
			}
		}
		else
		{
			c_row--;
			current = current->up;
			while (temp != nullptr)
			{
				delete_cell = temp;
				temp->down->up = temp->up;
				temp->up->down = temp->down;

				temp = temp->right;
				delete delete_cell;
			}
		}
		row_size--;
	}

	void ClearCol()
	{
		Cell *temp = current;
		while (temp->up != nullptr)
		{
			temp = temp->up;
		}
		while (temp != nullptr)
		{
			temp->data = "    ";
			temp = temp->down;
		}
	}

	void ClearRow()
	{
		Cell *temp = current;
		while (temp->left != nullptr)
		{
			temp = temp->left;
		}
		while (temp != nullptr)
		{
			temp->data = "    ";
			temp = temp->right;
		}
	}

    void PrintGrid()
	{
		for (int ri = 0; ri < row_size; ri++)
		{
			for (int ci = 0; ci < col_size; ci++)
			{
				PrintCellBorder(ri, ci, 6);
			}
		}
	}

	void PrintCellBorder(int row, int col, int colour)
    {
    		int wallCode = 510;
    		int wallCode2 = 771;
            color(colour);
            char c = wallCode;
            gotoRowCol(row * Cell_height, col * Cell_width);
            for (int i = 0; i < Cell_width; i++)
            {
                cout << c;
            }
            gotoRowCol(row * Cell_height + Cell_height, col * Cell_width);
            for (int i = 0; i < Cell_width; i++)
            {
                cout << c;
            }
			color(2);
			c = wallCode2;
            for (int i = 0; i < Cell_height; i++)
            {
                gotoRowCol(row * Cell_height + i, col * Cell_width);
                cout << c;
            }
            int r = row * Cell_height;
            int ci = (col * Cell_width) + Cell_width;
            for (int i = 0; i <= Cell_height; i++)
            {
                gotoRowCol(r + i, ci);
                cout << c;
            }
            gotoRowCol((Cell_height * row) + Cell_height / 2, (col * Cell_width) + Cell_width / 2);
            cout << "     ";
    }

    void PrintCellData(int row, int col, Cell *cellData, int colour)
    {
            color(colour);
            gotoRowCol((Cell_height * row) + Cell_height / 2, (col * Cell_width) + Cell_width / 2);
            cout << cellData->data;
    }

    void PrintColumn()
    {
        for (int ri = 0, ci = c_col + 1; ri < row_size; ri++)
        {
            PrintCellBorder(ri, ci, 6);
        }
    }

    void PrintRow()
    {
        for (int ci = 0, ri = c_row + 1; ci < col_size; ci++)
        {
            PrintCellBorder(ri, ci, 6);
        }
    }

	void PrintGridData()
	{
		Cell *temp = head;
		for (int ri = 0; ri < row_size; ri++)
		{
			Cell *temp2 = temp;
			for (int ci = 0; ci < col_size; ci++)
			{
				PrintCellData(ri, ci, temp, 3);
				temp = temp->right;
			}

			temp = temp2->down;
		}
	}

	void movement()
	{
		int max_col = 0, max_row = 0, min_col = INT_MAX, min_row = INT_MAX;
		while (true)
		{
			char c = _getch();
			if (c == 100) // right(d)
			{
				if (current->right != nullptr)
				{
					current = current->right;
					c_col++;
					// PrintCellBorder(c_row, c_col, 4);
				}
			}
			else if (c == 97) // left(a)
			{
				if (current->left != nullptr)
				{
					current = current->left;
					c_col--;
				}
			}
			else if (c == 115) // down(s)
			{
				if (current->down != nullptr)
				{
					current = current->down;
					c_row++;
				}
			}
			else if (c == 119) // up(w)
			{
				if (current->up != nullptr)
				{
					current = current->up;
					c_row--;
				}
			}
			else if (c == 99) // calculate(c)
				break;
			if (c_col > max_col)
				max_col = c_col;
			if (c_row > max_row)
				max_row = c_row;
			if (c_col < min_col)
				min_col = c_col;
			if (c_row < min_row)
				min_row = c_row;
			PrintCellBorder(c_row, c_col, 4);
			PrintCellData(c_row, c_col, current, 3);
		}
		Range_end.col = max_col;
		Range_end.row = max_row;
		Range_start.col = min_col;
		Range_start.row = min_row;
	}

	bool check_string_digit(Cell *temp)
	{
		for (int i = 0; i < temp->data.length(); i++)
		{
			if (!isdigit(temp->data[i]))
				return false;
		}
		return true;
	}

	void Copy()
	{
		Cell *temp = RangeStart;
		Clipboard.clear();
		int sri = c_row;
		int sci = c_col;
		movement();

		int row_limit = Range_end.row - Range_start.row;
		int col_limit = Range_end.col - Range_start.col;

		if (Range_start.col <= sri && Range_start.row < sci)
		{
			for (int i = 0; i <= Range_start.col; i++)
			{
				temp = temp->left;
			}
		}

		for (int ri = 0; ri <= row_limit; ri++)
		{
			vector<string> clip;
			Cell *temp2 = temp;
			for (int ci = 0; ci <= col_limit; ci++)
			{
				clip.push_back(temp->data);
				temp = temp->right;
			}

			Clipboard.push_back(clip);
			temp = temp2->down;
		}

		c_row = sri;
		c_col = sci;
	}

	void Cut()
	{
		Cell *temp = RangeStart;
		Clipboard.clear();
		int sri = c_row;
		int sci = c_col;
		movement();

		int row_limit = Range_end.row - Range_start.row;
		int col_limit = Range_end.col - Range_start.col;

		if (Range_start.col <= sri && Range_start.row < sci)
		{
			for (int i = 0; i <= Range_start.col; i++)
			{
				temp = temp->left;
			}
		}

		for (int ri = 0; ri <= row_limit; ri++)
		{
			vector<string> clip;
			Cell *temp2 = temp;
			for (int ci = 0; ci <= col_limit; ci++)
			{
				clip.push_back(temp->data);
				temp->data = " ";
				temp = temp->right;
			}

			Clipboard.push_back(clip);
			temp = temp2->down;
		}

		c_row = sri;
		c_col = sci;
	}

	void Paste()
	{
		Cell *temp = current;
		for (int ri = 0; ri < Clipboard.size(); ri++)
		{
			Cell *temp2 = current;
			for (int ci = 0; ci < Clipboard[0].size(); ci++)
			{
				current->data = Clipboard[ri][ci];
				if (current->right == nullptr)
					InsertColumnToRight();
				current = current->right;
			}

			if (temp2->down == nullptr)
				InsertRowBelow();
			current = temp2->down;
		}

		current = temp;
	}

	void CutCopyPaste()
	{
		string s;
		char c = _getch();
		RangeStart = current;
		if (c == 99) // Copy(C)
		{
			Copy();
		}
		else if (c == 112) // Paste(P)
		{
			Paste();
		}
		else if (c == 120) // Cut(x)
		{
			Cut();
		}
		current = RangeStart;
		PrintGrid();
		PrintGridData();
	}

	int CalculateSum()
	{
		Cell *temp = RangeStart;
		int sum = 0;
		int sri = c_row;
		int sci = c_col;
		movement();

		int row_limit = Range_end.row - Range_start.row;
		int col_limit = Range_end.col - Range_start.col;

		if (Range_start.col <= sri && Range_start.row < sci)
		{
			for (int i = 0; i <= Range_start.col; i++)
			{
				temp = temp->left;
			}
		}

		for (int ri = 0; ri <= row_limit; ri++)
		{
			Cell *temp2 = temp;
			for (int ci = 0; ci <= col_limit; ci++)
			{
				if (check_string_digit(temp))
				{
					sum = sum + std::stoi(temp->data);
				}
				temp = temp->right;
			}

			temp = temp2->down;
		}

		c_row = sri;
		c_col = sci;
		return sum;
	}

	int CalculateAverage()
	{
		Cell *temp = RangeStart;
		int average = 0;
		int sri = c_row;
		int sci = c_col;
		movement();

		int row_limit = Range_end.row - Range_start.row;
		int col_limit = Range_end.col - Range_start.col;

		if (Range_start.col <= sri && Range_start.row < sci)
		{
			for (int i = 0; i <= Range_start.col; i++)
			{
				temp = temp->left;
			}
		}

		for (int ri = 0; ri <= row_limit; ri++)
		{
			Cell *temp2 = temp;
			for (int ci = 0; ci <= col_limit; ci++)
			{
				if (check_string_digit(temp))
				{
					average = average + std::stoi(temp->data);
				}
				temp = temp->right;
			}

			temp = temp2->down;
		}

		c_row = sri;
		c_col = sci;
		return (average / 2);
	}

	int CalculateCount()
	{
		Cell *temp = RangeStart;
		int count = 0;
		int sri = c_row;
		int sci = c_col;
		movement();

		int row_limit = Range_end.row - Range_start.row;
		int col_limit = Range_end.col - Range_start.col;

		if (Range_start.col <= sri && Range_start.row < sci)
		{
			for (int i = 0; i <= Range_start.col; i++)
			{
				temp = temp->left;
			}
		}

		for (int ri = 0; ri <= row_limit; ri++)
		{
			Cell *temp2 = temp;
			for (int ci = 0; ci <= col_limit; ci++)
			{
				if (temp->data != " ")
					count++;
				temp = temp->right;
			}

			temp = temp2->down;
		}

		c_row = sri;
		c_col = sci;
		return count;
	}

	int CalculateMax()
	{
		Cell *temp = RangeStart;
		int Max = INT_MIN;
		int sri = c_row;
		int sci = c_col;
		movement();

		int row_limit = Range_end.row - Range_start.row;
		int col_limit = Range_end.col - Range_start.col;

		if (Range_start.col <= sri && Range_start.row < sci)
		{
			for (int i = 0; i <= Range_start.col; i++)
			{
				temp = temp->left;
			}
		}

		for (int ri = 0; ri <= row_limit; ri++)
		{
			Cell *temp2 = temp;
			for (int ci = 0; ci <= col_limit; ci++)
			{
				if (check_string_digit(temp))
				{

					if (Max < std::stoi(temp->data))
					{
						Max = std::stoi(temp->data);
					}
				}
				temp = temp->right;
			}

			temp = temp2->down;
		}

		c_row = sri;
		c_col = sci;
		return Max;
	}

	int CalculateMin()
	{
		Cell *temp = RangeStart;
		int Min = INT_MAX;
		int sri = c_row;
		int sci = c_col;
		movement();

		int row_limit = Range_end.row - Range_start.row;
		int col_limit = Range_end.col - Range_start.col;

		if (Range_start.col <= sri && Range_start.row < sci)
		{
			for (int i = 0; i <= Range_start.col; i++)
			{
				temp = temp->left;
			}
		}

		for (int ri = 0; ri <= row_limit; ri++)
		{
			Cell *temp2 = temp;
			for (int ci = 0; ci <= col_limit; ci++)
			{
				if (check_string_digit(temp))
				{

					if (Min > std::stoi(temp->data))
					{
						Min = std::stoi(temp->data);
					}
				}
				temp = temp->right;
			}

			temp = temp2->down;
		}

		c_row = sri;
		c_col = sci;
		return Min;
	}

	void Mathematic_operations()
	{
		string s;
		char c = _getch();
		RangeStart = current;
		if (c == 115) // Sum(S)
		{
			s = std::to_string(CalculateSum());
			gotoRowCol(Cell_height * row_size + 5, 0);
			color(1);
			cout << "Sum = ";
			color(3);
			cout << s << endl << endl;
		}
		else if (c == 97) // Average(A)
		{
			s = std::to_string(CalculateAverage());
			color(1);
			gotoRowCol(Cell_height * row_size + 5, 0);
			cout << "Average = ";
			color(3);
			cout << s << endl << endl;
		}
		else if (c == 99) // Count(c)
		{
			s = std::to_string(CalculateCount());
			color(1);
			gotoRowCol(Cell_height * row_size + 5, 0);
			cout << "Count = ";
			color(3);
			cout << s << endl << endl;
		}
		else if (c == 109) // Max(m)
		{
			s = std::to_string(CalculateMax());
			color(1);
			gotoRowCol(Cell_height * row_size + 5, 0);
			cout << "Max = ";
			color(3);
			cout << s << endl << endl;
		}
		else if (c == 110) // Min(n)
		{
			s = std::to_string(CalculateMin());
			color(1);
			gotoRowCol(Cell_height * row_size + 5, 0);
			cout << "Min = ";
			color(3);
			cout << s << endl << endl;
		}
		color(5);
		system("pause");
		gotoRowCol(Cell_height * row_size + 5, 0);
		cout << "                                                          ";
		gotoRowCol(Cell_height * row_size + 7, 0);
		cout << "                                                          ";
		current = RangeStart;
		current->data = s;
		PrintGrid();
		PrintGridData();
	}

    void keyboardInput()
	{
		PrintCellBorder(c_row, c_col, 4);
		Cell *temp = current;
		string input;
		while (true)
		{
            color(2);
			char key = _getch();
			if (key == 100) // right(d)
			{
				if (current->right == nullptr)
				{
					char input;
					gotoRowCol(10,90);
					cout<<"Do You Want To Insert Another Column (y/n): ";
					cin>>input;
					if(input=='n'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
					else if(input == 'y'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						InsertColumnToRight();
						PrintColumn();
					}
					else{
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
				}
				PrintCellBorder(c_row, c_col, 6); // Unhighlight
				PrintCellData(c_row, c_col, current, 3);
				current = current->right;
				c_col++;
			}
			else if (key == 97) // left(a)
			{
				if (current->left == nullptr)
				{
					char input;
					gotoRowCol(10,90);
					cout<<"Do You Want To Insert Another Column (y/n): ";
					cin>>input;
					if(input=='n'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
					else if(input == 'y'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						InsertColumnToLeft();
						PrintColumn();
						c_col++;
					}
					else{
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
				}
				PrintCellBorder(c_row, c_col, 6); // Unhighlight
				PrintCellData(c_row, c_col, current, 3);
				current = current->left;
				c_col--;

			}
			else if (key == 115) // down(s)
			{
				if (current->down == nullptr)
				{
					char input;
					gotoRowCol(10,90);
					cout<<"Do You Want To Insert Another Row (y/n): ";
					cin>>input;
					if(input=='n'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
					else if(input == 'y'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						InsertRowBelow();
						PrintRow();
					}
					else{
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
				}
				PrintCellBorder(c_row, c_col, 6); // Unhighlight
				PrintCellData(c_row, c_col, current, 3);
				current = current->down;
				c_row++;

			}
			else if (key == 119) // up(w)
			{
				if (current->up == nullptr)
				{
					char input;
					gotoRowCol(10,90);
					cout<<"Do You Want To Insert Another Row (y/n): ";
					cin>>input;
					if(input=='n'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
					else if(input == 'y'){
						gotoRowCol(10,90);
						cout<<"                                               ";
						InsertRowAbove();
						PrintRow();
						c_row++;
					}
					else{
						gotoRowCol(10,90);
						cout<<"                                               ";
						continue;
					}
				}
				PrintCellBorder(c_row, c_col, 6); // Unhighlight
				PrintCellData(c_row, c_col, current, 3);
				current = current->up;
				c_row--;
			}
			else if (key == 105) // insertion(i)
			{
				do
				{
					gotoRowCol(Cell_height * row_size + 5, 0);
					PrintCellData(c_row, c_col, current, 3);
					gotoRowCol(Cell_height * row_size + 5, 0);
                    color(1);
					cout << "Enter the value: ";
                    color(3);
					cin >> input;

					if (input.length() > 4)
					{
						gotoRowCol(Cell_height * row_size + 5 + 1, 0);
                        color(4);
						cout << "Invalid input, Please Try Again ... !";
						gotoRowCol(Cell_height * row_size + 5, 0);
						cout << "                                                                    ";
					}
					else
					{
						gotoRowCol(Cell_height * row_size + 5 + 1, 0);
						cout << "                                                                     ";
						gotoRowCol(Cell_height * row_size + 5, 0);
						cout << "                                                                    ";
						break;
					}

				} while (true);
				current->data = input;
				PrintCellData(c_row, c_col, current, 3);
			}

			else if (key == 99) // Clear row and col(c)
			{
				key = _getch();
				if (key == 99)
				{
					ClearCol();
					PrintGridData(); // Clear column(c)
				}
				else if (key == 114)
				{
					ClearRow(); // Clear row(r)
					PrintGridData();
				}
			}

			else if (key == 111) // Open Menu(o)
			{
				ShiftAndDelete();
			}

			else if (key == 109) // Mathematic operations(m)
			{
				Mathematic_operations();
			}

			else if (key == 49) // Save(1)
			{
				saveFile();
			}
            
			else if (key == 50) // Load(2)
			{ 
				loadFile();
			}

			else if (key == 120) // Cut and Copy(x)
			{
				CutCopyPaste();
			}

			else if (key == 48) // Menu(0)
			{
				menu();
			}

			gotoRowCol(c_row, c_col);
			PrintCellBorder(c_row, c_col, 4); // Highlight new cell
			PrintCellData(c_row, c_col, current, 3);
		}
	}

    void saveFile()
	{
		Cell *temp = head;
		ofstream fout("Save.txt");
		fout << row_size << endl;
		fout << col_size << endl;
		for (int i = 0; i < row_size; i++)
		{
			Cell *temp2 = temp;
			for (int j = 0; j < col_size; j++)
			{
				if (temp->data == " ")
				{
					fout << "Space" << " ";
				}
				else
				{
					fout << temp->data << " ";
				}

				temp = temp->right;
			}
			fout << endl;
			temp = temp2->down;
		}
	}

	void loadFile()
	{
		system("cls");
		ifstream fin("Save.txt");
		fin >> row_size;
		fin >> col_size;

		head = nullptr;
		current = nullptr;
		c_row = c_col = 0;

		head = New_row();
		current = head;
		for (int i = 0; i < row_size - 1; i++)
		{
			InsertRowBelow();
			row_size--;
			current = current->down;
		}

		string data;
		current = head;
		Cell *temp = current;
		for (int ri = 0; ri < row_size; ri++)
		{
			Cell *temp2 = temp;
			for (int ci = 0; ci < col_size; ci++)
			{
				fin >> data;
				if (data == "Space")
					temp->data = " ";
				else
					temp->data = data;

				temp = temp->right;
			}

			temp = temp2->down;
		}

		PrintGrid();
		PrintGridData();
	}

	void menu()
	{

		color(1);
		int x = 20; // Spacing for column
		gotoRowCol(0, col_size * x);
		cout << "Shortcut Keys: ";
		color(2);
		gotoRowCol(3, col_size * x);
		cout << "Insert : i";
		color(3);
		gotoRowCol(4, col_size * x);
		cout << "Shift Cell Right O -> D";
		color(4);
		gotoRowCol(5, col_size * x);
		cout << "Shift Cell Left O -> A";
		color(5);
		gotoRowCol(6, col_size * x);
		cout << "Shift Cell Up O -> U";
		color(6);
		gotoRowCol(7, col_size * x);
		cout << "Shift Cell Down O -> S";
		color(7);
		gotoRowCol(8, col_size * x);
		cout << "Delete Row O -> R";
		color(8);
		gotoRowCol(9, col_size * x);
		cout << "Delete Col O -> C";
		color(9);
		gotoRowCol(10, col_size * x);
		cout << "Copy X -> C and C to select";
		color(10);
		gotoRowCol(11, col_size * x);
		cout << "Cut X -> X and C";
		color(11);
		gotoRowCol(12, col_size * x);
		cout << "Paste X -> P and C";
		color(12);
		gotoRowCol(13, col_size * x);
		cout << "Clear Row C -> C";
		color(13);
		gotoRowCol(14, col_size * x);
		cout << "Clear Col C -> R";
		color(14);
		gotoRowCol(15, col_size * x);
		cout << "Save File 1";
		color(15);
		gotoRowCol(16, col_size * x);
		cout << "Load File 2";
		color(0);
		gotoRowCol(17, col_size * x);
		cout << "Sum Range M -> S and C to select";
		color(1);
		gotoRowCol(18, col_size * x);
		cout << "Average Range M -> A and C";
		color(3);
		gotoRowCol(19, col_size * x);
		cout << "Count Range M -> C and C";
		color(5);
		gotoRowCol(20, col_size * x);
		cout << "Max in Range M -> M and C";
		color(7);
		gotoRowCol(21, col_size * x);
		cout << "Min in Range M -> n and C";
		color(9);

		/*color(0);*/
		gotoRowCol(22, col_size * x);
		system("pause");
		gotoRowCol(0, col_size * x);
		cout << "                                        ";
		gotoRowCol(3, col_size * x);
		cout << "                                        ";
		gotoRowCol(4, col_size * x);
		cout << "                                        ";
		gotoRowCol(5, col_size * x);
		cout << "                                        ";
		gotoRowCol(6, col_size * x);
		cout << "                                        ";
		gotoRowCol(7, col_size * x);
		cout << "                                        ";
		gotoRowCol(8, col_size * x);
		cout << "                                        ";
		gotoRowCol(9, col_size * x);
		cout << "                                        ";
		gotoRowCol(10, col_size * x);
		cout << "                                        ";
		gotoRowCol(11, col_size * x);
		cout << "                                        ";
		gotoRowCol(12, col_size * x);
		cout << "                                        ";
		gotoRowCol(13, col_size * x);
		cout << "                                        ";
		gotoRowCol(14, col_size * x);
		cout << "                                        ";
		gotoRowCol(15, col_size * x);
		cout << "                                        ";
		gotoRowCol(16, col_size * x);
		cout << "                                        ";
		gotoRowCol(17, col_size * x);
		cout << "                                        ";
		gotoRowCol(18, col_size * x);
		cout << "                                        ";
		gotoRowCol(19, col_size * x);
		cout << "                                        ";
		gotoRowCol(20, col_size * x);
		cout << "                                        ";
		gotoRowCol(21, col_size * x);
		cout << "                                        ";
		gotoRowCol(25, col_size * x);
		cout << "                                        ";
	}

	void display()
	{
		color(5);
		gotoRowCol(10,70);
		cout<<"-----------------------------------------------------------------------------------" <<endl;
		gotoRowCol(11,70);
		cout<<"___________________________________________________________________________________" <<endl;
		gotoRowCol(12,70);
		color(1);
		cout << "||                  ___                                         __               ||"<<endl;     
		gotoRowCol(13,70);
		cout << "||                 /\\_ \\                                       /\\ \\__            ||"<<endl;     
		gotoRowCol(14,70);
		cout << "||  __  __  __    _\\/\\ \\     ___    ___    ___ ___      __     \\\\ ,_\\   ___      ||"<<endl;     
		gotoRowCol(15,70);
		cout << "||  /\\ \\/\\ \\/\\ \\ /'__`\\ \\ \\   /'___\\ / __`\\/' __` __`\\  /'__`\\   \\ \\ \\/  / __`\\  ||"<<endl;      
		gotoRowCol(16,70);
		cout << "||  \\ \\ \\_/ \\_/ /\\  __/\\_\\ \\_/\\ \\__ /\\ \\L\\ /\\ \\/\\ \\/\\ \\/\\  __/    \\ \\ \\_/\\ \\L\\ \\ ||"<<endl;      
		gotoRowCol(17,70);
		cout << "||   \\ \\___x___/\\ \\____/\\____\\ \\____\\ \\____\\ \\_\\ \\_\\ \\_\\ \\____\\    \\ \\__\\ \\____/ ||"<<endl;      
		gotoRowCol(18,70);
		cout << "||    \\/__ /__/  \\/____\\/___________/\\/___/ \\/_/\\/_/\\/_/\\/____/     \\/__/\\/___/  ||"<<endl;      
		gotoRowCol(19,70);
		cout << "||                          /\\_ \\                                                ||"<<endl;      
		gotoRowCol(20,70);
		cout << "||     __  __  _   ___     _\\ /\\ \\                                               ||"<<endl;      
		gotoRowCol(21,70);
		cout << "||   /'__`/\\ \\/'\\ /'___\\ /'__`\\ \\ \\                                              ||"<<endl;      
		gotoRowCol(22,70);
		cout << "||  /\\  __\\/>  < /\\ \\__ /\\  __/\\_\\ \\_                                            ||"<<endl;      
		gotoRowCol(23,70);
		cout << "||  \\ \\____/\\_/\\_\\ \\____\\ \\____/\\____\\                                           ||"<<endl;      
		gotoRowCol(24,70);
		cout << "||  \\/____\\ /\\/_/\\/____/\\/____\\/____/                                            ||"<<endl;
		gotoRowCol(25,70);
		cout<<"||                                                                               ||" <<endl;
		color(5);
		gotoRowCol(26,70);
		cout<<"-----------------------------------------------------------------------------------" <<endl;
		gotoRowCol(27,70);
		cout<<"___________________________________________________________________________________" <<endl;
		color(1);
	}

	void displayClear()
	{
		gotoRowCol(10,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(11,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(12,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(13,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(14,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(15,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(16,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(17,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(18,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(19,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(20,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(21,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(22,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(23,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(24,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(25,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(26,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(27,70);
		cout<<"                                                                                    " <<endl;
		gotoRowCol(28,0);
		cout<<"                                                                                    " <<endl;
	}
};

int main()
{
	system("cls");
	Excel mini;
	mini.keyboardInput();
}