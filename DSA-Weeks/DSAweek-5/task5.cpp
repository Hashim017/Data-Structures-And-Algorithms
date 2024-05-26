#include <iostream>
#include <math.h>
using namespace std;

int MULT(int X, int Y) {
  if (Y == 0) {
    return 0;
  } else if (Y % 2 == 0) {
    return MULT(2 * X, Y / 2);
  } 
  
}

int MULT(int X, int Y, int M) {
  if (Y == 0) {
    return 0;
  } else if (Y % 2 == 0) {
    return MULT(X * X % M, Y / 2, M);
  } else {
    return (X * MULT(X * X % M, Y / 2, M)) % M;
  }
}

int MULT(int X, int Y, int M, int* cache) {
  if (Y == 0) {
    return 0;
  } else if (Y % 2 == 0) {
    if (cache[Y] == -1) {
      cache[Y] = MULT(X * X % M, Y / 2, M, cache);
    }
    return cache[Y];
  } else {
    if (cache[Y] == -1) {
      cache[Y] = (X * MULT(X * X % M, Y / 2, M, cache)) % M;
    }
    return cache[Y];
  }
}
int main(){
    // int X = 2;
    // int Y = 5;

    // int result = MULT(X, Y);

    // cout << "The result is: " << result << endl;


    int X = 2;
    int Y = 5;
    int M = 10;

    int result = MULT(X, Y, M);

    cout << "The result is: " << result << endl;


    
    return 0;
}