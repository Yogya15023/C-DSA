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
void display()
{
    struct queue *p;
    p=f;
    while(p!=0)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
}
int main()
{
   cout<<dequeue();
    display();
    return 0;
}
