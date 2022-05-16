#include <iostream>

using namespace std;
struct node {
 struct node *lchild;
 int data;
 struct node *rchild;
}*root=NULL;
struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;

};
void create(struct queue *q,int x)
{
    q->size=x;
    q->front=q->rear=0;
    q->Q=new node * [q->size];

}
int isempty(struct queue *q)
{
    return q->front==q->rear;
}
void enqueue(struct queue *q,node *x)
{
    if(q->rear==q->size-1)
        cout<<"The queue is Full!"<<endl;
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
node * dequeue(struct queue *q)
{
    node* x=NULL;
    if(q->rear==q->front)
        cout<<"The queue is empty!"<<endl;
    else
    {
        q->front++;
        x=q->Q[q->front];

    }
    return x;
}
void tcreate()
{
    struct node*p,*t;
    int x;
    struct queue q;
    create(&q,100);
    cout<<"enter root value:"<<endl;
    cin>>x;
    root=new node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isempty(&q))
    {
        p=dequeue(&q);
        cout<<"Enter left child of : "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);

        }
         cout<<"Enter right child of : "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void preorder(struct node *p)
{
    if(p)
    {
        cout<<p->data<<endl;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<endl;
        inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<endl;
    }
}
void levelorder(struct node *p){
    struct queue q;
    create(&q,100);
    p=root;
    enqueue(&q,p);
 cout<<root->data<<endl;
 while(!isempty(&q))
 {
 p=dequeue(&q);
     if(p->lchild){
 cout<<p->lchild->data<<endl;
 enqueue(&q,p->lchild);
     }
 if(p->rchild){
 cout<<p->rchild->data<<endl;
 enqueue(&q,p->rchild);
 }
  }
 }
int count(struct node *root)
{
    if(root)
    {
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
}
int countleaf(struct node *root)
{
    if(root)
    {if(root->lchild==NULL && root->rchild==NULL)
        return countleaf(root->lchild)+countleaf(root->rchild)+1;
     return countleaf(root->lchild)+countleaf(root->rchild);
    }
    return 0;
}
int countdegtwo(struct node *root)
{
    if(root)
    {if(root->lchild==NULL && root->rchild==NULL)
        return countdegtwo(root->lchild)+countdegtwo(root->rchild)+1;
     return countdegtwo(root->lchild)+countdegtwo(root->rchild);
    }
    return 0;
}
int height(struct node *root)
{
    int x=0,y=0;
    if(root==0)
    {
        return 0;
    }
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    return y+1;
}
int main()
{tcreate();
cout<<countleaf(root)<<endl;
cout<<height(root);
    return 0;
}
