#include <iostream>

using namespace std;
struct queue
{
    int data;
    struct queue *next;
}*f=NULL,*r=NULL;
void enqueue(int x)
{struct queue *t=new queue;
    if(t==NULL)
        cout<<"No space Left"<<endl;
    else
    {
        t->data=x;
        t->next=NULL;
        if(f==NULL)
           r=f=t;
        else
        {
            r->next=t;
            r=t;
        }
    }
}
int dequeue()
{struct queue *p;
int x=-1;
    if(f==NULL)
        cout<<"The queue is empty"<<endl;
    else
    {
        p=f;
        x=f->data;
        f=f->next;
        delete p;
    }
    return x;
}
int isEmpty()
{
    return f==NULL;
}
void bfs(int g[][7],int start,int n)
{

    int i=start;
    int visited[7]={0};
    cout<<i<<endl;
    visited[i]=1;
    enqueue(i);
    while(!isEmpty())
    {
        i=dequeue();
        for(int j=1;j<n;j++)
        {
            if(g[i][j]==1 && visited[j]==0)
            {
                cout<<j<<endl;
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}
void dfs(int g[][7],int start,int n)
{

    static int visited[7]={0};
    if(visited[start]==0)
    {
        cout<<start<<endl;
        visited[start]=1;
        for(int j=1;j<n;j++)
        {
            if(g[start][j]==1 && visited[j]==0)
            {
                dfs(g,j,n);
            }
        }
    }
}
int main()
{
    int g[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0},};
     dfs(g,4,7);

    return 0;
}
