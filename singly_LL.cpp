#include <iostream>

using namespace std;

struct node
{
   int data;
   node* next;
};

node* h = NULL;
node* l = NULL;

// INSERTING AT THE END

void insert(int x) 
{
    if(h == NULL)
    {
        node* n = new node;
        n -> next = NULL;
        n -> data = x;
        h = n;
        l = n;   
    }
    else
    {
        node* n = new node;
        n -> next = NULL;
        n -> data = x;
        l -> next = n;
        l = n;   
    }
}

/*INSERTING AT THE BEGINNING*/
void insert_beg(int x) 
{
    if( h == NULL)
    {
        node* n = new node;
        n -> data = x;
        n -> next = NULL;
        l = n;
        h = l;
    }
    else 
    {
        node* n = new node;
        n -> data = x;
        n -> next = h; 
        h = n;
    }
}


void remove(int position) 
{
    node *temp = h;
    for(int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    node *freeme = temp->next;
    temp->next = temp->next->next; 
    delete freeme;   
}

/* ANOTHER WAY OF DELETING
void del(int n)
{
    node* temp1 = h;
    if( n == 1 )
    {
        h = temp1 -> next;
        delete(temp1);
    }
    else
    {
        for(int i = 0; i< n-2 ; i++)
        temp1 = temp1 -> next;
        node* temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete(temp2);

    }
}*/

void display() 
{
    node* t = h;
    while(t != NULL) 
    {
        cout<<t->data<<endl;
        t = t -> next;
    }
}

int main()
{
    insert_beg(2);
    insert_beg(4);
    insert_beg(6);
    insert_beg(8);
    display();
}    
