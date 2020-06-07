#include<iostream>
using namespace std;

#define n 5
int visited[n] = {0};
int graph[n][n] =   {   { 1, 1, 0, 0, 0},
                        { 0, 1, 0, 1, 1},
                        { 1, 0, 1, 0, 0},
                        { 0, 0, 0, 1, 0},
                        { 0, 0, 0, 0, 1}
                    };

int dodfs(int node)
{
    visited[node] = 1;
    cout<<node;
    for(int i = 0; i < n; i++)
    {
        if( visited[i] == 0 && graph[node][i] == 1) 
        {
            dodfs(i);
        }
    }
}

int main()
{   
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        dodfs(i);
    }
    
}
