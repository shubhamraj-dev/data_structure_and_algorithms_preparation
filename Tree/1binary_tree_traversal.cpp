#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
};

node * getnode(int data)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder_recursive(node * root)
{
    if(root){
        cout<<root->data<<" ";
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }
}

void preorder_iterative(node * head)
{
    node * root = head;
    if(root == NULL)return;
    stack<node *>st;
    st.push(root);
    while(root || !st.empty()){
        root = st.top();
        st.pop();
        while(root)
        {
            cout<<root->data<<" ";
            if(root->right)st.push(root->right);
            root=root->left;
        }
        
    }
}

// Inorder traversal

void inorder_recursive(node * root)
{
    if(root){
        inorder_recursive(root->left);
        cout<<root->data<<" ";
        inorder_recursive(root->right);
    }
}

void iterative_inorder(node * head)
{
    node * root = head;
    if(root == NULL)return;
    stack<node *>st;
    while(root || !st.empty())
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout<<root->data<< " ";
        root = root->right;

    }
}

// Postorder traversal

void postorder(node * root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void postorder_iterative(node * root)
{
    if(root == NULL)return;
    stack<node * >st;
    while(root || !st.empty())
    {
        while(root)
        {
            if(root->right)st.push(root->right);
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if(root->right && !st.empty() && st.top() == root->right){
            st.pop();
            st.push(root);
            root = root->right;
        }
        else
        {
            cout<<root->data<<" ";
            root = NULL;
        }
        
    }
}

// level order traversal

void levelorder(node * head)
{
    node * root = head;
    if(root == NULL)return;
    queue<node * > q;
    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        cout<<root->data<<" ";
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
    }

}



int main()
{
    node * tree = getnode(10);
    tree->left = getnode(4);
    tree->right = getnode(15);
    tree->left->left = getnode(2);
    tree->left->right = getnode(6);
    preorder_iterative(tree);
    cout<<endl;
    iterative_inorder(tree);
    cout<<endl;
    postorder_iterative(tree);
    cout<<endl;
    levelorder(tree);
    return 0;
}