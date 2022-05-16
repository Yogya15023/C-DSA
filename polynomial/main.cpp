#include <iostream>

using namespace std;
struct Term
{
   int coeff;
   int exp;
};
struct Poly{
    int n;
    Term *t;
};
void create(struct Poly *p){
    cout<<"number of terms:"<<endl;
    cin>>p->n;
    p->t=new Term[p->n];
    cout<<"enter terms"<<endl;
    int i;
    for(i=0;i<p->n;i++){
        cin>>p->t[i].coeff>>p->t[i].exp;
    }
}
void display(struct Poly p){
    int i;
for(i=0;i<p.n;i++){
    cout<<p.t[i].coeff<<"x"<<p.t[i].exp<<"+";
}
cout<<endl;

}
struct Poly *add(struct Poly *p1,struct Poly *p2)
{
    int i,j,k;
struct Poly *sum=new Poly;
sum->t=new Term[p1->n+p2->n];
i=j=k=0;
while(i<p1->n && j<p2->n){
    if(p1->t[i].exp>p2->t[j].exp){
        sum->t[k++]=p1->t[i++];
    }
    else if(p1->t[i].exp<p2->t[j].exp){
        sum->t[k++]=p2->t[j++];
    }
    else
    { sum->t[k].coeff=p1->t[i].coeff+p2->t[j++].coeff;
      sum->t[k++].exp=p1->t[i++].exp;
    }
}
for(;i<p1->n;i++)sum->t[k++]=p1->t[i];
for(;i<p1->n;i++)sum->t[k++]=p2->t[j];
sum->n=k;
return sum;
};
int main()
{
    struct Poly p1,p2,*p3;
    create(&p1);
    cout<<endl;
    display(p1);
    cout<<endl;
    create(&p2);
    cout<<endl;
    display(p2);
    cout<<endl;
     p3=add(&p1,&p2);
    display(*p3);

    return 0;
}
