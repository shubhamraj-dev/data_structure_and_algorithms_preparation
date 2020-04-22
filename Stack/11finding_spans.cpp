// problem: finding spans for every element,span is number of consecutive elements
// which are smaller than the element
// solution: using stacks and storing the index of the array in stack this problem is solved
#include<iostream>
#include<stack>
using namespace std;

int * find_span(int array[],int n)
{
    static int span[5];
    stack<int> st;
    int p = -1;
    for(int i = 0;i<n;i++)
    {
        while(!st.empty() && array[i]>array[st.top()])st.pop();
        if(st.empty())p = -1;
        else p = st.top();
        span[i] = i-p;
        st.push(i);
    }
    return span;
}
int main()
{
    int array[] = {6,3,4,5,2};
    int * ans = find_span(array,5);
    for(int i =0;i<5;i++)cout<<ans[i]<<endl;
    return 0;
}