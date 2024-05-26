#include <iostream>
using namespace std;

void decimalToBinary(int number){
    if(number==0){
        return;
    }
    decimalToBinary(number/2);
    cout<<number%2;
}

string integerToString(int value)
{
    if(value==0)
    {
        return "";
    }
    return integerToString(value/10)+to_string(value%10);
}

int gcd(int firstNumber, int secondNumber) {
  if (secondNumber == 0) {
    return firstNumber;
  } 
  else {
    return gcd(secondNumber, firstNumber % secondNumber);
  }
}

int main(){
    decimalToBinary(5);
    cout << endl;
    cout << integerToString(987)<< endl;
    cout<<gcd(16,0)<< endl;
    return 0;
}