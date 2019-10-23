using namespace std;
#define n 5
#include<iostream>
int arr[n],front = -1,rear=-1;

void enqueue() //push
{
    int x;
    cout<<" enter element to be enqueued: ";
    cin>>x;
    if(front == -1 && rear == -1)
    {
        front++;
        arr[++rear] = x;
    }
    else if(rear < n -1) 
    {
        arr[++rear] = x;  
    }
    else if(n-1 == rear)
    cout<<"queue is full!! no more elements can be added\n";
}

void dequeue() //pop
{
    if(front == -1 && rear == -1)
    {
        cout<<"queue is empty !! no element can be dequeued";
        return;
    }
    else 
    front++;
}

void display()
{
    if(front == -1 && rear == -1)
    {
        cout<<"queue is empty\n";
        return;
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}

int main()
{
    int choice,x;
    while(true)
        {
            cout<<"\nenter choice: "<<endl<<"1) display queue: "<<endl<<"2) enqueue: "<<endl<<"3) dequeue: "<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1 :display();
                    break;
            case 2 :enqueue();
                    break;
            case 3 :dequeue();
                    break;
            default:cout<<"no option selected";
                    break;
            }
        }
}