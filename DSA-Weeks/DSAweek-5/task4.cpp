#include <iostream>
using namespace std;

int powerofY(int a, int b, int c) {
  if (b == 0) {
    return 1;
  }
  
  return (a*powerofY(a,b-1,c))%c;
}

int powerofY(int a, int b, int c) {
  if (b == 0) {
    return 1;
  }
  
  return (a*powerofY((a*a)%c,b/2,c))%c;
}


int main(){
    cout<<power(3,5,2);
    return 0;
}