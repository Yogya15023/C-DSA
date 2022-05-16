#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *st)
{
    cout<<"Enter the Size:"<<endl;
    cin>>st->size;
    st->top=-1;
    st->s=new int [st->size];
}
void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        cout << st.s[i]<<endl;
    }
    cout<<endl;

}
void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
        cout<<"stack Overflow"<<endl;
    else{
    st->top++;
    st->s[st->top]=x;
}
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
        cout<<"Stack underflow"<<endl;
    else{
        x=st->s[st->top--];
    }
    return x;
}
int isfull(struct stack st)
{
    if(st.top==st.size-1)
        return 1;
    return 0;
}
int isempty(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
int peep(struct stack st,int pos)
{int i=-1;
if(st.top-pos+1<0)
    cout<<"invalid index";
i=st.s[st.top-pos+1];
return i;
}
int stacktop(struct stack st)
{
int x=st.s[st.top];
return x;
}
int main(){
struct stack st;
create(&st);
push(&st,20);
push(&st,30);
push(&st,40);
push(&st,50);
display(st);
cout<<stacktop(st);
   return 0;
}
