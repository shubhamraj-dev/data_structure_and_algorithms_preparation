//problem: sort stack using only push pop top and empty function calls
// solution: using 2 stacks this problem is solved
//using insertion or selection sort like algorithm in stack

#include<iostream>
#include<stack>
using namespace std;

stack<int> sort_stack(stack<int>s)
{
    stack<int>t;
    while(!s.empty())
    {
        t.push(s.top());
        s.pop();

    }
    int min;
    while(!t.empty())
    {
        min = t.top();
        t.pop();
        while(!s.empty() && s.top()> min)
        {
            t.push(s.top());
            s.pop();
        }
        s.push(min);

    }
    return s;
}

int main()
{
    int array[] = {3,8,11,6,4};
    stack<int> s;
    s.push(3);
    s.push(8); s.push(11); s.push(6); s.push(4);
    s = sort_stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}