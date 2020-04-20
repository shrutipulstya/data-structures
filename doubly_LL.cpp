#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
    node* temp;
};

node* h = NULL;

void insert_head(int x)         //will insert at head
{
    if(h == NULL)
    {
        node* n = new node;
        n -> data = x;
        n -> next = NULL;
        n -> prev = NULL;
        h = n;
    }
    else
    {
        node* n = new node;
        n -> data = x;
        h -> prev = n;
        n -> next = h;
        n -> prev = NULL;
        h = n;
    }
}


void insert_mid(int x)
{
    int mid, count = 0;
    node* test = h;
    while(test != NULL) 
    {
        test = test -> next;
        count++;
    }
    mid = (count/2) - 1;
    node* temp = h;
    for(int i = 0; i < mid; i++)                
    {
        temp = temp->next;
    }
    node* n = new node;
    n -> data = x;
    n -> next = temp -> next;
    temp -> next = n;
    n -> next -> prev = n;
    n -> prev = temp; 
}

void insert_inbetween(int x)        //will insert from head
{
    int pos;
    cout << "enter the position where the node has to be inserted: ";
    cin>> pos;
    node* temp = h;
    for(int i = 0; i < pos - 2; i++)                
    {
        temp = temp->next;
    }
    node* n = new node;
    n -> data = x;
    n -> next = temp -> next;
    temp -> next = n;
    n -> next -> prev = n;
    n -> prev = temp;
}

void remove_inbetween(int pos) // will remove from head

{
    node* temp = h;
    for(int i = 1; i < pos - 1; i++)
    {
        temp = temp -> next;
    }
    node* to_be_deleted = temp -> next;
    temp -> next = to_be_deleted -> next;
    to_be_deleted -> next -> prev = temp;
    delete to_be_deleted;  
}


void firstlast_del(int pos)         //will delete from head
{
    if( h == 0)
    {
        cout << "list is empty";
    }
    node * test = h;
    for(int  i = 1; i < pos; i++)
    {
        test = test -> next;
    }
    if( test -> next == NULL)
    {
        test -> prev -> next = NULL;
    }
    else if( test -> prev == NULL)
    {
        h = test -> next;
        test -> next -> prev = NULL;
    }
}

void display()
{
    node* t = h;
    while( t != NULL ) 
    {
        cout<<t->data;
        t = t -> next;
        cout<<" ";
    }
}

int main()
{
    insert_head(1);
    insert_head(2);
    insert_head(3);
    insert_head(5);
    insert_inbetween(4);
    display();
    return 0;
}
