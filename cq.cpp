#include<iostream>
#define n 6
int front = -1, rear = -1,x;
int arr[n];

using namespace std;

void enqueue()
{
    int next = (rear + 1) % n;
    if(next == front )
    {
        cout << " queue is full";
        return;
    }
    cout<<"enter element to be enqueued";
    cin>>x;
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = x; 
    }
    else 
    {
        arr[next] = x;
        rear = next;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1 )
    {
        cout << " queue is empty ";
    }
    else if(front == 0 && rear == 0)
    {
        cout<< " element removed is "<<arr[front]<<endl;
        front = -1 ;
        rear = -1 ;
    }
    else 
    {
        cout<< " element removed is "<<arr[front]<<endl;
        front = (front + 1) % n;
    }
}

void display()
{
    int i = front;
    while(i != rear) {
        cout<<arr[i]<<endl;
        i = (i + 1) % n;
    }
    cout<<arr[i]<<endl;
}

int main()
{
    int choice;
    while(true)
    {
        cout<<"enter choice: \n1) display queue: \n2) enqueue: \n3) dequeue: \n";
        cin>>choice;
        switch (choice)
        {
        case 1: display();
            cout<<endl;
            break;
        case 2: enqueue();
            cout<<endl;
            break;
        case 3: dequeue();
            cout<<endl;
            break;
        default: cout<<"no option selected";
            break;
        }
    }
    return 0;
}

