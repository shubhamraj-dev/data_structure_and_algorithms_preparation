//problem: implement a doubly ended queue with linked list

#include<iostream>


using namespace std;

struct node
{
    int data;
    node * prev;
    node * next;
};

class deque
{
    node * head;
    public:
    void push_back(int value)
    {
        node * temp = (node *)malloc(sizeof(node));
        temp->data = value;
        if(head == NULL)
        {
            head = temp;
            head->next = head;
            head->prev = head;
        }
        else
        {
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            // head = temp;
        }
        
    }

    void push_front(int value)
    {
        push_back(value);
        head = head->prev;
    }

    int pop_back()
    {
        int temp;
        if(head == NULL)return -1;
        if(head->prev == head)
        {
            temp = head->data;
            free(head);
            head = NULL;
        }
        else{
            node * ele = head->prev;
            temp = ele->data;
            ele->prev->next = head;
            head->prev = ele->prev;
            free(ele);
            return temp;
        }
    }

    int pop_front()
    {
        head = head->next;
        int temp = pop_back();
        return temp;

    }

};

int main()
{
    deque dq;
    dq.push_back(20);
    dq.push_front(10);dq.push_front(30);
    cout<<dq.pop_back()<<endl;cout<<dq.pop_front()<<endl;cout<<dq.pop_front()<<endl;
    return 0;
}