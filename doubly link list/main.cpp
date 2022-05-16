#include <iostream>

using namespace std;
struct node
{
    struct node *pre;
    int data;
    struct node *next;
}*first=NULL;
void create(int a[],int n)
{
    struct node *t,*last;
    int i;
    first=new node;
    first->data=a[0];
    first->pre=first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        t->pre=last;
        last=t;
    }
}
void display(struct node *p)
{
    while(p!=0)
    {
        cout<<p->data<<endl;

        p=p->next;
    }
    cout<<endl;
}
int len(struct node *p)
{
    int l=0;
    while(p!=0)
    {
        l++;
        p=p->next;
    }
    return l;
}
void ins(struct node *p,int x,int pos)
{
    struct node *t=new node;
    t->data=x;
    if(pos==0)
    {   p->pre=t;
        t->next=p;
        t->pre=NULL;
        first=t;


    }
    else{
            for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
    t->pre=p;
    p->next->pre=t;
    }
}
void del(struct node *p,int pos)
{
    if(pos==1)
    {
        first=p->next;
        first->pre=NULL;
        delete p;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;

        }
        p->pre->next=p->next;
        if(p->next)
            p->next->pre=p->pre;
        delete p;
    }
}
void rev(struct node *p)
{
    struct node *q=NULL;
    while(p!=NULL)
    {
        q=p->next;
        p->next=p->pre;
        p->pre=q;
        p=p->pre;
        if(p!=0 && p->next==NULL)
            first=p;
    }

}
void findm(struct node *p)
{
    struct node *q=first;
    while(q!=NULL)
    { q=q->next;
      if(q!=NULL)
        q=q->next;
      if(q!=NULL)
        p=p->next;
    }
    cout<<"The mid value is: "<<p->data<<endl;
}
int main()
{ int s[]={1,2,3,4,5,8,9};
create(s,7);
findm(first);
display(first);

    return 0;
}
