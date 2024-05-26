#pragma once
#include <iostream>
#include <vector>
using namespace std;
	template<typename T>

	class staticArray {
	private:
		int size;
		int capacity;
		vector<T> arr;
	public:
		staticArray(int cap) {
			capacity = cap;
			arr = new vector<T>[capacity];
		};
		void addElement(T value) {
			arr.push_back(value);
		}

	};

int main() {
	staticArray arr;
	arr = new staticArray(90);
	return 0;
}