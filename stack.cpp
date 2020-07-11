#include<iostream>
using namespace std;
#define n 10
int arr[n],top = -1;

void push(int x)
{
    cout<<"enter element to be pushed";
    cin>>x;
    if(top == n-1)
    {
        cout<<"stack overflow \n";
        return;
    }
    arr[++top] = x;
}

void pop()
{
    cout<<"last element is popped";
    if(top == -1)
    {
        cout<<"stack is empty";
        return;
    }
    top--;
}

void display()
{
    int i;
    for(int i = top; i>=0; i--)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int choice,x;
    while(true)
        {
            cout<<"enter choice: "<<endl<<"1) display stack: "<<endl<<"2) push in stack: "<<endl<<"3) pop in stack: "<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1 :display();
                    break;
            case 2 :push(x);
                    break;
            case 3 :pop();
                    break;
            default:cout<<"no option selected";
                    break;
            }
        }
}