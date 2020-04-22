// problem : evaluate the expression in one pass 
// solution : using 2 stacks one for operator and one for operands
// then using same getprecedence for getting precedence and using it to selectively 
// pop out of the operator stack

#include<iostream>
#include<stack>
using namespace std;

int getprecedence(char c)
{
    if(c == '+' || c == '-')return 1;
    else if(c == '*' || c == '/')return 2;
    else return -1;
}

int calculate(int a,int b,char op)
{
    if(op == '+')return a+b;
    else if(op == '-')return a-b;
    else if(op == '*')return a*b;
    else return a/b;
}

int evaluate_infix(string str)
{
    stack<int>oper;
    stack<char>operand;

    for(int i = 0;i<str.size();i++)
    {
        if(str[i] =='+' || str[i] == '-' || str[i] =='*' || str[i] == '/')
        {
            int precedence = getprecedence(str[i]);
            while(!oper.empty() && getprecedence(oper.top())>precedence)
            {
                char op = oper.top();
                oper.pop();
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                operand.push(calculate(first,second,op));
            }
            oper.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(oper.top()!= '(')
            {
                char op = oper.top();
                oper.pop();
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                operand.push(calculate(first,second,op));
            }
            oper.pop();
        }
        else if(str[i] == '(')oper.push(str[i]);
        else operand.push(str[i]-'0');
    }
    while(!oper.empty())
    {
        char op = oper.top();
        oper.pop();
        int second = operand.top();
        operand.pop();
        int first = operand.top();
        operand.pop();
        operand.push(calculate(first,second,op));
    }
    return operand.top();


}

int main()
{
    string input = "5+6*7+8";
    int answer  = evaluate_infix(input);
    cout<<answer<<endl;
    return 0;
}