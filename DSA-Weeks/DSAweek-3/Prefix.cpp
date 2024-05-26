#include <iostream>
#include<algorithm>
// #include <cctype>
#include <stack>
using namespace std;

int precedence(char value);
string expression(string infix);

int main()
{
    cout << "1st : " << expression("(2*3)+4/6") << endl;
    cout << "2nd : " << expression("5*(6+2)/8") << endl;
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
        else if (infix[i] == ')')//changes done here from this ( to this )
        {
            st.push(infix[i]);
        }
        else if (infix[i] == '(')//changes done here from this ( to this )
        {
            while (!st.empty() && st.top() != ')')//changes done here from this ( to this )
            {
                char temp = st.top();
                prefix.push_back(temp);
                st.pop();
            }
            if (!st.empty() && st.top() == ')')//changes done here from this ( to this )
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
