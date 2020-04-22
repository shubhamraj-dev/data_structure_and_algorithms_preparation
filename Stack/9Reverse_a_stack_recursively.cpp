//problem: reverse a stack using only stack operation
//solution: use recursion
#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> * s,int element)
{
    int temp;
    if(s->empty())s->push(element);
    else
    {
        temp = s->top();
        s->pop();
        insert_at_bottom(s,element);
        s->push(temp);
    }
    
}

void reverse(stack<int> * s)
{
    if(s->empty())return;
    int element = s->top();
    s->pop();
    reverse(s);
    insert_at_bottom(s,element);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(8);
    st.push(9);
    reverse(&st);
    cout<<st.top()<<endl;
    return 0;
}