#include <iostream>
using namespace std;

int sumTillN(int number){
    if(number==0){
        return 0;
    }
    return number + sumTillN(number-1);
}

int oddSumTillN(int number){
    if(number==1){
        return 1;
    }
    return number + oddSumTillN(number-2);
}

int sumOfPowersOfTwo(int number) {
  if (number == 0) {
    return 0;
  } else if (number == 1) {
    return 1;
  } else {
    return 2 * sumOfPowersOfTwo(number - 1) + 1;
  }
}

int sumOfPowersOfThree(int number) {
  if (number == 0 || number==1) {
    return number;
  } 
  else {
    return 3 * sumOfPowersOfThree(number - 1) + 1;
  }
}

int sumTillOneByThree(int number){
    if (number == 0 || number==1) {
    return number;
  } 
  else{
    return number + sumTillOneByThree(number/3);
  }
}

int sumTillOneByTwo(int number){
    if (number == 0 || number==1) {
    return number;
  } 
  else{
    return number + sumTillOneByTwo(number/2);
  }
}

int main(){
    cout << sumTillN(5)<<endl;
    cout << oddSumTillN(5)<<endl;
    cout << sumOfPowersOfTwo(4)<<endl;
    cout << sumOfPowersOfThree(4)<<endl;
    cout << sumTillOneByThree(9)<<endl;
    cout << sumTillOneByTwo(4)<<endl;
    return 0;
}