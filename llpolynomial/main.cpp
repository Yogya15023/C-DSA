#include <iostream>

using namespace std;
struct node
{
    int col;
    int data;
    struct node *next;
};
void create(int m)
{
   struct node *a=new node[m];
    for(int i=0;i<m;i++)
    {   struct node *p=new node;
        a[i]=p;
        cout<<"Enter the column no and data:"<<endl;
        cin>>p->col>>p->data;
        p->next;

    }

}
void display(struct node *p)
{struct node *p;
int n;
    for(int i=0;i<m;i++)
    {
      p=a[i];
      cout<<"print no of columns"<<endl;
      cin>>n;
      for(int j=0;j<n;j++)
      {
          if(j==p->col)
            cout<<p->data;
          else
            cout<<"0";
      }
      cout<<endl;
    }
}
int main()
{

    return 0;
}
