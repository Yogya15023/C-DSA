#include <iostream>

using namespace std;
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
void insert(int key)
{struct node *t=root;
struct node *r,*s;
       if(root==NULL){
        s=new node;
        s->data=key;
        s->lchild=s->rchild=NULL;
        root=s;
        return;
       }
 while(t!=NULL)
 {r=t;
     if(key<t->data)
     {
         t=t->lchild;
     }
     else if(key>t->data)
     {
         t=t->rchild;
     }
     else
        return;
 }
  s=new node;
        s->data=key;
        s->lchild=s->rchild=NULL;
         if(key<r->data)
     {
         r->lchild=s;
     }
      if(key>r->data)
     {
         r->rchild=s;
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
int search(struct node *p,int key)
{
    struct node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
            return 1;
        else if(key>t->data)
            t=t->rchild;
        else
            t=t->lchild;
    }
    return 0;
}
int height(struct node *p)
{
    int x,y;
    if(p==NULL)return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y ? x+1:y+1;
}
struct node *inpre(struct node *p)
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
};
struct node *insuc(struct node *p)
{
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
};
struct node *del(struct node *p,int key)
{ struct node *q=NULL;
         if(p==NULL)
            return NULL;
         if(p->lchild==NULL && p->rchild==NULL)
         {if(p==root)
             root = NULL;
          delete p;
          return NULL;

         }
         if(key < p->data)
            p->lchild=del(p->lchild,key);
        else if(key>p->data)
            p->rchild=del(p->rchild,key);
        else
        {
            if(height(p->lchild)>height(p->rchild))
            {
                q=inpre(p->lchild);
                p->data=q->data;
                p->lchild=del(p->lchild,q->data);
            }
            else
            {
                 q=insuc(p->rchild);
                p->data=q->data;
                p->rchild=del(p->rchild,q->data);
            }
        }
  return p;
}
int main()
{insert(30);
insert(10);
insert(25);
insert(40);
insert(35);
insert(5);
del(root,30);
inorder(root);
    return 0;
}
