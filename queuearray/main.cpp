#include <iostream>

using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;

};
void create(struct queue *q,int x)
{
    q->size=x;
    q->front=q->rear=0;
    q->Q=new int[q->size];

}
void enqueue(struct queue *q,int x)
{
    if((q->rear==q->size - 1)
        cout<<"The queue is Full!"<<endl;
    else
    {
        q->rear=q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front)
        cout<<"The queue is empty!"<<endl;
    else
    {
        q->front++;
        x=q->Q[q->front];

    }
    return x;
}
void display(struct queue q)
{
 int i;
    for(i=q.front+1;i<=q.rear;i++)
    {
        cout<<q.Q[i];
    }
    cout<<endl;
}
int main()
{struct queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    cout<<"no. deleted was: "<<dequeue(&q)<<endl;
    enqueue(&q,50);
    enqueue(&q,60);
    display(q);
    return 0;
}
