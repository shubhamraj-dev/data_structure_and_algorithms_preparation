// problem: make a stack which return only the minimum element till now
// solution: using 2 stacks where we only push when a new minimum is encountered
// and pop when the minimum is removed

#include<iostream>
#include<stack>
using namespace std;
// this approach gives the space complexity of o(n)
class min_stack
{
    stack<int>elements;
    stack<int>min;
    
    public:
    void push(int value)
    {
        elements.push(value);
        if(min.empty())min.push(value);
        else
        {
            if(min.top()>value)min.push(value);
        }
        
    }
    void pop()
    {
        if(min.top() == elements.top())min.pop();
        elements.pop();
    }

    int getminimum()
    {
        return min.top();
    }
};

//Method for getting O(1) space complexity

class mystack
{
    stack<int>st;
    int minele;
    public:
    void push(int value)
    {
        if(st.empty())
        {
            minele = value;
            st.push(value);
        }
        else
        {
            if(value<minele)
            {
                st.push(2*value - minele);
                minele = value;
            }
            else
            {
                st.push(value);
            }
            
        }
        
    }

    void pop()
    {
        if(st.top()>minele)st.pop();
        else
        {
            minele = 2*minele - st.top();
            st.pop();
        }
        
    }

    int getminimum()
    {
        return minele;
    }

};

int main()
{
    int array[] = {4,5,6,11,2,3,12};
    min_stack st;
    st.push(4);
    cout<<st.getminimum()<<endl;
    st.push(5);
    st.push(11);
    st.push(2);
    cout<<st.getminimum()<<endl;
    st.pop();
    cout<<st.getminimum()<<endl;
    return 0;
}