#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>

class dynamicQueue {
private:
	int size, capacity, ri, fi, pre_ri;
	T* SQ;
public:
	dynamicQueue(int cap) {
		size = 0;
		capacity = cap;
		SQ = new T[capacity];
		fi = ri = pre_ri = 0;
	}
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == capacity;
	}
	void push(T val) {
		if (isFull()) {
			T* HA = new T[capacity * 2];
			for (int i = 0, c=fi; i < size; i++, c++) {
				if (c = capacity) {
					c = 0;
				}
				HA[i] = SQ[c];
			}
			delete[] SQ;
			SQ = HA;
			capacity = capacity * 2;
			fi = 0;
			ri = size;

			//throw exception("Queue is full");
		}
		SQ[ri] = val;
		pre_ri = ri;
		ri = (ri + 1) % capacity;
		size++;
	}
	void pop() {
		if (isEmpty()) {
			throw exception("Queue is already empty");
		}
		fi = (fi + 1) % capacity;
		size--;
	}
	T frontValue() {
		return SQ[fi];
	}
	T lastValue() {
		return SQ[pre_ri];
	}
};
