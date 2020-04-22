#include<iostream>
using namespace std;

struct node
{
    int value;
    node * next;
};

class mystack
{
    int capacity;
    node * root;
    
    public:
    mystack()
    {
        capacity = 0;
        root = NULL;
    }

    int isEmpty()
    {
        return(root == NULL);
    }

// There is no concept of full in linked list implementation
    // int isFull()
    // {
    //     return(top == capacity-1);
    // }

    void push(int value)
    {
        node * temp = (node *)malloc(sizeof(node));
        temp->value = value;
        temp->next = root;
        capacity++;
        root = temp;
    }

    int pop()
    {
        if(isEmpty())return INT8_MIN;
        node * temp = root;
        root = root->next;
        free(temp);
        return temp->value;
    }

    // I think destructor is required in this problem so 
    // that there is no memory leak in this program.
};
int main()
{
    return 0;
}