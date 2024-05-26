#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int evaluatePostfix(string s){
    stack<int> st;
    for(int x = 0; x < s.length(); x++){
        if(s[x]>='0'&&s[x]<='9'){
            st.push(s[x]-'0');
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch(s[x]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
            }
        }
    }
    return st.top();
}

int evaluatePrefix(string s){
    stack<int> st;
    for(int x = s.length()-1; x >= 0; x--){
        if(s[x]>='0'&&s[x]<='9'){
            st.push(s[x]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch(s[x]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
            }
        }
    }
    return st.top();
}

int precedence(char c) {
  switch (c) {
    case '^':
      return 4;
    case '*':
    case '/':
      return 3;
    case '+':
    case '-':
      return 2;
    default:
      return 1;
  }
} 

string infixToPostfix(string s){
    stack<char> st;
    string result;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
            result+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(st.top())>precedence(s[i])){
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}

string infixToPrefix(string s){
    string result;
    reverse(s.begin(), s.end());

    for (char& c : s) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    result = infixToPostfix(s);

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    cout  << endl << endl;
    string infix_value = "2*3+4";
    cout << "Infix value: " << infix_value << endl;
    cout << "Postfix value: " << infixToPostfix(infix_value) << endl;
    cout << "Prefix value: " << infixToPrefix(infix_value) << endl << endl;

    string prefix_value = "+*234";
    cout << "Prefix value: " << prefix_value << endl;
    cout << "Result: " << evaluatePrefix(prefix_value) << endl << endl;
    
    string postfix_value = "23*4+";
    cout << "Postfix value: " << postfix_value << endl;
    cout << "Result: " << evaluatePostfix(postfix_value) << endl << endl;

    return 0;
}