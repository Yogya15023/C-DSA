#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
}*head;
void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    head=new node;
    head->data=a[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(struct node *h){
do
  {
      cout<<h->data<<endl;
      h=h->next;
  }while(h!=head);
  cout<<endl;
}
void ins(struct node *h,int x,int pos)
{
    struct node *q=new node;
    q->data=x;
    if(pos==0)
    {
        while(h->next!=head)
        {
            h=h->next;
        }
        h->next=q;
        q->next=head;
        head=q;
    }
    else{
   for(int i=0;i<pos-1;i++){
    h=h->next;
   }
    q->next=h->next;
    h->next=q;
    }
}
void del(struct node *h,int pos)
{struct node *q=NULL;
if(pos==0)
{ while(h->next!=head)
        {
            h=h->next;

        }
        h->next=head->next;
        head=h->next;
}
else{
    for(int i=0;i<pos-1;i++)
    {
      h=h->next;
    }
    q=h->next;
    h->next=q->next;
}
}
int main()
{ int a[]={1,2,3,4,5};
create(a,5);
ins(head,8,0);
display(head);
del(head,1);
display(head);
    return 0;
}
