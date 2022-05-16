#include <iostream>

using namespace std;
struct stack
{
    char data;
    struct stack *next;
}*top=NULL;
void display()
{ struct stack *p;
p=top;
    while(p!=0)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
void push(char x)
{
    struct stack *t=new stack;
    t->data=x;
    t->next=top;
    top=t;
}
char pop()
{   struct stack *p;
p=top;
    char x=-1;
    x=p->data;
    top=top->next;
    delete p;
    return x;

}
void peek(int pos)
{
    int i;
    struct stack *p;
    p=top;
    for(i=0;p!=0 && i<pos-1;i++)
    {
        p=p->next;
    }
    cout<<"the number at the position "<<pos<<" is: "<<p->data<<endl;
}
int isbalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('|| exp[i]=='{'|| exp[i]=='[')
    {
        push(exp[i]);
    }   else if(exp[i]==')'|| exp[i]=='}'|| exp[i]==']')
    {    if(top==NULL)
            return 0;
         pop();
    }
    }
    if(top==NULL)
        return 1;
    return 0;
}
int pre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}
int isoperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}
char intopost(char *infix)
{int i=0,j=0;
char *postfix;
long len=strlen(infix);
postfix=new char[len+2];

while(infix[i]!='\0')
{
    if(isoperand(infix[i]))
    {
        postfix[j++]=infix[i++];
    }
    else {if(infix[i]>top->data)
        push(infix[i++]);
    else
        postfix[j++]=pop();
}
}
while(top!=NULL)
    postfix[j++]=pop();
postfix[j]='\0';
return postfix;

}
int main()
{
char *exp ="a+b*c";
push('#');
char *postfix=intopost(exp);
cout<<postfix;
    return 0;
}
