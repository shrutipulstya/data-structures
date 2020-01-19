#include<iostream>
int front , rear , n = 6, arr[6];

using namespace std;

void enqueue(int x)
{
    int next = (rear + 1) % n ;
    if(next == front )
    {
        cout << " queue is full";
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = x; 
        else 
        {
            arr[next] = x;
            rear = next;
        }
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
        cout<< " element removed is "<<arr[front];
        front = -1 ;
        rear = -1 ;
    }
    else 
    {
        cout<< " element removed is "<<arr[front];
        front = (front + 1) % n;
    }
}

void display()
{
    for(int i = front; i < (rear+1)%n; i++)
    cout<<arr[i]<<endl;
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);                                                                                                                                      
    display();
    return 0;
}

