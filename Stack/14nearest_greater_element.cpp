#include<iostream>
#include<stack>
using namespace std;

void find_next_greater(int a[],int res[],int n)
{
    stack<int>s;
    for(int i = 0;i<n;i++)
    {
        while(!s.empty() && a[s.top()] < a[i])
        {
            res[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        res[s.top()] = a[s.top()];
        s.pop();
    }
    
}

int main()
{
    int array[] = {10,4,5,11,34,34,34,11,45};
    int len = sizeof(array)/sizeof(int);
    int next_greater_element[len];
    find_next_greater(array,next_greater_element,len);
    for(int i = 0;i<len;i++)
    {
        cout<<next_greater_element[i]<<" ";
    }
    return 0;
}