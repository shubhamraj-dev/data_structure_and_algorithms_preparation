// problem: implement stack using 2 queues
#include<iostream>
#include<queue>
using namespace std;

class stack_using_queue
{
    queue<int>q1;
    queue<int>q2;

    public:
    void stack_push(int value)
    {
        if(q1.empty())q2.push(value);
        else q1.push(value);
    }

    int stack_pop()
    {
        int i,size,data;
        if(q1.empty() && q2.empty())return -1;
        if(!q1.empty())
        {
            size = q1.size();
            i = 0;
            while(i<size-1)
            {
                q2.push(q1.front());
                q1.pop();
                i++;
            }
            data = q1.front();
            q1.pop();
        }
        else
        {
            size = q2.size();
            i = 0;
            while(i<size-1)
            {
                q1.push(q2.front());
                q2.pop();
                i++;
            }
            data = q2.front();
            q2.pop();
        }
        return data;
        
    }
};

int main()
{
    stack_using_queue s;
    s.stack_push(10);
    s.stack_push(20);
    s.stack_push(11);
    s.stack_push(25);
    cout<<s.stack_pop()<<endl;
    cout<<s.stack_pop()<<endl;
    cout<<s.stack_pop()<<endl;
    return 0;
}