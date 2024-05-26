// Fibonacci Series using Space Optimized Method
#include <iostream>
using namespace std;

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


// Driver code
int main()
{
	int n = 9;

	cout << fib(n);
	return 0;
}

// This code is contributed by Code_Mech
