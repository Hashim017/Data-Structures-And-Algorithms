#include <iostream>
using namespace std;

class stack{
    int* st;
    int top;
    public:
        
        stack(){
            st = new int[100];
            top=-1;
        }
        void push(int n){
            if(top == 99){
                cout << "Stack overflow";
                return;
            }
            top++;
            st[top] = n;
        }
        void pop(){
            if(top == -1){
                cout << "stack is empty";
                return;
            }
            top--;
        }
        int Top(){
            if(top == -1){
                cout << "stack is empty";
                return -1;
            }
            return st[top];
        }
        bool empty(){
            return top == -1;
        }
    
};

int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.Top() << endl;

    return 0;
}