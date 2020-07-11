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

void insert_Tail(int x) 
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
void insert_head(int x) 
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


void remove(int position)       //dosent work for pos 1 . deletes 2nd pos instead
{
    node *temp = h;
    for(int i = 1; i < position - 1; i++) 
    {
        temp = temp->next;
    }
    node *freeme = temp->next;
    temp->next = temp->next->next; 
    delete freeme;   
}

// ANOTHER WAY OF DELETING
void del(int pos)                           // for insert at head deletes from last pos ,also head.
{                                           //for insert at tail deletes from first pos or head.
    node* temp1 = h;
    if( pos == 1 )
    {
        h = temp1 -> next;
        delete(temp1);
    }
    else
    {
        for(int i = 0; i< pos-2 ; i++)
        {
            temp1 = temp1 -> next;
        }
        node* temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete(temp2);

    }
}

void display() 
{
    node* t = h;
    while(t != NULL) 
    {
        cout<< t -> data << " ";
        t = t -> next;
    }
}

int main()
{
    insert_Tail(2);
    insert_Tail(4);
    insert_Tail(6);
    insert_Tail(8);
    display();cout<<endl;
    remove(1);
    display();
}    
