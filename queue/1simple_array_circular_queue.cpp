// implementation of simple circular queue

#include<iostream>
#include<vector>
using namespace std;

class myqueue
{
    int * array;
    int front;
    int rear;
    int q_size;

    public:
    myqueue(int q_size)
    {
        array = (int *)malloc(sizeof(int)*q_size);
        front = -1;
        rear = -1;
        q_size = q_size;
    }

    int queuesize()
    {
        // this function will always return value between 0 and q_size-1 so it can
        // not be used for checking whether the queue is full or not.
        return (rear - front + 1 + q_size)%q_size;
    }
    void enqueue(int value)
    {
        if((rear+1)%q_size == front)
        {
            cout<<"queue is full"<<endl;
            return;
        }
        rear = (rear+1)%q_size;
        array[rear] = value;
        if(front == -1)front = rear;
    }
    // Important look at this function and understand it
    int dequeue()
    {
        
        if(queuesize() == 0)
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int data = array[front];
        if(front == rear)front = rear = -1;
        else front = (front + 1)%q_size;
        return data;
    }
};

int main()
{
    return 0;
}