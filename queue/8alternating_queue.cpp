// problem: the problem is to create an alternating queue from original queue
// input[11,12....,20] output[11,16,12,17,13,18,14,19,15,20]
// using another queue to achieve the task

#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int a[] = {11,12,13,14,15,16,17,18,19,20};
    queue<int>q;
    for(auto x:a)q.push(x);
    queue<int>aux;
    int n = sizeof(a)/sizeof(int);
    for(int i = 0;i<n/2;i++)
    {
        aux.push(q.front());
        q.pop();
    }
    for(int i = 0;i<n/2;i++)
    {
        q.push(aux.front());
        q.push(q.front());
        aux.pop();
        q.pop();
    }
    // implement this using iterator of queue;
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}