#include <stdexcept>
#include"FileName.cpp"

int main() {
	dynamicQueue<char> q1(3);
	q1.push('a');
	q1.push('b');
	q1.push('c');
	q1.push('d');
	cout << q1.frontValue() << endl;
	cout << q1.lastValue() << endl;
	q1.push('d');
	q1.push('e');
	q1.push('f');
	q1.push('g');
	cout << q1.frontValue() << endl;
	cout << q1.lastValue() << endl;
	return 0;
}