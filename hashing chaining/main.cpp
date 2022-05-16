#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL;
struct node *searching(struct node *p,int x)
{struct node *q=NULL;
    while(p!=0)
    {if(p->data==x)
    {
        cout<<"Key found:"<<p->data<<endl;
        q->next=p->next;
        p->next=first;
        first=p;

        break;
    }

    q=p;
    p=p->next;
    }
    if(p->data!=x)
        cout<<"Key not found!!";
}
void insertsorted(struct node **h,int x)
{
    struct node *t,*q=NULL,*p=*h;
    t=new node;
    t->data=x;
    t->next=NULL;
    if(*h==NULL)
        *h=t;
    else{
    while(p!=0 && p->data < x)
    {   q=p;
        p=p->next;
    }
    if(p==*h)
    {t->next=*h;
    *h=t;
    }
    else{
    t->next=q->next;
    q->next=t;
    }
}
}
int hashs(int key)
{
    return key%10;
}
void insertht(struct node *h[],int key)
{
    int index=hashs(key);
    insertsorted(&h[index],key);
}
int main()
{
     struct node *ht[10],*temp;
     for(int i=0;i<10;i++)
     {
         ht[i]=0;
     }
     insertht(ht,12);
     insertht(ht,22);
     insertht(ht,42);
     temp=searching(ht[hashs(22)],22);
     cout<<temp->data;
    return 0;
}
