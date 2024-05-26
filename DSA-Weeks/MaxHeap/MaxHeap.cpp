#include <iostream>
#include <vector>
using namespace std;
int Left(int i)
{
    return 2 * i + 1;
}
int Right(int i)
{
    return 2 * i + 2;
}
void maxHeapify(vector<int>& vec, int i, int size)
{
    int l = Left(i);
    int r = Right(i);
    int largest;
    if (l < size && vec[l] > vec[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r < size && vec[r] > vec[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = vec[i];
        vec[i] = vec[largest];
        vec[largest] = temp;
        maxHeapify(vec, largest, size);
    }
}
void buildMaxHeap(vector<int>& vec,int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        maxHeapify(vec, i, size);
    }
}
void heapSort(vector<int>& vec)
{
    int size = vec.size();
    buildMaxHeap(vec, size);
    for (int i = size - 1; i >= 1; i--)
    {
        int temp = vec[0];
        vec[0] = vec[i];
        vec[i] = temp;
        size--;
        maxHeapify(vec, 0, size);
    }
}

int main()
{
    vector<int> vec;
    vec.push_back(45);
    vec.push_back(5);
    vec.push_back(35);
    vec.push_back(2);
    vec.push_back(15);
    vec.push_back(65);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(9);
    heapSort(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;

}