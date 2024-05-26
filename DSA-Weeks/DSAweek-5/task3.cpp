#include <iostream>
#include <random>
using namespace std;

int SearchFirstEntry(int list[], int size, int target) {
  if (size == 0) {
    return -1;
  } else if (list[0] == target) {
    return 0;
  } else {
    return SearchFirstEntry(list+1, size + 1, target);
  }
}

int SearchLastEntry(int list[], int size, int target) {
  if (size == 0) {
    return -1;
  } else if (list[size - 1] == target) {
    return size - 1;
  } else {
    return SearchLastEntry(list, size - 1, target);
  }
}

int BinarySearch(int list[], int size, int target) {
  if (size == 0) 
  {
    return -1;
  } else 
  {
    int mid = size / 2;

    if (list[mid] == target) 
    {
      return mid;
    } 
    else if (list[mid] < target)
    {
      return BinarySearch(list + mid + 1, size - mid - 1, target);
    } 
    else 
    {
      return BinarySearch(list, mid, target);
    }
  }
}

int main() {
  int list[] = {1, 2, 3, 4, 5};
  int size = sizeof(list) / sizeof(list[0]);

  int x = 4;

  int firstEntry = SearchFirstEntry(list, size, x);
  int lastEntry = SearchLastEntry(list, size, x);

  if (firstEntry != -1) {
    cout << "The first entry of " << x << " is at index " << firstEntry << endl;
  } else {
    cout << "The element " << x << " is not in the list" << endl;
  }

  if (lastEntry != -1) {
    cout << "The last entry of " << x << " is at index " << lastEntry << endl;
  } else {
    cout << "The element " << x << " is not in the list" << endl;
  }
  
  return 0;
}
