// find maximum element in window of length w 
#include<iostream>
#include<queue>
using namespace std;

void find_sliding_answer(int a[],int n,int w,int ans[])
{
    // cout<<"hello"<<endl;
    queue<int>q;
    int current,start;
    int temp;
    for(int i = 0;i<n;i++)
    {
        if(q.empty())q.push(i);
        else
        {
            while(!q.empty() && (a[q.front()] < a[i] || q.front() <= i-w))q.pop();
            q.push(i);
        }
        if(i>=w-1)ans[i-w+1] = a[q.front()];
    }
}

int main()
{
    // cout<<"hello"<<endl;
    int array[] = {1,3,-1,-3,5,3,6,7};
    int w = 3;
    int N = 8;
    // cout<<"hello"<<endl;
    
    int answer[N-w+1];
    // cout<<"hello";
    find_sliding_answer(array,N,w,answer);
    // cout<<"ehel"<<endl;
    for(auto a: answer)cout<<a<<endl;
    return 0;
}