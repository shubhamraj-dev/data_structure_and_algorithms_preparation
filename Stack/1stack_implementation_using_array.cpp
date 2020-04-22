#include<iostream>
using namespace std;

class mystack
{
    int top;
    int capacity;
    int *array;
    
    public:
    mystack(int size)
    {
        capacity = size;
        array = (int *)malloc(capacity*sizeof(int));
        top = -1;

    }

    int isEmpty()
    {
        return(top == -1);
    }

    int isFull()
    {
        return(top == capacity-1);
    }

    void push(int value)
    {
        if(!isFull())
        {
            top++;
            array[top] = value;
        }
        else
        {
            cout<<"stack full"<<endl;
        }
        
    }

    int pop()
    {
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return INT8_MIN;
        }
        else return array[top--];
    }
};

int main()
{
    return 0;
}