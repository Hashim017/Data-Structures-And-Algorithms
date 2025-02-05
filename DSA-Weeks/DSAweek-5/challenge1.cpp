#include <iostream>
#include <vector>
using namespace std;


void printSubArrays(vector<int> arr, int start, int end)
{
	if (end == arr.size())
    cout << "[]";
	else if (start > end)
		printSubArrays(arr, 0, end + 1);
	else {
		cout << "[";
		for (int i = start; i < end; i++)
			cout << arr[i] << ", ";
		cout << arr[end] << "]" << endl;
		printSubArrays(arr, start + 1, end);
	}
	return;
}

int main()
{
	vector<int> arr = { 1, 2, 3 };
	printSubArrays(arr, 0, 0);
	return 0;
}
