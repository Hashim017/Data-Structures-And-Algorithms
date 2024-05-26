#include <iostream>
#include <vector>
using namespace std;

// TASK 1

int sumTillN(int number){ // part-1
    if(number==0){
        return 0;
    }
    return number + sumTillN(number-1);
}

int oddSumTillN(int number){ // part-2
    if(number==1){
        return 1;
    }
    return number + oddSumTillN(number-2);
}

int sumOfPowersOfTwo(int number) { // part-3
  if (number == 0) {
    return 0;
  } else if (number == 1) {
    return 1;
  } else {
    return 2 * sumOfPowersOfTwo(number - 1) + 1;
  }
}

int sumOfPowersOfThree(int number) { // part-4
  if (number == 0 || number==1) {
    return number;
  } 
  else {
    return 3 * sumOfPowersOfThree(number - 1) + 1;
  }
}

int sumTillOneByThree(int number){ // part-5
    if (number == 0 || number==1) {
    return number;
  } 
  else{
    return number + sumTillOneByThree(number/3);
  }
}

int sumTillOneByTwo(int number){ // part-6
    if (number == 0 || number==1) {
    return number;
  } 
  else{
    return number + sumTillOneByTwo(number/2);
  }
}

// TASK 2

void decimalToBinary(int number){ // part-1
    if(number==0){
        return;
    }
    decimalToBinary(number/2);
    cout<<number%2;
}

string integerToString(int value) // part-2
{
    if(value==0)
    {
        return "";
    }
    return integerToString(value/10)+to_string(value%10);
}

int gcd(int firstNumber, int secondNumber) { // part-3
  if (secondNumber == 0) {
    return firstNumber;
  } 
  else {
    return gcd(secondNumber, firstNumber % secondNumber);
  }
}

// TASK 3

int SearchFirstEntry(int numbersArray[], int size, int target) { // part-1
  if (size == 0) {
    return -1;
  } else if (numbersArray[0] == target) {
    return 0;
  } else {
    return SearchFirstEntry(numbersArray+1, size + 1, target);
  }
}

int SearchLastEntry(int numbersArray[], int size, int target) { // part-2
  if (size == 0) {
    return -1;
  } else if (numbersArray[size - 1] == target) {
    return size - 1;
  } else {
    return SearchLastEntry(numbersArray, size - 1, target);
  }
}

int BinarySearch(int numbersArray[], int size, int target) { // part-3
  if (size == 0) 
  {
    return -1;
  } else 
  {
    int mid = size / 2;

    if (numbersArray[mid] == target) 
    {
      return mid;
    } 
    else if (numbersArray[mid] < target)
    {
      return BinarySearch(list + mid + 1, size - mid - 1, target);
    } 
    else 
    {
      return BinarySearch(list, mid, target);
    }
  }
}

// TASK 4

int powerofY(int a, int b, int c) { // part-1
  if (b == 0) {
    return 1;
  }
  
  return (a*powerofY(a,b-1,c))%c;
}

int powerofY(int a, int b, int c) { // part-2
  if (b == 0) {
    return 1;
  }
  
  return (a*powerofY((a*a)%c,b/2,c))%c;
}

// TASK 5

int multylog(int x, int y) // part-1
{
    if (y == 0 || x == 0)
    {
        return 0;
    }
    else if (y % 2 == 0)
    {
        return mult(x, y / 2) + mult(x,y/2);
    }
    else
    {
        return x + (mult(x, y-1));
    }
}

// TASK 7

int fibonacciRecursion(int nthNumber) { 
    if (nthNumber == 0) {
        return 0;
    } 
    else if (nthNumber == 1) {
        return 1;
    }   
    return fibonacciRecursion(nthNumber - 1) + fibonacciRecursion(nthNumber - 2);
}

// part-1
// Simple recursion is the most inefficient way for Fibonacci calculation since it would have a time complexity of O(2^n)(terrible). To reduce the repeated steps of recursion there is always the option of iterations available.

 int fibonacciLoop(int nthNumber) { // part-2
 
    int previouspreviousNumber, previousNumber = 0, currentNumber = 1;
    for (int i = 1; i < nthNumber ; i++) {
        previouspreviousNumber = previousNumber;
        previousNumber = currentNumber;
        currentNumber = previouspreviousNumber + previousNumber;

    }
    return currentNumber;
}

// TASK 8

int tri_sum_generator(int n) { // part-1
  if (n < 3) {
    return 1;
  } else {
    return tri_sum_generator(n - 1) + tri_sum_generator(n - 2) + tri_sum_generator(n - 3);
  }
}

int tri_sum_generator2(int n) { // part-2
  int a = 1;
  int b = 1;
  int c = 2;

  for (int i = 3; i <= n; i++) {
    int sum = a + b + c;
    a = b;
    b = c;
    c = sum;
  }

  return c;
}

// CHALLENGE 1

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

// CHALLENGE 2

struct stack {
	int data;
	struct stack* next;
};

void initStack(struct stack** s) { *s = NULL; }

int isEmpty(struct stack* s)
{
	if (s == NULL)
		return 1;
	return 0;
}

void push(struct stack** s, int x)
{
	struct stack* p = (struct stack*)malloc(sizeof(*p));

	if (p == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		return;
	}

	p->data = x;
	p->next = *s;
	*s = p;
}

int pop(struct stack** s)
{
	int x;
	struct stack* temp;

	x = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;
	free(temp);

	return x;
}

int top(struct stack* s) { return (s->data); }

void sortedInsert(struct stack** s, int x)
{
	if (isEmpty(*s) or x > top(*s)) {
		push(s, x);
		return;
	}

	int temp = pop(s);
	sortedInsert(s, x);

	push(s, temp);
}

void sortStack(struct stack** s)
{
	if (!isEmpty(*s)) {
		int x = pop(s);
		sortStack(s);
		sortedInsert(s, x);
	}
}

void printStack(struct stack* s)
{
	while (s) {
		cout << s->data << " ";
		s = s->next;
	}
	cout << "\n";
}

int main(){
    return 0;
}