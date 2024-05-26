#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool findOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix;
    stack<char> st;
    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i]))
        {
            postfix.push_back(infix[i]);
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!st.empty() && st.top() != '(' && precedence(infix[i]) <= precedence(st.top()))
            {
                char temp = st.top();
                postfix.push_back(temp);
                st.pop();
            }
            st.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                postfix.push_back(temp);
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        char temp = st.top();
        if (temp == '(' || temp == ')')
        {
            continue;
        }
        postfix.push_back(temp);
        st.pop();
    }
    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(),infix.end());
    string prefix;
    stack<char> st;
    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i]))
        {
            prefix.push_back(infix[i]);
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!st.empty() && st.top() != '(' && precedence(infix[i]) < precedence(st.top()))
            {
                char temp = st.top();
                prefix.push_back(temp);
                st.pop();
            }
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                char temp = st.top();
                prefix.push_back(temp);
                st.pop();
            }
            if (!st.empty() && st.top() == ')')
            {
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        char temp = st.top();
        if (temp == '(' || temp == ')')
        {
            continue;
        }
        prefix.push_back(temp);
        st.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int evaluatePrefix(string prefix) {
    stack<int> operands;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isdigit(c)) {
            operands.push(c - '0');
        } 
        else if (findOperator(c)) {
            int operand1 = operands.top();
            operands.pop();
            int operand2 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operands.top();
}

int evaluatePostfix(string postfix) {
    stack<int> operands;

    for (char c : postfix) {
        if (isdigit(c)) {
            operands.push(c - '0');  
        } 
        else if (findOperator(c)) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operands.top();
}

int main() {
    cout<<endl;
    string infix_value1 = "(2*3)+5";
    cout << "Infix value 1: " << infix_value1 << endl;
    cout << "Postfix value: " << infixToPostfix(infix_value1) << endl;
    string postfix_value1 = "23*5+";
    cout << "Result: " << evaluatePostfix(postfix_value1) << endl;
    cout << "Prefix value: " << infixToPrefix(infix_value1) << endl;
    string prefix_value1 = "+*235";
    cout << "Result: " << evaluatePrefix(prefix_value1) << endl << endl;

    string infix_value2 = "5*(6+2)/4";
    cout << "Infix value 2: " << infix_value2 << endl;
    cout << "Postfix value: " << infixToPostfix(infix_value2) << endl;
    string postfix_value2 = "562+*8/";
    cout << "Result: " << evaluatePostfix(postfix_value2) << endl;
    cout << "Prefix value: " << infixToPrefix(infix_value2) << endl;
    string prefix_value2 = "/*5+624";
    cout << "Result: " << evaluatePrefix(prefix_value2) << endl;
    

    return 0;
}