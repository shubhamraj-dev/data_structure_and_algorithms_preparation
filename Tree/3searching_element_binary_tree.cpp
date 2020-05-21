#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
};

node * newNode(int data)
{
    node * temp = (node * )malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

bool findElement(node * root,int value)
{
    if(root == NULL)return false;
    if(root->data == value)return true;
    else return findElement(root->left,value) || findElement(root->right,value);
}
// for iterative do any tree traversal i will do preorder here
bool findElement_iterative(node * head,int value)
{
    node *root = head;
    if(root == NULL)return false;
    stack<node *>st;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        while(root)
        {
            if(root->right)st.push(root->right);
            if(root->data == value)return true;
            root = root->left;
        }
    }
    return false;
}

int main()
{
    node * root = newNode(10);
    root->left = newNode(4);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    cout<<findElement(root,10)<<endl;
    cout<<findElement(root,11)<<endl;
    cout<<findElement_iterative(root,10)<<endl;
    cout<<findElement_iterative(root,11)<<endl;
    
    return 0;
}