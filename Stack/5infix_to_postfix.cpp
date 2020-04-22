// problem : infix to postfix conversion
//solution: using an stack to solve with precedence.
#include<iostream>
#include<stack>
using namespace std;

int getprecedence(char c)
{
    if(c == '+' || c == '-')return 1;
    else if(c == '*' || c == '/')return 2;
    else return 3;
}

void infix_to_postfix(string str)
{
    stack<char> st;
    for(int i = 0;i<str.size();i++)
    {
        // cout<<str[i]<<" ";
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(')
        {
            int precedence = getprecedence(str[i]);
            // cout<<precedence;
            while(!st.empty() && st.top() != '(' && getprecedence(st.top())>precedence)
            {
                cout<<st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        // else if(str[i] == '(')st.push(str[i]);
        else cout<<str[i];
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    cout<<"entered main"<<endl;
    string input = "A*B-(C+D)+E";
    cout<<input<<endl;
    infix_to_postfix(input);
    return 0;
}