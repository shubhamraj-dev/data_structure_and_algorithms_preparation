#include<iostream>
#include<stack>
using namespace std;

int calculate(int a,int b,char c)
{
    if(c == '+')return a+b;
    else if(c == '-')return a-b;
    else if(c == '*')return a*b;
    else return a/b;
}

int postfix_evaluate(string str)
{
    stack<int>st;
    for(int i = 0;i<str.size();i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            st.push(calculate(first,second,str[i]));
        }
        else st.push(str[i]-'0');
    }
    return st.top();
}

int main()
{
    string input = "123*+5-";
    int output = postfix_evaluate(input);
    cout<<output<<endl;

    return 0;
}