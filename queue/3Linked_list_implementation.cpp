// implementing queue using linked list;

#include<iostream>
using namespace std;

struct node
{
    int data;
    node * next;
};

class myqueue
{
    node * front;
    node * rear;

    public:
    myqueue()
    {
        front = rear = NULL;
    }

    void enqueue(int value)
    {
        node * temp = (node * )malloc(sizeof(node));
        temp->data = value;
        temp->next = NULL;
        if(rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        
    }

    int dequeue()
    {
        int data =  -1;
        if(front == NULL)return -1;
        else if (front == rear)
        {
            data = front->data;
            free(front);
            front = rear = NULL;
        }
        else
        {
            node * temp = front;
            data = temp->data;
            front = front->next;
            free(temp);
        }
        return data;
    }
};

int main()
{

    return 0;
}