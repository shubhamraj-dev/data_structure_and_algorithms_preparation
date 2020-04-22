// problem: To implement m stacks in one array  
// solution: divide the array in m parts and then if there is a clash shift the left side or
// right side stacks to make space for inserting new element 
#include<iostream>
using namespace std;

class m_stack
{
    int * array;
    int * base;
    int * top;

    public:
    m_stack(int array_size,int stack_count)
    {
        array = (int *)malloc(sizeof(int)* array_size);
        base = (int * )malloc(sizeof(int)*stack_count+1);
        top = (int * )malloc(sizeof(int)*stack_count);
        for(int i = 0;i<stack_count;i++)
        {
            base[i] = array_size*(i)/stack_count;
            top[i] = 0;
        }
        base[stack_count] = array_size;
    }

    void push(int id_stack,int data)
    {
        if(base[id_stack] + top[id_stack] >= base[id_stack+1])
        {
            //shift right

            //shift left

            //pushing the value
            array[base[id_stack] + top[id_stack]] = data;
            top[id_stack]++;
        }
        else
        {
            array[base[id_stack]+top[id_stack]] = data;
            top[id_stack]++;
        }
    }

    int pop(int id_stack)
    {
       if(top[id_stack]==0)cout<<"this stack is empty"<<endl;
       return (array[base[id_stack]+top[id_stack]--]); 
    }

};

int main()
{
    return 0;
}