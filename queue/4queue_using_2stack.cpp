//problem: implement queue using 2 stacks
#include<iostream>
#include<stack>
using namespace std;

class queue_using_stack
{
    stack<int>stack1;
    stack<int>stack2;

    public:
    void enqueue(int value)
    {
        stack1.push(value);
    }

    int dequeue()
    {
        int data;
        if(!stack2.empty())
        {
            data = stack2.top();
            stack2.pop();
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            if(stack2.empty())return -1;
            data = stack2.top();
            stack2.pop();
        }
        return data;
    }
};

int main()
{
    queue_using_stack q;
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(5);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}