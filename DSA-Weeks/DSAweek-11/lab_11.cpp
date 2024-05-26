#include <iostream>
#include <queue>
#include <fstream>
#include <ctime>
using namespace std;
class compare
{
    public:
        bool operator()(int &a, int &b)
        {
            return a >=b;
        }
};
void heapSort(vector<int>& vec)
{
    priority_queue<int, vector<int>, compare> q;
    for (int i = 0; i < vec.size(); i++)
    {
        q.push(vec[i]);
    }
    vec.clear();
    while (!q.empty())
    {
        vec.push_back(q.top());
        q.pop();
    }
}
void randomizedInit(vector<int>& vec)
{
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        vec[i] = rand() % 100;
    }
}
void vectorPrint(vector<int>& vec)
{
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void bubbleSort(vector<int>& arr,const int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(vector<int> arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i; j < n; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= low && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
void createRandomFile(string fileName, int size)
{
    ofstream writer(fileName);
    for (int i = 0; i < size * 1024 * 1024; i++)
    {
        writer << rand() % 100 << " ";
    }
}
void readFile(string fileName, vector<int>& vec)
{
    ifstream reader(fileName);
    while (reader)
    {
        int temp = 0; 
        reader >> temp;
        vec.push_back(temp);
    }
}

int main()
{
    // priority_queue<int, vector<int>, compare> q;
    // q.push(30);
    // q.push(20);
    // q.push(50);
    // while (!q.empty())
    // {
    //     cout << q.top() << " ";
    //     q.pop();
    // }
    // vector<int> vec(20);
    // randomizedInit(vec);
    // vectorPrint(vec);
    // heapSort(vec);
    // vectorPrint(vec);

    vector<int> vec;
    createRandomFile("integers", 10);
    cout << "File Generated Successfully" << endl;
    readFile("integers", vec);
    cout << "File Read Successfully" << endl;
    cout << vec.size() << endl;
    cout << "Before time: " << time(0) << endl;
    quickSort(vec, 0, vec.size() - 1);
    cout << "After Quick Sort time: " << time(0) << endl;
    // heapSort(vec);
    // cout << "After Heap Sort time: " << time(0) << endl;
    // bubbleSort(vec, vec.size());
    // cout << "After bubble Sort time: " << time(0) << endl;
    // selectionSort(vec, vec.size());
    // cout << "After Selection Sort time: " << time(0) << endl;


}


