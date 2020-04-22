// problem - discuss how stack can be used for checking of symbols
// solution - read through the input and when any opening bracket is found then that
// bracket is pushed to the stack and when any closing bracket is found then it is 
// compared with the top most element of the stack and if they match then it is continued
// and if not then error is thrown.

#include<iostream>
#include<stack>
using namespace std;

bool balance(string input)
{
    stack<char> st;
    for(int i = 0;i<input.size();i++)
    {
        if(input[i] == '(' || input[i] == '[' ||input[i] == '{')st.push(input[i]);
        else if(input[i] == '}' ||input[i] == ']' || input[i] == ')')
        {
            if(input [i] == '}' && !st.empty() && st.top() == '{')st.pop();
            else if(input [i] == ']' && !st.empty() && st.top() == '[')st.pop();
            else if(input [i] == ')' && !st.empty() && st.top() == '(')st.pop();
            else return false;
        }
    }
    if(st.empty())return true;
    else return false;
}

int main()
{
    string input = "(({888{[45515]}})))";
    // function that takes string as input and output boolean as output
    bool ans = balance(input);
    cout<<ans<<endl;
    return 0;
}

// This algorithm is o(N) complexity 

