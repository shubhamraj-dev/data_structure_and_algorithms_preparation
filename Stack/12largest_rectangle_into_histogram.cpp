// problem: the problem is to calculate the largest rectangle in terms of area under the 
// histogram
// solution: using stack just like problem in 11.

#include<iostream>
#include<stack>
using namespace std;

int find_largest_rectangle(int a[],int n)
{
    int highest = 0;
    //implement the function
    stack<int>st;
    for(int i = 0;i<=n;i++)
    {
        // if(st.empty())st.push(i);
        while(!st.empty() && ( i==n || a[i] < a[st.top()]))
        {
            int height = a[st.top()];
            st.pop();
            if(st.empty())
            {
                highest = max(highest,height*(i));
            }
            else
            {
                highest = max(highest,height*(i-st.top()-1));
            }
        }
        if(!st.empty() && a[st.top()] == a[i])continue;
        st.push(i);
    }
    return highest;
}

int main()
{
    int rect_height[] = {3,2,5,6,1,4,4,4};
    int answer = find_largest_rectangle(rect_height,8);
    cout<<answer<<endl;
    return 0;
}