#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL,*last=NULL;
void create(int a[],int n)
{int i;
struct node *t,*last;
first=new node;
first->data=a[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++){
    t=new node;
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
}

}
void create2(int a[],int n)
{int i;
struct node *t,*last;
second=new node;
second->data=a[0];
second->next=NULL;
last=second;
for(i=1;i<n;i++){
    t=new node;
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
}

}
void count(struct node *p){
    int c=0;
    while(p!=0)
    {
        p=p->next;
        c++;


    }
    cout<<"the no. of nodes are: "<<c<<endl;
}

void display(struct node *p)
{
    while(p!=0)
    {
        cout<<"the number is: "<<p->data<<endl;
        p=p->next;



    }
}
void displayr(struct node *p){
if(p!=0){
    displayr(p->next);
    cout<<"the number: "<<p->data<<endl;
}


}
void add(struct node *p){
int s=0;
while(p!=0)
    {
        s+=p->data;
        p=p->next;
    }
    cout<<"sum is: "<<s<<endl;
}
void max(struct node *p)
{
    int m=-32768;
    while(p!=0)
    {
        if(p->data>m)
        {
            m=p->data;
             p=p->next;
        }
    }
    cout<<"Max digit is: "<<m<<endl;
}
void searching(struct node *p,int x)
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
void insert(struct node *p,int pos,int x)
{struct node *t;
int i;
  t=new node;
    t->data=x;
if(pos==0){
    t->next=first;
    first=t;

}
else if(p>0){
    p=first;
    for(i=0;i<pos-1;i++){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
}

}
void insertlast(struct node *p,int x)
{
    struct node *t,*last;
    t=new node;
    t->data=x;
    t->next=NULL;
    if(first==NULL){
    first=last=t;
    }
    else
        last->next=t;
        last=t;
}
 void insertsorted(struct node *p,int x)
{
    struct node *t,*q=NULL;
    t=new node;
    t->data=x;
    while(p!=0 && p->data < x)
    {   q=p;
        p=p->next;
    }
    if(p==first)
    {t->next=first;
    first=t;
    }
    else{
    t->next=q->next;
    q->next=t;
    }
}
void del(struct node *p,int pos)
{
struct node *q=NULL;
q=new node;
int x =-1,i;
if(pos==1)
{
    x=first->data;
    p=first;
    first=first->next;
    delete p;
}
else
{
    for(i=0;i<pos-1 && p!=0;i++)
    {
        q=p;
        p=p->next;
    }
    if(p!=0)
    {
        q->next=p->next;
        x=p->data;
        delete p;
    }
}
}
void checksorting(struct node *p)
{
    int x=-32768;
    if(p->data<x)
    {
        cout<<"Not Sorted";
    }
    while(p!=0 && p->data>x)
    {   x=p->data;
        p=p->next;
    }
    cout<<"Sorted List!";
}
void delduplicates(struct node *p)
{
    struct node *q=p->next;
    while(q!=0){
        if(q->data!=p->data){
             p=q;
        q=q->next;
        }
        else
          {
           p->next=q->next;
           delete q;
           q=p->next;
          }
    }
}
void rev(struct node *p,struct node *s)
{
    struct node *q=NULL,*r=NULL;
    while(p!=0)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void concat(struct node *p)
{while(p->next!=0)
{
    p=p->next;
}
p->next=second;
second=NULL;
}
void mer(struct node *p)
{
    if(first->data<second->data)
    {
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else
    {
      third=last=second;
        second=second->next;
        last->next=NULL;
    }
    while(first!=NULL && second!=NULL)
    {
        if(first->data<second->data)
        {
          last->next=first;
          last=first;
          first=first->next;
          last->next=NULL;
        }
        else
        {
         last->next=second;
          last=second;
          second=second->next;
          last->next=NULL;
        }
    }
    if(first!=NULL)
        last->next=first;
    else
        last->next=second;
}
int check(struct node *f)
{
   struct node *q=NULL,*p=NULL;
   p=q=first;
   do
   {
       p=p->next;
       q=q->next;
       if(q!=NULL)
        q=q->next;
   }
   while(p!=NULL && q!=NULL && p!=q);
   if(p==q)
    return 1;
   else
    return 0;
}
int main()
{
    struct node *t1,*t2;
int a[]={1,2,3};
int b[]={4,5};
   create(a,3);
   create2(b,2);
  // t1=first->next->next->next;
   //t2=first->next->next->next->next->next;
   //t2->next=t1;
  //cout<<check(first);
  mer(third);
  display(third);


    return 0;
}
