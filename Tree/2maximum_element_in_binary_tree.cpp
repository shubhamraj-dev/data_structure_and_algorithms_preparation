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

int findMax(node * root)
{
    if(root == NULL )return INT32_MIN;
    int current_max = root->data;
    return max(max(findMax(root->left),findMax(root->right)),current_max);
}

// iterative solution 
// use any one of iterative tree traversal and find the maximum element out of them
// most simple is inorder and preorder 
// solving using inorder 

int findMax_inorder(node * head)
{
    node * root = head;
    if(root == NULL)return INT32_MIN;
    stack<node *>st;
    int answer = INT16_MIN;
    while(root || !st.empty())
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        // instead of cout step make a comparison with the current maximum element
        // cout<<root->data<<" ";
        answer = max(answer,root->data);
        root = root->right;
    }
    return answer;
}

int main()
{
    node * root = newNode(10);
    root->left = newNode(4);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(6);

    cout<<findMax(root)<<endl;
    cout<<findMax_inorder(root)<<endl;
    return 0;
}