#include<iostream>
#include<queue>
using namespace std;

#define n 5
int visited[n] = {0};
queue <int> q;
int graph[n][n] =   {   { 1, 1, 0, 0, 1},
                        { 0, 1, 1, 1, 0},
                        { 0, 0, 1, 0, 0},
                        { 0, 0, 0, 1, 0},
                        { 0, 0, 0, 0, 1}
                    };
void bfs(int start)
{
    visited[start] = 1;
    q.push(start);
    while(!q.empty())
    {
        start = q.front();
        cout << start;
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if (graph[start][i] == 1 && (!visited[i]))
            {
                q.push(i);
                visited[i] = 1;
            }
        }

    }
}

int main()
{
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        bfs(i);
    }
}
