#include <iostream>
#include <stack>
using namespace std;

int precedence(char value);
string expression(string infix);

int main()
{
    cout << "1st : " << expression("(2*3)+4/6") << endl;
    cout << "2nd : " << expression("5*(6+2)/4") << endl;
    return 0;
}

int precedence(char value)
{
    if (value == '*' || value == '/' || value == '%')
        return 2;
    else if (value == '+' || value == '-')
        return 1;
    return 0;
}

string expression(string infix)
{
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
