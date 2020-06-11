#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* root = NULL;

node* makenewnode(int data)
{
    node* newnode = new node();
    newnode -> data = data;
    newnode -> right = newnode -> left = NULL;
    return newnode;
}

node* insert(node* root,int data)
{
    if(root == NULL)
    {
        root = makenewnode(data);
    }
    else if(data <= root -> data)
    {
        root -> left = insert(root -> left ,data);   
    }
    else
    {
        root -> right = insert(root -> right ,data);   
    }
    return root;
}

bool search(node* root, int num)
{
    if( root == NULL )
    {
        return false;
    }    
    else if( root -> data == num)
    {
        return true;
    }
    else if( num <= root ->data)
    {
        return search( root -> left, num);
    }
    else if( num >= root ->data)
    {
        return search( root -> right, num);
    }
}

// 3 types of traversal
void levelorder(node *root)
{
    if(root == NULL)
    return;
    queue <node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* current = q.front();
        cout << current -> data << " ";
        if( current -> left != NULL)
        q.push(current -> left);
        if( current -> right != NULL)
        q.push(current -> right);
        q.pop();
    }
       
}

void preorder(node *root)
{
    if(root == NULL)
    return;
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(node *root)
{
    if(root == NULL)
    return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder( root -> right);
}

void postorder(node *root)
{
    if(root == NULL)
    return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main()
{
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,12);
    root = insert(root,17);
    // int num;
    // cout <<"enter the number to be searched : ";
    // cin >> num;
    // if(search(root,num) == true) 
    // cout<<"found";
    // else cout << "not found";
    // levelorder(root);cout << endl;
    // preorder(root);cout << endl;
    // inorder(root);cout<< endl;
    // postorder(root);cout << endl;
}