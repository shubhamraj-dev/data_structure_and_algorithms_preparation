
// implementation of Dynamic circular queue

#include<iostream>
using namespace std;

class myqueue
{
    int * array;
    int front;
    int rear;
    int q_size;

    public:
    myqueue()
    {
        q_size = 1;
        array = (int *)malloc(sizeof(int)*q_size);
        front = -1;
        rear = -1;
        
    }

    int queuesize()
    {
        // this function will always return value between 0 and q_size-1 so it can
        // not be used for checking whether the queue is full or not.
        return (rear - front + 1 + q_size)%q_size;
    }

    void resize_queue()
    {
        // doubling the size of the array;
        q_size = 2*q_size;
        array = (int *)realloc(array,q_size);

        // There is a circular representation here therefore if front is greater
        // than rear then rearrangement is performed to make a bigger circle

        if(front > rear)
        {
            int size = q_size/2;
            for(int i = 0;i<front;i++)
            {
                array[size + i]  = array[i];
            }
            rear = rear + size;
            
        }
    }

    void enqueue(int value)
    {
        if((rear+1)%q_size == front)resize_queue();
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